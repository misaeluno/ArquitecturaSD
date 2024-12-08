#include <require_cpp11.h>
#include <deprecated.h>
#include <SPI.h>
#include <stdlib.h>
#include <string.h>

typedef struct Id Horario;
typedef struct Node Clases;

struct Id {       //estructura de las IDs
  int Dia[5];       //01) Lunes        |02) Martes        |03) Miercoles     |04) Jueves       |05) Viernes 
  int Bloque[11];   //01) 08:00->0930  |02) 09:30->09:40  |03) 09:40->11:10  |04) 11:10->11:20 |05) 11:20->12:50 |06) 12:50->14:00
};                  //07) 14:00->15:30 |08) 15:30->15:40  |09) 15:40->17.10  |10) 17:10->17:20 |11) 17:20->18:50 |

struct Node {     //Node que contiene los IDs de las tarjetas
  Id Horario;
  char Clase[99];
  Node *prev;
  Node *next;
};

//Inicializa funciones (prototipo)
//estas funciones se definen al final del codigo
Node *CreateNode(Id Horario);                       //Se crea la funcion "CreateNode" para poder crear un node
int ListAppend(List *list, Id Horario);             //Se crea funcion "ListAppend" que agrega un node al final
Id ListPop(List *list, int index);                  //Se crea funcion "ListPop", que permite sacar un elemento
Id ListGet(List *list, int index);


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
