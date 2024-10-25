/*
#define VRX A4
#define VRY A5
*/
int cont;
int j;
int k;

void setup(){ 
  for ( j=2; j<19; j++)
    pinMode(j, OUTPUT);
/*
  pinMode(ama1, OUTPUT);
  pinMode(ama2, OUTPUT);
  pinMode(roj1, OUTPUT);
  pinMode(roj2, OUTPUT);
  Serial.begin(9600);
*/
}

void loop(){
  for ( j=2; j<10; j++){
    digitalWrite(j, LOW);
    for ( k=10; k<18; k++){
      digitalWrite(k, HIGH);
    }
  }
//  HIGH  enciende  columna
//  LOW   enciede   fila
///////////////////////////////////////////////////////////////
          //Flecha izquierda  
  if(analogWrite())
    while(cont<1000){  
      for ( j=2; j<10; j++){
        digitalWrite(j, LOW);
        for ( k=10; k<18; k++){
          digitalWrite(k, HIGH);
        }
      }
      digitalWrite(15, LOW);
      digitalWrite(4, HIGH);
      //delay(2000);
      for ( j=2; j<10; j++){
        digitalWrite(j, LOW);
        for ( k=10; k<18; k++){
          digitalWrite(k, HIGH);
        }
      }
      digitalWrite(13, LOW);
      digitalWrite(4, HIGH);
      //delay(2000);
      for ( j=2; j<10; j++){
        digitalWrite(j, LOW);
        for ( k=10; k<18; k++){
          digitalWrite(k, HIGH);
        }
      }
      digitalWrite(12, LOW);
      digitalWrite(5, HIGH);
      //delay(2000);
      for ( j=2; j<10; j++){
        digitalWrite(j, LOW);
        for ( k=10; k<18; k++){
          digitalWrite(k, HIGH);
        }
      }
      digitalWrite(16, LOW);
      digitalWrite(5, HIGH);
      //delay(2000);
      for ( j=2; j<10; j++){
        digitalWrite(j, LOW);
        for ( k=10; k<18; k++){
          digitalWrite(k, HIGH);
        }
      }
      digitalWrite(11, LOW);
      digitalWrite(6, HIGH);
      //delay(2000);
      for ( j=2; j<10; j++){
        digitalWrite(j, LOW);
        for ( k=10; k<18; k++){
          digitalWrite(k, HIGH);
        }
      }
      digitalWrite(17, LOW);
      digitalWrite(6, HIGH);
      //delay(2000);
      for ( j=2; j<10; j++){
        digitalWrite(j, LOW);
        for ( k=10; k<18; k++){
          digitalWrite(k, HIGH);
        }
      }
      digitalWrite(15, LOW);
      digitalWrite(4, HIGH);
      //delay(2000);
      for ( j=2; j<10; j++){
        digitalWrite(j, LOW);
        for ( k=10; k<18; k++){
          digitalWrite(k, HIGH);
        }
      }
      for ( j=3; j<10; j++){
        digitalWrite(j, HIGH);
        for( k=11; k<18; k++){
          if(k==14 & j==3){
            digitalWrite(k, LOW);
          }
        }
        //delay(2000);
        digitalWrite(j, LOW);
      }
      //delay(2000);
      for ( j=2; j<10; j++){
        digitalWrite(j, LOW);
        for ( k=10; k<18; k++){
          digitalWrite(k, HIGH);
        }
      }
      //delay(2000);
      cont++;
    }
    cont=0;
            //Flecha derecha
  while(cont<1000){  
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(15, LOW);
    digitalWrite(8, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(13, LOW);
    digitalWrite(8, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(12, LOW);
    digitalWrite(7, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(16, LOW);
    digitalWrite(7, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(11, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(17, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    for ( j=3; j<10; j++){
      digitalWrite(j, HIGH);
      for( k=11; k<18; k++){
        if(k==14 & j==3){
          digitalWrite(k, LOW);
        }
      }
      digitalWrite(j, LOW);
    }
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    cont++;
  }
  cont=0;
            //Linea continua
  while(cont<10000){
    for ( j=3; j<10; j++){
      digitalWrite(j, HIGH);
      for( k=11; k<18; k++){
        if(k==14 & j==3){
          digitalWrite(k, LOW);
        }
      }
      digitalWrite(j, LOW);
    }
    cont++;
  }
  cont=0;
            //exclamacion
  while(cont<1000){
    digitalWrite(17, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(15, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(14, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(13, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(13, LOW);
    digitalWrite(7, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(13, LOW);
    digitalWrite(5, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(12, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(12, LOW);
    digitalWrite(7, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(12, LOW);
    digitalWrite(5, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(11, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(11, LOW);
    digitalWrite(7, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(11, LOW);
    digitalWrite(5, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(10, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(10, LOW);
    digitalWrite(7, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    digitalWrite(10, LOW);
    digitalWrite(5, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    cont++;
  }
  cont=0;
            //Circulo
  while(cont<1000){

    digitalWrite(10, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(11, LOW);
    digitalWrite(5, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(11, LOW);
    digitalWrite(7, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(12, LOW);
    digitalWrite(4, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(12, LOW);
    digitalWrite(8, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(13, LOW);
    digitalWrite(3, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(13, LOW);
    digitalWrite(8, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(14, LOW);
    digitalWrite(3, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(14, LOW);
    digitalWrite(9, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(15, LOW);
    digitalWrite(4, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(15, LOW);
    digitalWrite(8, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(16, LOW);
    digitalWrite(5, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(16, LOW);
    digitalWrite(7, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(17, LOW);
    digitalWrite(6, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }
    cont++;
  }
  cont=0;
}