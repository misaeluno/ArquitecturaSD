#include <LiquidCrystal_I2C.h>
#include <ezButton.h>  // the library to use for SW pin
#include <math.h>

#define CLK_PIN 2
#define DT_PIN 3
#define SW_PIN 4

#define DIRECTION_CW 0
#define DIRECTION_CCW 1
#define TIME 1

typedef struct Horario Horario;
typedef struct Node Node;
typedef struct List List;

struct Horario {
  unsigned long inicio;
  unsigned long fin;
  char evento;
};

struct List {
  int size;
  Node *head;
  Node *tail;
};

struct Node {     //Node que contiene los IDs de las tarjetas
  Horario data;
  Node *next;
  Node *prev;
};

void SetTime();
Node* CreateNode(Horario data);
int ListAppend(List *list, Horario data);
Horario ListNext(List *list, Horario actual);
void Clase(Horario data);

List horarios[7] = { 0 };
String nombreEvento[] = { "Disponible", "Receso", "Almuerzo", "Lenguaje 1", "Lenguaje 2", "Herramientas de Desarrollo", "Formacion Profesional III", "Base de Datos", "Estructura de Datos", "Introduccion a la Investigacion", "Dibujo de Ingenieria", "Formacion Profesional III" };
Horario actual = { 0UL, 0UL, 0 };
Horario siguiente = { 0UL, 0UL, 0 };
int dia = 0;
bool once = false;

unsigned long timer = 0;
unsigned long aux = 0;
char incrementAmount = 0;
char incrementMax = 0;
int direction = DIRECTION_CW;
int CLK_state;
int prev_CLK_state;
bool settingTime = false;
int setting = 0;
unsigned long step = 0;

ezButton button(SW_PIN);  // create ezButton object that attach to pin 4
LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() {
  
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  pinMode(CLK_PIN, INPUT);
  pinMode(DT_PIN, INPUT);
  button.setDebounceTime(50);  // 50 milisegundos de debouncing

  prev_CLK_state = digitalRead(CLK_PIN);
  // Lunes
  ListAppend(&horarios[0], (Horario) { 34200UL*TIME, 34800UL*TIME, 1 });
  ListAppend(&horarios[0], (Horario) { 40200UL*TIME, 40800UL*TIME, 1 });
  ListAppend(&horarios[0], (Horario) { 45600UL*TIME, 50400UL*TIME, 2 });
  ListAppend(&horarios[0], (Horario) { 55800UL*TIME, 56400UL*TIME, 1 });
  
  ListAppend(&horarios[0], (Horario) { 28800UL*TIME, 34200UL*TIME, 11 }); // Borrar este
  ListAppend(&horarios[0], (Horario) { 34800UL*TIME, 40200UL*TIME, 5 });
  ListAppend(&horarios[0], (Horario) { 40800UL*TIME, 45600UL*TIME, 5 });
  ListAppend(&horarios[0], (Horario) { 50400UL*TIME, 55800UL*TIME, 6 });
  // Martes
  ListAppend(&horarios[1], (Horario) { 34200UL*TIME, 34800UL*TIME, 1 });
  ListAppend(&horarios[1], (Horario) { 40200UL*TIME, 40800UL*TIME, 1 });
  ListAppend(&horarios[1], (Horario) { 45600UL*TIME, 50400UL*TIME, 2 });
  ListAppend(&horarios[1], (Horario) { 55800UL*TIME, 56400UL*TIME, 1 });
  
  ListAppend(&horarios[1], (Horario) { 34800UL*TIME, 40200UL*TIME, 8 });
  ListAppend(&horarios[1], (Horario) { 40800UL*TIME, 45600UL*TIME, 9 });
  ListAppend(&horarios[1], (Horario) { 56400UL*TIME, 61800UL*TIME, 8 });
  // Miércoles
  ListAppend(&horarios[2], (Horario) { 34200UL*TIME, 34800UL*TIME, 1 });
  ListAppend(&horarios[2], (Horario) { 40200UL*TIME, 40800UL*TIME, 1 });
  ListAppend(&horarios[2], (Horario) { 45600UL*TIME, 50400UL*TIME, 2 });
  ListAppend(&horarios[2], (Horario) { 55800UL*TIME, 56400UL*TIME, 1 });
  
  ListAppend(&horarios[2], (Horario) { 28800UL*TIME, 34200UL*TIME, 11 });
  ListAppend(&horarios[2], (Horario) { 50400UL*TIME, 55800UL*TIME, 10 });
  // Jueves
  ListAppend(&horarios[3], (Horario) { 34200UL*TIME, 34800UL*TIME, 1 });
  ListAppend(&horarios[3], (Horario) { 40200UL*TIME, 40800UL*TIME, 1 });
  ListAppend(&horarios[3], (Horario) { 45600UL*TIME, 50400UL*TIME, 2 });
  ListAppend(&horarios[3], (Horario) { 55800UL*TIME, 56400UL*TIME, 1 });
  
  ListAppend(&horarios[3], (Horario) { 34800UL*TIME, 40200UL*TIME, 8 });
  ListAppend(&horarios[3], (Horario) { 50400UL*TIME, 55800UL*TIME, 6 });
  // Viernes
  ListAppend(&horarios[4], (Horario) { 34200UL*TIME, 34800UL*TIME, 1 });
  ListAppend(&horarios[4], (Horario) { 40200UL*TIME, 40800UL*TIME, 1 });
  ListAppend(&horarios[4], (Horario) { 45600UL*TIME, 50400UL*TIME, 2 });
  ListAppend(&horarios[4], (Horario) { 55800UL*TIME, 56400UL*TIME, 1 });
  Serial.println("Init");

  Clase(actual);
  delay(5000);
}

