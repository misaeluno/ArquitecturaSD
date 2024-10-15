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
  
  while(cont<=5){ //se repetira simmepre ya que cont nunca llega a 5

    if( cont==0){                 //si cont es 0 da una señal de inicio 
      cont=1;                     
      digitalWrite(roj, HIGH);    //se enciende todas las lucen 
      digitalWrite(ama, HIGH);
      digitalWrite(ver, HIGH);
      delay(750);
      digitalWrite(roj, LOW);     //se apagan todas excepto la amarilla
      digitalWrite(ver, LOW);     //la luz amarilla indica que se puede precionar el boton
      delay(2000);
    }

    else if( digitalRead(bA) && cont==1 ){     //si se preciona el boton rojo y el cont es igual a 1 entra
      cont=2;                             // el contador se aumenta en 1
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(ver, HIGH);            // enciende el led verde
      delay(250);                         // dura 1/4 de segundo
      digitalWrite(ver, LOW);             // se apaga el led verde
    }

    else if( digitalRead(bA) && cont==2 ){     //si se preciona el boton rojo y el cont es igual a 2 entra
      cont=3;                             // el contador se aumenta en 1
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(ver, HIGH);            // enciende el led verde
      delay(250);                         // dura 1/4 de segundo
      digitalWrite(ver, LOW);             // se apaga el led verde
    }

    else if( digitalRead(bB) && cont==3 ){     //si se preciona el boton rojo y el cont es igual a 3 entra
      cont++;                             // el contador se aumenta en 1
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(ver, HIGH);            // enciende el led verde
      delay(250);                         // dura 1/4 de segundo
      digitalWrite(ver, LOW);             // se apaga el led verde
    }
    
    else if( digitalRead(bA) && cont==4){      // si se preciona el boton verde y el cont es igual a 4 entra
      cont=0;                             // el contador se vuelve 0 para dar inicio a la caja fuerte de nuevo
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(ver, HIGH);
      delay(15000);                       //dura 15 segundos 
      digitalWrite(ver, LOW);
    }

    else if( digitalRead(bA) && cont==3){  // si se preciona el boton rojo y el cont es mayor a 2 entra
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(roj, HIGH);            // se enciende el led rojo
      delay(250);                         // dura un 1/4 de segundo
      digitalWrite(roj, LOW);             // se apaga el led rojo
      cont=0;                             // el contador es igual a 0
    }

    else if( digitalRead(bB) && cont!=3){ // si se preciona el boton verde y el cont es distinto a 3 entra
      digitalWrite(ama, LOW);
      delay(100);                         // dura 1/10 de segundo
      digitalWrite(roj, HIGH);
      delay(250);
      digitalWrite(roj, LOW);
      cont=0;                             // el contador se vuleve 0
    }

    digitalWrite(ama, HIGH);
  
  }
}