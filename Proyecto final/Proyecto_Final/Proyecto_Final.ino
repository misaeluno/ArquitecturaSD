#include <require_cpp11.h>
#include <deprecated.h>
#include <SPI.h>
#include <stdlib.h>
#include <string.h>

typedef struct Horario Horario;
typedef struct Node Node;
typedef struct List List;

struct Horario {       //estructura de las IDs
  unsigned long incio;   
  unsigned long fin;    //01) 08:00->0930  |02) 09:30->09:40  |03) 09:40->11:10  |04) 11:10->11:20 |05) 11:20->12:50 |06) 12:50->14:00
  char evento;          //07) 14:00->15:30 |08) 15:30->15:40  |09) 15:40->17.10  |10) 17:10->17:20 |11) 17:20->18:50 |
};

struct List {
  int tamano;
  Node *cabeza;
  Node *cola
};

struct Node {     //Node que contiene los IDs de las tarjetas
  Horaio *horaio;
  Node *sigiente;
  Node *anteriaor;
};

List horarios[5] = { 0 };
char *nombre_Evento = { "Disponible", "Receso", "ALmuerzo", "Lenguaje1", "Lenguaje2" };
int Append(List *horario{inicio,fin,nombre_Evento});
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:

}
