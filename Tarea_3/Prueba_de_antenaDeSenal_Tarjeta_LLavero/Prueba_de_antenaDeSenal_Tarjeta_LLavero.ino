//librerias a usar
#include <SPI.h>
#include <MFRC522.h>


//Se definen los pines del lector RFID
#define SS_PIN 10
#define RST_PIN 9

// Se crea una instancia del objeto RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);

//LED
int led = 2;

void setup() {
  // Definimos el led como salida 
  pinMode(led, OUTPUT);

  Serial.begin(9600);
  //habilitamos el SPISirve para la comunicacion MOSI, MUSI, SCK Y SS
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  // Comprueba la presencia de una tarjeta
  if (!mfrc522.PICC_IsNewCardPresent()){
    return;
  }

  //Lee el ID de la tarjeta
  if (!mfrc522.PICC_ReadCardSerial()){
    return;
  }
  //Imprime el UID
  Serial.print("UID tag: ");

  for (byte i=0 ; i<mfrc522.uid.size; i++){
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }

  //Encendemos el LED y lo apagamos
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);

  Serial.println();
  delay(1000);

}