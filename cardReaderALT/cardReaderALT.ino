#include <MFRC522.h>
#include <require_cpp11.h>
#include <MFRC522Extended.h>
#include <deprecated.h>

#include <SPI.h>
#include <stdlib.h>
#include <string.h>

#define RED 4
#define GRN 3
#define DLT 6
#define DPL 7
#define RST 9
#define SDA 10
#define MOSI 11
#define MISO 12
#define SCK 13

MFRC522 rfid(SDA, RST);

typedef struct Id Id;
typedef struct Node Node;
typedef struct List List;

struct Id {       //estructura de las IDs
  int data[4];
};

struct Node {     //Node que contiene los IDs de las tarjetas
  Id id;
  Node *prev;
  Node *next;
};

struct List {   //List contiene a los Node
  Node *tail;
  Node *head;
  int size;
};

//Inicializa funciones (prototipo)
//estas funciones se definen al final del codigo
Node *CreateNode(Id id);                            //Se crea la funcion "CreateNode" para poder crear un node
int ListAppend(List *list, Id id);                  //Se crea funcion "ListAppend" que agrega un node al final
Id ListPop(List *list, int index);                  //Se crea funcion "ListPop", que permite sacar un elemento
Id ListGet(List *list, int index);
void ListPrint(List *list);
int ListCompare(List *list, Id id);
int IdEquals(Id id1, Id id2);

// se agregaran los participan que pueden ingresar
Id cards[5] = { (Id) { { 23, 7, 85, 134 } }, (Id) { { 99, 166, 43, 40 } }, (Id) { { 243, 31, 18, 173 } }, (Id) { { 122, 238, 23, 2 } }, (Id) { { 7, 111, 31, 134 } } };
Id keychain[5] = { (Id) { { 138, 24, 222, 0 } }, (Id) { { 19, 146, 71, 20 } }, (Id) { { 100, 23, 206, 207 } }, (Id) { { 83, 188, 184, 44 } }, (Id) { { 38, 180, 126, 0 } } };
List regCards = { NULL, NULL, 0 };
List regKeychain = { NULL, NULL, 0 };
Id id = { 0 };
int pressDPL = 0;
int pressDLT = 0;
int mode = 1;
int pos;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(MISO, INPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(SDA, OUTPUT);
  pinMode(RST, INPUT);
  pinMode(DPL, INPUT_PULLUP);
  pinMode(DLT, INPUT_PULLUP);
  pinMode(GRN, OUTPUT);
  pinMode(RED, OUTPUT);
  Serial.println("Place your card near the reader...");
}

void loop() {

 if (digitalRead(DPL)) {
  if (pressDPL) {
   pressDPL = 0;
   ListPrint(&regCards);
   ListPrint(&regKeychain);
  }
 }
 else {
  pressDPL = 1;
 }
 if (digitalRead(DLT)) {
  if (pressDPL) {
   pressDLT = 0;
   mode = !mode;
   digitalWrite(GRN, HIGH);
   digitalWrite(RED, HIGH);
   delay(1000);
   digitalWrite(GRN, LOW);
   digitalWrite(RED, LOW);
  }
 }
 else pressDLT = 1;
 
 // Revisa si hay alguna nueva tarjeta presente
 if (!rfid.PICC_IsNewCardPresent()) {
   return;  // No card detected, return to loop
 }
 // Check if we can read the card's UID
 if (!rfid.PICC_ReadCardSerial()) {
  return;  // Failed to read card UID
 }
 // Display the UID
 if (mode) Serial.print("Card: ");
 else Serial.print("Keychain: ");
 for (byte i = 0; i < 4; i++) {
  id.data[i] = rfid.uid.uidByte[i];
  Serial.print(rfid.uid.uidByte[i], DEC);
  Serial.print(" ");
 }
 Serial.println();
 for (pos = 0; pos < 5; pos++) {
  if (IdEquals(cards[pos], id) && mode && !ListCompare(&regCards, id)) {
   ListAppend(&regCards, id);
   ListAppend(&regKeychain, keychain[pos]);
   digitalWrite(GRN, HIGH);
   break;
  }
  else if (ListCompare(&regKeychain, id) && !mode) {
   digitalWrite(GRN, HIGH);
  }
  else {
   digitalWrite(RED, HIGH);
  }  
 }
 // Halt PICC (to stop it from constantly reading the same card)
 rfid.PICC_HaltA();
 // Stop encryption on PCD
 rfid.PCD_StopCrypto1();

 delay(1000);
 digitalWrite(GRN, LOW);
 digitalWrite(RED, LOW);
}

Node* CreateNode(Id id) {
 Node *newNode = (Node*)malloc(sizeof(Node));
 if (!newNode) {
  return NULL;
 }
 newNode->id = id;
 newNode->prev = newNode->next = NULL;
 return newNode;
}

int ListAppend(List *list, Id id) {
 Node *newNode = CreateNode(id);
 if (!newNode) return 0;

 if (list->head) {
  list->head->next = newNode;
  newNode->prev = list->head;
  list->head = newNode;
 } else {
  list->tail = list->head = newNode;
 }
 list->size++;
 int i = 0;
 for (i = 0; i < 4; i++) {
  Serial.print(id.data[i], DEC);
  Serial.print(" ");
 }
 Serial.println();
 Serial.print("Size: ");
 Serial.print(list->size, DEC);
 Serial.println();
 return 1;
}

// Imprimo los datos de la lista de manera comprensible
void ListPrint(List *list) {
 if (list->size == 0) return;
 Node *current = list->tail;
 int i = 0;
 Serial.print("List:");
 Serial.println();
 while (current) {
  for (i = 0; i < 4; i++) {
   Serial.print(current->id.data[i], DEC);
   Serial.print(" ");
  }
  Serial.println();
  current = current->next;
 }
}

// Reviso si un determinado ID está ya registrado
int ListCompare(List *list, Id id) {
 if (list->size == 0) return 0;
 Node *current = list->tail;
 int i, j, correct;
 for (i = 0, correct = 0; i < list->size; i++, current = current->next) {
  if (IdEquals(current->id, id)) return 1;
 } 
 return 0;
}

// Obtiene el dato dado una posición
Id ListGet(List *list, int index) {
    if (index < 0) {
        return (Id) { 0, 0, 0, 0 };
    }

    Node *current = list->head;
    for (int i = 0; i < index && i < list->size; i++) {
        current = current->next;
    }
    return current->id;
}

int IdEquals(Id id1, Id id2) {
  int i, correct;
  for (i = 0, correct = 0; i < 4; i++) {
    //Serial.print(current->id.data[i], DEC);
    //Serial.print(" - ");
    //Serial.print(id.data[i], DEC);
    //Serial.println();
    if (id1.data[i] == id2.data[i]) {
      correct++;
    }
    else break;
    if (correct == 4) return 1;
  }
  return 0;
}
