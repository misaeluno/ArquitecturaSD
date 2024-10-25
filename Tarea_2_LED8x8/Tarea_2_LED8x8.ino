#define VRX A4
#define VRY A5
int cont;
int j;
int k;
int x = 0;
int y = 0;

int ama1;//derecha
int ama2;//arriba
int roj1;//izquierda
int roj2;//abajo
float calc;// calcula la direccion del analogo

void setup(){ 
  for ( j=2; j<19; j++)
    pinMode(j, OUTPUT);
  Serial.begin(9600);
}

void loop(){

  x = analogRead(VRX); 
  y = analogRead(VRY);

  for ( j=2; j<10; j++){
    digitalWrite(j, LOW);
    for ( k=10; k<18; k++){
      digitalWrite(k, HIGH);
    }
  }
//  HIGH  enciende  columna
//  LOW   enciede   fila
//  ama1  derecha
//  roj1  izquirda
//  ama2  arriba
//  roj2  abajo
  
  calc = ((float) (x-521)) / 8;
  calc = calc > 0 ? calc : 0;
  ama1 = calc;  //derecha

  calc = ((float) (x - 512)) / 8;
  calc = -calc > 0 ? 256 - calc : 0;
  roj1= calc;   //izquierda

  calc = ((float) (y - 512)) / 8;
  calc = calc > 0 ? calc : 0;
  ama2 = calc;  //arriba

  calc = ((float) (y - 512)) / 8;
  calc = -calc > 0 ? 256 - calc : 0;
  roj2 = calc;  //abajo

///////////////////////////////////////////////////////////////
          //Flecha izquierda  
  if( roj1 > 0 ){     //si se preciona la izquierda entra
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
  }
    cont=0;
            //Flecha derecha
  else if(ama1 > 0){  //si se preciona la derecha entra
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
  }
  cont=0;
            //Linea continua
  else if(ama2 > 0){  //si se preciona arriba entra
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
  }
  cont=0;
            //exclamacion
  else if(roj2 > 0){  //si se preciona abajo entra
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
  }
  cont=0;
            //Circulo
  else {              //si no se hace nada entra
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
  }
  cont=0;
}