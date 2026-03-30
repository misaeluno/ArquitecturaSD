//hola DEATH
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

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

void mostrar(){
	nodo *aux = rc522;						//se crea un nodo auxiliar igual al nodo "rc522"
	while(aux->siguiente != NULL){			//mientras el nodo auxliar no apunta a NULL a la derecha avandara a la derecha
		cout<<aux->tarjeta<<" -> ";			//mostrara el valor de tarjeta del nodo auxilar junto con el caracter ->
		aux =aux->siguiente; 				//abanzara al siguiente bloque a la derecha
	}
	cout<<aux->tarjeta<<endl;				//mostrala el valor auxiliar faltante de tajeta
}

int main (){
	
	int tarjeta;
	string tar;
	int info[4] = {7, 111, 31, 143};	
	int i;
	int j = 4;
	for( i=0 ; i<j; i++){
		stringstream ss; //buscar programa Cocatenar nummeros.cpp
    	ss <<tar<< info[i];
    	tar = ss.str();
		//printf("\n %i \n",info[j-i]);
	}
	
	//cout << tar;
	stringstream ss(tar);	//buscar Pasar de STRING a INg.cpp
    ss >> tarjeta;
	
	printf("\n");
	insertar (7);
	insertar (111);
	insertar (31 );
	insertar (143);
	insertar (tarjeta);
	mostrar();		
}
