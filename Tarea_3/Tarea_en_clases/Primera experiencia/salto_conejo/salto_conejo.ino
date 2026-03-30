int Led6 = 13;
int Led5 = 12;
int Led4 = 11;
int Led3 = 10;
int Led2 = 9;
int Led1 = 8;
int i;
int j;

void setup() {
  pinMode(Led1, OUTPUT); 
  pinMode(Led2, OUTPUT); 
  pinMode(Led3, OUTPUT); 
  pinMode(Led4, OUTPUT); 
  pinMode(Led5, OUTPUT); 
  pinMode(Led6, OUTPUT); 
}

void loop() {
  //digitalWrite(Led1, HIGH);
  //delay(1000);
  //digitalWrite(Led1, LOW);
  //delay(100);

  for(i=1 ; i <= 6; i++){
    for(j=8; j<=13; j++){
      digitalWrite(j, HIGH);



    }
  }

}