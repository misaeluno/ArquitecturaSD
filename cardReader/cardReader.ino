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

struct Id {
  int data[4];
};

struct Node {
  Id id;
  Node *prev;
  Node *next;
};

struct List {
  Node *tail;
  Node *head;
  int size;
};

Node *CreateNode(Id id);
int ListAppend(List *list, Id id);
Id ListPop(List *list, int index);
int ListInsert(List *list, int index, Id id);
Id ListGet(List *list, int index);
void ListFree(List *list);
void ListPrint(List *list);
int ListCompare(List *list, Id id);

List cards = { NULL, NULL, 0 };
List keychain = { NULL, NULL, 0 };
Id id = { 0 };

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

  //Tarjets
  ListAppend(&cards, (Id) { { 23, 7, 85, 134 } });
  ListAppend(&cards, (Id) { { 63, 166, 43, 28 } });
  ListAppend(&cards, (Id) { { 64, 17, 206, 207 } });
  ListAppend(&cards, (Id) { { 53, 188, 184, 44 } });
  ListAppend(&cards, (Id) { { 7, 111, 31, 134 } });
  //Llaveros
  ListAppend(&cards, (Id) { { 38, 180, 126, 0 } });
  ListAppend(&cards, (Id) { { 19, 146, 71, 20 } });
  ListAppend(&cards, (Id) { { , 111, 31, 134 } });
  ListAppend(&cards, (Id) { { 7, 111, 31, 134 } });
  ListAppend(&cards, (Id) { { 138, 24, 222, 0 } });
}

void loop() {

 if (digitalRead(DPL)) {
  ListPrint(&cards);
  ListPrint(&keychain);
 }
 if (digitalRead(DLT)) {
  ListFree(&cards);
  ListFree(&keychain);
 }
 // Check if a new card is present
 if (!rfid.PICC_IsNewCardPresent()) {
   return;  // No card detected, return to loop
 }
 // Check if we can read the card's UID
 if (!rfid.PICC_ReadCardSerial()) {
  return;  // Failed to read card UID
 }
 // Display the UID
 for (byte i = 0; i < 4; i++) {
  id.data[i] = rfid.uid.uidByte[i];
 }
 
 if (!ListCompare(&cards, id)) {
  ListAppend(&cards, id);
 }
 // Halt PICC (to stop it from constantly reading the same card)
 rfid.PICC_HaltA();
 // Stop encryption on PCD
 rfid.PCD_StopCrypto1();

 
 digitalWrite(GRN, HIGH);
 digitalWrite(RED, HIGH);
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


void ListFree(List *list) {
 if (list->size == 0) return;
 Node *current = list->tail;
 Node *next = NULL;
 while (current) {
  next = current->next;
  free(current);
  current = next;
 }
 current = next = NULL;
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
 int i = 0;
 int correct = 0;
 while (current) {
  for (i = 0; i < 4; i++) {
    //Serial.print(current->id.data[i], DEC);
    //Serial.print(" - ");
    //Serial.print(id.data[i], DEC);
    //Serial.println();
    if (current->id.data[i] == id.data[i]) {
      correct++;
    }
    else break;
    if (correct == 4) return 1;
  }
  current = current->next;
 } 
 return 0;
}
