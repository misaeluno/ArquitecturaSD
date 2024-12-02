const int pinx = A4;
const int piny = A5;

int angulox = 0;
int anguloy = 0;

int j;
int k;

int ama1;//derecha
int ama2;//arriba
int roj1;//izquierda
int roj2;//abajo
void setup(){ 
  
  for ( j=2; j<19; j++)
    pinMode(j, OUTPUT);
  Serial.begin(9600);
}

void loop(){

  int x = analogRead(pinx); 
  int y = analogRead(piny);

  for ( j=2; j<10; j++){
    digitalWrite(j, LOW);
    for ( k=10; k<18; k++){
      digitalWrite(k, HIGH);
    }
  }
//  HIGH  enciende  columna
//  LOW   enciede   fila
  
            //funcion que cambia parametros
            //transfomra la variable X, limite inferior de X, limite superiro de X,
            //a nuevo limite inferior de anguloX y nuevo limite superior de AnguloX            
  angulox = map(x, 0 ,1023, 0, 180);
  anguloy = map(y, 0 ,1023, 0, 180);
  Serial.println("valor de X: ");
  Serial.println(x);
  Serial.println("valor de Y: ");
  Serial.println(y);
  delay(2000);

///////////////////////////////////////////////////////////////
  if( angulox < 0){     //si se preciona la izquierda entra
    //FLECHA IZQUIERZA
    for ( j=2; j<10; j++){          //Acegura que el si ahay un
      digitalWrite(j, LOW);         //comando anterior este 
      for ( k=10; k<18; k++){       //este apagado
        digitalWrite(k, HIGH);      //
      }
    }

    digitalWrite(15, LOW);          //Enciende fila numero 15
    digitalWrite(4, HIGH);          //En la columna 4
      
    for ( j=2; j<10; j++){          //Apaga el Led anterior
      digitalWrite(j, LOW);         //de forma inmediata
      for ( k=10; k<18; k++){       //
        digitalWrite(k, HIGH);      //
      }
    }

    digitalWrite(13, LOW);          //Enciende fila numero 13
    digitalWrite(4, HIGH);          //En la columnna 4
    //delay(2000);                  //este clico es estan rapido 
                                    //que no se nota que se apagan
    for ( j=2; j<10; j++){          //los LEDs para cada punto
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
    digitalWrite(16, LOW);
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
    digitalWrite(17, LOW);
    digitalWrite(6, HIGH);
      
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
    if(x>514){
      ama1=x;
    }
    else if (x<412){
      roj1=x;
    }
    else if(412<=x & x<=514){
      ama1=0;
      roj1=0;
    }
  }

  else if(angulox > 100){  //si se preciona la derecha entra
    //FLECHA DERECHA     
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
    if(x>514){
      ama1=x;
    }
    else if (x<510){
      roj1=x;
    }
    else if(510<=x & x<=514){
      ama1=0;
      roj1=0;
    }
  }

  else if(anguloy < 70){  //si se preciona arriba entra
    //LINEA CONTINUA
    for ( j=3; j<10; j++){
      digitalWrite(j, HIGH);
      for( k=11; k<18; k++){
        if(k==14 & j==3){
          digitalWrite(k, LOW);
        }
      }
      digitalWrite(j, LOW);
    }
  }
      
  else if(anguloy > 110){  //si se preciona abajo entra
    //EXCLAMACION
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
  }

  else {              //si no se hace nada entra

    digitalWrite(11, LOW);
    digitalWrite(6, HIGH);
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

    digitalWrite(12, LOW);
    digitalWrite(7, HIGH);
    for ( j=2; j<10; j++){
      digitalWrite(j, LOW);
      for ( k=10; k<18; k++){
        digitalWrite(k, HIGH);
      }
    }

    digitalWrite(13, LOW);
    digitalWrite(4, HIGH);
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
  }
}