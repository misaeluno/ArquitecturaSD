#include <MFRC522.h>
#include <require_cpp11.h>
#include <MFRC522Extended.h>
#include <deprecated.h>
#include <SPI.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <iostream>

#define RST 9
#define SDA 10
#define MOSI 11
#define MISO 12
#define SCK 13

MFRC522 rfid(SDA, RST);

using namespace std;

//estructura del nodo
//estructura del nodo
struct nodo {
    nodo *anterior;		//esto apunta al bloque de atras (izquierda)    	si es el ultimo apunta a NUUL
	nodo *siguiente;	//esto apunta al bloque de adelante (derecha)		si es el primero apunta a NILL
	int tarjeta;		//la informacuion que va a tner el nodo
};


nodo *rc522=NULL;			//se crea la estructura para rc522

//para poder ingresar los datos
void insertar (int dato){
							//el nodo "nuevo" es un nodo auxilar que sirve para guardar o mover la informacion
	nodo *nuevo = new nodo;	//el nodo nuevo que quiere ungressar sera igual a un nodo vacio
	nuevo->tarjeta = dato;	//la informacion de tarjeta nuevo sera el dato que llega
	
	if(rc522==NULL){				//si rc522 esta vacio quiere decir que tadoabia no hay datos 
		rc522=nuevo;				//entonces rc522 sera igual al nodo nuevo 
		rc522->siguiente = NULL;	//el nodo rc522 apunta a NULL acia la derecha
		rc522->anterior = NULL;		//el nodo rc522 apunta a NULL acia la izquierda
	}
	
	else{					
		nodo *aux = rc522;					//se crea un nodo auciliar igual al nodo rc522
		while(aux->siguiente != NULL){		//mientras que el siguiente de auxiliar no apunta al nodo rc522 entra
			aux = aux->siguiente;			//auxiliar avanzara un bloque a la derecha
		}
		
		aux->siguiente = nuevo;				//el nodo axuiliar apunta nuevo a la derecha
		nuevo->anterior = aux;				//el nodo "nuevo" apunta a auxiliar a la izquierda
		nuevo->siguiente = NULL;			//y el nodo "nuevo" apunta a NULL a la derecha
	}
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(MISO, INPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(SDA, OUTPUT);
  pinMode(RST, INPUT);
  Serial.println("Place your card near the reader...");
}

void loop() {
  


  // Verificar si hay una nueva tarjeta presente
  if (!rfid.PICC_IsNewCardPresent()) {
    //Serial.println("tarjeta nueva");
    return;  // No se detecta ninguna tarjeta, volver al bucle
  }
  
  // Verificamos si podemos leer el UID de la tarjeta
  if (!rfid.PICC_ReadCardSerial()) {
    Serial.println("no se puede leer");
    return;  // Error al leer el UID de la tarjeta
  
  }
  // Display the UID
  Serial.print("Card UID: ");
    
  Serial.println("");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i]);  //imprime el ID de la tarjeta
    //tarjeta[i]=rfid.uid.uidByte[i];
  }

  Serial.println("");
  //Serial.println("el codigo de la tarjea es: ");
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(tarjeta[i]);
  }
  Serial.println("");
  for (byte i = 0; i < rfid.uid.size; i++) {
    if(tarjeta[i]==rfid.uid.uidByte[i]){    //Revisa si el codigo guardado es igual que la tarjeta
      Serial.println("hola DEATH");
    }
  }
  Serial.println();
  // Detener PICC (para evitar que lea constantemente la misma tarjeta)
  rfid.PICC_HaltA();
  // Detener el cifrado en PCD
  rfid.PCD_StopCrypto1();
}