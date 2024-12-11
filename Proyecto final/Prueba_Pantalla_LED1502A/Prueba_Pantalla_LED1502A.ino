#include <LiquidCrystal_I2C.h> //DESCARGAR LIBRERÍA:
                                                //  https://github.com/ELECTROALL/Codigos-arduino/blob/master/LiquidCrystal_I2C.zip

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("08:00 A 09:30"); 
  lcd.setCursor (0,1);
  lcd.print("Juego de rol DYD");
}

void loop() { 

  lcd.display();
  delay(1000);
  lcd.noDisplay();
  delay(50);
}