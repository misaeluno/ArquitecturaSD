int roj = 4;
int ama = 3;
int ver = 2;
int bA = 9;
int bB = 8;
int cont;

void setup() {
  pinMode(roj, OUTPUT);      //Rojo
  pinMode(ama, OUTPUT);      //Verde
  pinMode(ver, OUTPUT);      //Azul
  pinMode(bB, INPUT_PULLUP);  //boton rojo   Boton B
  pinMode(bA, INPUT_PULLUP);  //boton verde  Boton A
}

void loop() {
  
  cont=0; //contador par saber si la clave esta bien empieza en 1
  //clave A,A,B,A
  
  while(cont<=5){ //se repetira hasta tener la contraseña correcta

    if( cont==0){
      cont=1;
      digitalWrite(roj, HIGH);
      digitalWrite(ama, HIGH);
      digitalWrite(ver, HIGH);
      delay(750);
      digitalWrite(roj, LOW);
      digitalWrite(ver, LOW);
    }

    if( digitalRead(bA) && cont<=2 ){     //si se preciona el boton rojo y el cont es igual a 1 entra
      cont++;                             // el contador se vuelve 2
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(ver, HIGH);           // enciende el led verde
      delay(250);                         // dura 1/4 de segundo
      digitalWrite(ver, LOW);            // se apaga el led verde
    }

    if( digitalRead(bB) && cont==3 ){     //si se preciona el boton rojo y el cont es igual a 2 entra
      cont++;                             // el contador se vuelve 3
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(ver, HIGH);           // enciende el led verde
      delay(250);                         // dura 1/4 de segundo
      digitalWrite(ver, LOW);            // se apaga el led verde
    }
    
    if( digitalRead(bA) && cont==4){ // si se preciona el boton verde y el cont es igual a 3 entra
      cont=0;                             // el contador se vuelve 4
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(ver, HIGH);
      delay(15000);
      digitalWrite(ver, LOW);
    }

    if( digitalRead(bA) && cont==3){  // si se preciona el boton rojo y el cont es mayor a 2 entra
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(ver, HIGH);           // se enciende el led rojo
      delay(250);                         // dura un 1/4 de segundo
      digitalWrite(ver, LOW);            // se apaga el led rojo
      cont=0;                             // el contador es igual a 0
    }

    if( digitalRead(bB) && cont!=3){ // si se preciona el boton verde y el cont es distinto a 3 entra
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(ver, HIGH);
      delay(250);
      digitalWrite(ver, LOW);
      cont=0;                             // el contador se vuleve 0
    }

    digitalWrite(ama, HIGH);
  
  }
}