void loop() { 
  button.loop();  // MUST call the loop() function first

  // Lee el estado actual del codificador a través del pin CLK
  CLK_state = digitalRead(CLK_PIN);

  // Si el estado de CLK cambia, entonces se causa un pulso
  // Reacciona sólo a la subida de potencial (de bajo a alto) para evitar conteo doble
  if (CLK_state != prev_CLK_state && CLK_state == HIGH) {
    if ((digitalRead(DT_PIN) == HIGH) && settingTime) {
      timer += step*TIME;
    }
  }

  // save last CLK state
  prev_CLK_state = CLK_state;

  // Para poner la hora con el codificador rotacional
  if (button.isPressed()) SetTime();
  
  siguiente = ListNext(&horarios[dia], actual);
  if ((actual.inicio != siguiente.inicio && actual.fin != siguiente.fin && actual.evento != siguiente.evento)) {
    Clase(siguiente);
  }
  actual = siguiente;
  
  if (!settingTime) {
    timer += (millis() - aux);
  }
  if (timer > 86400*TIME) {
    timer %= (86400*TIME);
    dia = (dia + 1)%7;
    actual = (Horario) { 0UL, 0UL, 0};
    siguiente = (Horario) { 0UL, 0UL, 0};
    Clase(actual);
  }
  if (!settingTime) aux = millis();

  Serial.print((dia == 0) ? "Lun" : (dia == 1) ? "Mar" : (dia == 2) ? "Mie" : (dia == 3) ? "Jue" : (dia == 4) ? "Vie" : (dia == 5) ? "Sab" : "Dom"); // Dia
  Serial.print(" - ");
  Serial.print((int) floor(timer/(36000UL*TIME))%3); // Obtengo la decena de la hora
  Serial.print((int) floor(timer/(3600UL*TIME))%10); // Obtengo la unidad de la hora
  Serial.print(":");
  Serial.print((int) floor(timer/(600UL*TIME))%6); // Obtengo la decena del minuto
  Serial.print((int) floor(timer/(60UL*TIME))%10); // Obtengo la unidad del minuto
  Serial.print(" | ");
  Serial.print(timer);
  Serial.print(" | ");
  Serial.print(timer > actual.fin ? nombreEvento[0] : nombreEvento[actual.evento]);
  Serial.print(" | ");
  Serial.print((int) floor(actual.inicio/(36000UL*TIME))%3); // Obtengo la decena de la hora
  Serial.print((int) floor(actual.inicio/(3600UL*TIME))%10); // Obtengo la unidad de la hora
  Serial.print(":");
  Serial.print((int) floor(actual.inicio/(600UL*TIME))%6); // Obtengo la decena del minuto
  Serial.print((int) floor(actual.inicio/(60UL*TIME))%10); // Obtengo la unidad del minuto
  Serial.print(" - ");
  Serial.print((int) floor(actual.fin/(36000UL*TIME))%3); // Obtengo la decena de la hora
  Serial.print((int) floor(actual.fin/(3600UL*TIME))%10); // Obtengo la unidad de la hora
  Serial.print(":");
  Serial.print((int) floor(actual.fin/(600UL*TIME))%6); // Obtengo la decena del minuto
  Serial.print((int) floor(actual.fin/(60UL*TIME))%10); // Obtengo la unidad del minuto
  Serial.println();
}

