int red = 10;
int yellow = 8;
int green = 6;

void setup() {
  pinMode(red, OUTPUT); //red 
  pinMode(yellow, OUTPUT); //yellow
  pinMode(green, OUTPUT); //green
}

void loop() {
  digitalWrite(red, HIGH);
  delay(1000);
  //digitalWrite(red, LOW);
  //delay(100);

  digitalWrite(yellow, HIGH);
  delay(1000);
  //digitalWrite(yellow, LOW);
  //delay(100);

  digitalWrite(green, HIGH);
  delay(3000);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  //delay(100);
}