#define VRX A4
#define VRY A5

int j, k, x, y;

void setup(){ 
  for (j = 2; j < 19; j++)
    pinMode(j, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  x = analogRead(VRX);
  y = analogRead(VRY);
  Serial.print("Eje x: ");
  Serial.println(x, DEC);
  Serial.print("Eje y: ");
  Serial.println(y, DEC);

  for (j = 2; j < 10; j++){
    digitalWrite(j, LOW);
    for (k = 10; k < 18; k++){
      digitalWrite(k, HIGH);
    }
  }

  //  HIGH  enciende  columna
  //  LOW   enciede   fila
  
///////////////////////////////////////////////////////////////

  if (x == 0){                      //si se preciona la izquierda entra
    //FLECHA IZQUIERZA
    for (j = 2; j < 10; j++){       //Acegura que el si ahay un
      digitalWrite(j, LOW);         //comando anterior este 
      for (k = 10; k < 18; k++){    //este apagado
        digitalWrite(k, HIGH);      //
      }
    }

    digitalWrite(15, LOW);          //Enciende fila numero 15
    digitalWrite(4, HIGH);          //En la columna 4
      
    for (j = 2; j < 10; j++){       //Apaga el Led anterior
      digitalWrite(j, LOW);         //de forma inmediata
      for (k = 10; k < 18; k++){    //
        digitalWrite(k, HIGH);      //
      }
    }

    digitalWrite(13, LOW);          //Enciende fila numero 13
    digitalWrite(4, HIGH);          //En la columnna 4
    //delay(2000);                  //este clico es estan rapido 
                                    //que no se nota que se apagan
    for (j = 2; j < 10; j++){       //los LEDs para cada punto
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
      
    digitalWrite(12, LOW);
    digitalWrite(5, HIGH);
      
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(16, LOW);
    digitalWrite(5, HIGH);
    
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(11, LOW);
    digitalWrite(6, HIGH);

    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(17, LOW);
    digitalWrite(6, HIGH);
      
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(15, LOW);
    digitalWrite(4, HIGH);

    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    for (j = 3; j < 10; j++){
      digitalWrite(j, HIGH);
      for(k = 11; k < 18; k++){
        if((k == 14) && (j == 3)){
          digitalWrite(k, LOW);
        }
      }

      digitalWrite(j, LOW);
    }

    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
  }

  else if(x > 10) {  //si se preciona la derecha entra
    //FLECHA DERECHA     
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(15, LOW);
    digitalWrite(8, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(13, LOW);
    digitalWrite(8, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(12, LOW);
    digitalWrite(7, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(16, LOW);
    digitalWrite(7, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(11, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(17, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    for (j = 3; j < 10; j++){
      digitalWrite(j, HIGH);
      for(k = 11; k < 18; k++){
        if((k == 14) && (j == 3)){
          digitalWrite(k, LOW);
        }
      }
      digitalWrite(j, LOW);
    }
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
  }

  else if(y == 0){  //si se preciona arriba entra
    //LINEA CONTINUA
    for (j = 3; j < 10; j++){
      digitalWrite(j, HIGH);
      for( k = 11; k < 18; k++){
        if((k == 14) && (j == 3)){
          digitalWrite(k, LOW);
        }
      }
      digitalWrite(j, LOW);
    }
  }

  else if(y > 520){  //si se preciona abajo entra
    //EXCLAMACION
    digitalWrite(17, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(15, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(14, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(13, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(13, LOW);
    digitalWrite(7, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(12, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(12, LOW);
    digitalWrite(7, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(12, LOW);
    digitalWrite(5, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(11, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(11, LOW);
    digitalWrite(7, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(11, LOW);
    digitalWrite(5, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(10, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(10, LOW);
    digitalWrite(7, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(10, LOW);
    digitalWrite(5, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
  }

  else {              //si no se hace nada entra
    digitalWrite(11, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(12, LOW);
    digitalWrite(5, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(12, LOW);
    digitalWrite(7, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(13, LOW);
    digitalWrite(4, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(13, LOW);
    digitalWrite(8, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(14, LOW);
    digitalWrite(3, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(14, LOW);
    digitalWrite(9, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(15, LOW);
    digitalWrite(4, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(15, LOW);
    digitalWrite(8, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(16, LOW);
    digitalWrite(5, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(16, LOW);
    digitalWrite(7, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(17, LOW);
    digitalWrite(6, HIGH);
    for (j = 2; j < 10; j++){
      digitalWrite(j, LOW);
      for (k = 10; k < 18; k++){
        digitalWrite(k, HIGH);
      }
    }
  }
  delay(10);
}
