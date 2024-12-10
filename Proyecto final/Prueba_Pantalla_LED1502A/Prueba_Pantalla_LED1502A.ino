#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() { 
  lcd.begin(16, 2);  // Inicializa el LCD con 16 columnas y 2 filas
  lcd.setCursor(0, 0);  // Coloca el cursor en la segunda fila (0 es la primera, 1 es la segunda)
  lcd.write("hola");  // Usa print en lugar de write para mostrar el texto
lcd.print("Hola Mundo!");
delay(1000);
lcd.clear();
lcd.setCursor(0, 1);  // Cambiar a la segunda fila
lcd.print("Segunda Fila");

}

void loop() { }
