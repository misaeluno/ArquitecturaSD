int roj = 13;

void setup() {
  pinMode(roj, OUTPUT);      //Rojo
}

void loop() {
           
  digitalWrite(roj, HIGH);    //se enciende todas las lucen 
  delay(750);
  digitalWrite(roj, LOW);     //se apagan todas excepto la amarilla
  delay(2000);

}