// Para establecer el tiempo
void SetTime() {
if (!settingTime) settingTime = true;
  else {
    switch (setting) {
      case 0:
        setting = 1;
        step = 60UL;
        break;
      case 1:
        setting = 2;
        step = 600UL;
        break;
      case 2:
        setting = 3;
        step = 3600UL;
        break;
      case 3:
        setting = 4;
        step = 36000UL;
        break;
      case 4:
        setting = 0;
        step = 0UL;
        settingTime = false;
        break;
    }
  }
}

// Function to create a new node
Node* CreateNode(Horario data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Function to append data to the end of the list
int ListAppend(List *list, Horario data) {
    Node *newNode = CreateNode(data);
    if (!newNode) return 0;

    if (list->head) {
        list->head->next = newNode;
        newNode->prev = list->head;
        list->head = newNode;
    } else {
        list->tail = list->head = newNode;
    }
    list->size++;
    return 1;
}

// 
Horario ListNext(List *list, Horario data) {
  if (list-> size == 0) return data;
  Node *current;
  int i;
  for (i = 0, current = list->tail; i< list->size; i++, current = current->next) {
    if (current->data.inicio < timer && data.fin <= current->data.inicio) return current->data;
  }
  return data;
}

void Clase(Horario data){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor (0,1);
  lcd.print("                ");
  String tiempo = (dia == 0) ? "Lun" : (dia == 1) ? "Mar" : (dia == 2) ? "Mie" : (dia == 3) ? "Jue" : (dia == 4) ? "Vie" : (dia == 5) ? "Sab" : "Dom";
  //if (!(timer > actual.fin   || timer < actual.inicio)) {
  if (data.inicio != data.fin) {
    tiempo += "|";
    tiempo += (int) floor(data.inicio/(36000UL*TIME))%3;
    tiempo += (int) floor(data.inicio/(3600UL*TIME))%10;
    tiempo += ":";
    tiempo += (int) floor(data.inicio/(600UL*TIME))%6;
    tiempo += (int) floor(data.inicio/(60UL*TIME))%10;
    tiempo += "-";
    tiempo += (int) floor(data.fin/(36000UL*TIME))%3;
    tiempo += (int) floor(data.fin/(3600UL*TIME))%10;
    tiempo += ":";
    tiempo += (int) floor(data.fin/(600UL*TIME))%6;
    tiempo += (int) floor(data.fin/(60UL*TIME))%10;
    tiempo += "|";
  }
  lcd.setCursor(0,0);
  lcd.print(tiempo);
  lcd.setCursor (0,1);
  //lcd.print(timer > actual.fin ? nombreEvento[0] : nombreEvento[actual.evento]);
  lcd.print(nombreEvento[data.evento]);
} 
