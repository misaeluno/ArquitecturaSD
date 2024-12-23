#define VRX A4
#define VRY A5

int x = 0;
int y = 0;

int ama1 = 13;//derecha
int ama2 = 10;//arriba
int roj1 = 9;//izquierda
int roj2 = 11;//abajo
float calc;

void setup() {
  pinMode(ama1, OUTPUT);
  pinMode(ama2, OUTPUT);
  pinMode(roj1, OUTPUT);
  pinMode(roj2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  x = analogRead(VRX); 
  y = analogRead(VRY);
 
//DERECHA AMARAILLO
  calc = ((float) (x - 521)) / 8;
  calc = calc > 0 ? calc : 0;
  calc = calc;
  analogWrite(ama1, calc);

//IZQUIERDA ROJO
  calc = ((float) (x - 512)) / 8;
  calc = -calc > 0 ? 256 - calc : 0;
  analogWrite(roj1, calc);

//ARRIBA AMARILLO
  calc = ((float) (y - 512)) / 8;
  calc = calc > 0 ? calc : 0;
  analogWrite(ama2, calc);

//ABAJO ROJO
  calc = ((float) (y - 512)) / 8;
  calc = -calc > 0 ? 256 - calc : 0;
  analogWrite(roj2, calc);
 
  delay(100);
}
