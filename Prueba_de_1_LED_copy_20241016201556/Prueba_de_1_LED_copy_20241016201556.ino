int roj = 13;

void setup() {
  pinMode(roj, OUTPUT);      //Rojo
}

void loop() {
           
  digitalWrite(roj, HIGH);    //se enciende todas las lucen 
  delay(7500);
  digitalWrite(roj, LOW);
  delay(2000);

}