char key[] = { 1, 0, 1, 0, 0, 0 };//clave A,A,B,A
char data[] = { 0, 0, 0, 0, 0, 0 };
int size = 6;

int roj = 4;
int ama = 3;
int ver = 2;
int bA = 9;
int bB = 8;
int cont = 0;
char start = 0;

void setup() {
 pinMode(roj, OUTPUT);//Rojo
 pinMode(ama, OUTPUT);//Verde
 pinMode(ver, OUTPUT);//Azul
 pinMode(bB, INPUT_PULLUP);//boton rojo   Boton B
 pinMode(bA, INPUT_PULLUP);//boton verde  Boton A
}

void loop() {
 while (cont <= size){//se repetira hasta tener la contraseña correcta
  if (start){
   start = 0;
   digitalWrite(roj, HIGH);
   digitalWrite(ama, HIGH);
   digitalWrite(ver, HIGH);
   delay(750);
   digitalWrite(roj, LOW);
   digitalWrite(ver, LOW);
  }
  if (digitalRead(bA)){
   data[cont] = 0;
   if (data[cont] == key[cont]) Correct();
   else Incorrect();
  }
  if (digitalRead(bB)){
   data[cont] = 1;
   if (data[cont] == key[cont]) Correct();
   else Incorrect();
  }
  digitalWrite(ama, HIGH);
 }
}
void LEDsOn(void) {
 digitalWrite(ama, LOW);
 delay(100);// dura 1/10 de segundo
 digitalWrite(ver, HIGH);// enciende el led verde
 delay(250);// dura 1/4 de segundo
 digitalWrite(ver, LOW);// se apaga el led verde
}
void Correct() {
 LEDsOn();
 cont++;//el contador aumenta
}
void Incorrect() {
 LEDsOn();
 cont = 0;//contador par saber si la clave esta bien empieza en 1
 start = 1;
}
