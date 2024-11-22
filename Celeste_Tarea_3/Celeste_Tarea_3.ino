#include <MFRC522.h>
#include <require_cpp11.h>
#include <MFRC522Extended.h>
#include <deprecated.h>

#include <SPI.h>

#define RST 9
#define SDA 10
#define MOSI 11
#define MISO 12
#define SCK 13

MFRC522 rfid(SDA, RST);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  pinMode(MISO, INPUT);
  pinMode(MOSI, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(SDA, OUTPUT);
  pinMode(RST, INPUT);
  Serial.println("Place your card near the reader...");
}

void loop() {
  // Check if a new card is present
  if (!rfid.PICC_IsNewCardPresent()) {
    return;  // No card detected, return to loop
  }
  // Check if we can read the card's UID
  if (!rfid.PICC_ReadCardSerial()) {
    return;  // Failed to read card UID
  }
  // Display the UID
  Serial.print("Card UID: ");
    
  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);  // Print each byte of the UID in hexadecimal
    Serial.print(" ");
  }
  Serial.println();
  // Halt PICC (to stop it from constantly reading the same card)
  rfid.PICC_HaltA();
  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();
}
