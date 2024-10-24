#define VRX A4
#define VRY A5

int x = 0;
int y = 0;

int ama1 = 3;//derecha
int ama2 = 3;//arriba
int roj1 = 2;//izquierda
int roj2 = 2;//abajo
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

 calc = ((float) (x - 512)) / 2;
 calc = calc > 0 ? calc : 0;
 analogWrite(ama1, calc);
 calc = ((float) (x - 512)) / 2;
 calc = -calc > 0 ? -calc : 0;
 analogWrite(roj1, calc);

 calc = ((float) (y - 512)) / 2;
 calc = calc > 0 ? calc : 0;
 analogWrite(ama2, calc);
 calc = ((float) (y - 512)) / 2;
 calc = -calc > 0 ? -calc : 0;
 analogWrite(roj2, calc);

 // print data to Serial Monitor on Arduino IDE
 Serial.print("x = ");
 Serial.print(x);
 Serial.print(", y = ");
 Serial.println(y);
 delay(200);
}
