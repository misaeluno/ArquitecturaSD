#include <LiquidCrystal_I2C.h> //DESCARGAR LIBRERÍA:
                                                //  https://github.com/ELECTROALL/Codigos-arduino/blob/master/LiquidCrystal_I2C.zip

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  //lcd.setCursor(0,0);
  //lcd.print("08:00 A 09:30"); 
  //lcd.setCursor (0,1);
  //lcd.print("Juego de rol DYD");
}

void Clase(String dato);
void Bloques(String dato, int hora);
void Materias(String dato, int hora);

void Clase(String dato){
  lcd.setCursor(0,0);
  lcd.print(dato);
  lcd.setCursor (0,1);
  lcd.print("Juego de rol DYD");
  delay(5000);
  //lcd.noBacklight(); // Apaga la retroiluminación después de mostrar el mensaje
  //delay(2000); // Mantiene la pantalla apagada durante 2 segundos
  //lcd.backlight(); // Vuelve a encender la retroiluminación
}

void Bloques(String dato,int hora){
  if(hora==0){
    lcd.setCursor(0,0);
    lcd.print(dato);
    delay(5000);
  }
  else if(hora==1){
    lcd.setCursor(0,1);
    lcd.print(dato);
    delay(5000);
  }
}

void Materias(String dato, int hora){
  //intertar con swhis
} 
void loop() { 
  int hora=0;
  String clase="DA";
  //lcd.display();
  //delay(1000);
  //lcd.noDisplay();
  //delay(50);
  Clase(clase);
  delay(2000);
  Bloques(clase,hora);
  delay(2000);
  hora++;
  Bloques(clase,hora);
  delay(2000);
}