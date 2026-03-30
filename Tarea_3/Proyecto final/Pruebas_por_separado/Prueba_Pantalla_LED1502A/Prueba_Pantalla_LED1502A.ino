#include <LiquidCrystal_I2C.h> //DESCARGAR LIBRERÍA:
                                                //  https://github.com/ELECTROALL/Codigos-arduino/blob/master/LiquidCrystal_I2C.zip

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
                          //12
  String nombreEvento[] = { "Disponible", "Receso", "Almuerzo", "Lenguaje 1", "Lenguaje 2", "Herramientas de Desarrollo", "Formacion Profesional III", "Base de Datos", "Estructura de Datos", "Introduccion a la Investigacion", "Dibujo de Ingenieria", "Formacion Profesional III" };
}

void loop() { 
  int cont=0;
  int i=0;
  int j=0;
  int k;
  int hor=8;
  int min=0;
  int seg=0;
  Serial.println("hola");
  for(hor ; hor<=23 ; hor++){
    for(min ; min<=60 ; min++){
      for(seg ; seg<=60 ; seg++){
        Serial.print(hor);
        Serial.print(min);
        Serial.print(seg);
        Serial.println(" - ");
      }
      seg=0;
      //Serial.println(" - ");
      if(hor>=(8+i) && min>=(0+j) && cont==0){
        Serial.println("HAHAHAHAHA");
        cont++;
        i++;
        j=j+40;
        if(j>60){
          k=j-60;
          i++;
          j=k;
        }
        Serial.println(i);
        Serial.println(j);
        delay(3000);
      }
    }
    cont=0;
    min=0;
    Serial.println(" cambio de hora");
    delay(1000);
  }
  hor=8;
}
