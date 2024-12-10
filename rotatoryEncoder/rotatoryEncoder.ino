#include <ezButton.h>  // the library to use for SW pin
#include <math.h>

#define CLK_PIN 2
#define DT_PIN 3
#define SW_PIN 4

#define DIRECTION_CW 0   // clockwise direction
#define DIRECTION_CCW 1  // counter-clockwise direction
#define TIME 1

unsigned long timer = 0;
unsigned long aux = 0;
int direction = DIRECTION_CW;
int CLK_state;
int prev_CLK_state;
bool settingTime = false;
int setting = 0;
unsigned long step = 0;

ezButton button(SW_PIN);  // create ezButton object that attach to pin 4

// the setup routine  runs once when you press reset:
void setup() {                
  // initialize  the digital pins as outputs.
  Serial.begin(9600);
  // configure encoder pins as inputs
  pinMode(CLK_PIN, INPUT);
  pinMode(DT_PIN, INPUT);
  button.setDebounceTime(50);  // set debounce time to 50 milliseconds

  // read the initial state of the rotary encoder's CLK pin
  prev_CLK_state = digitalRead(CLK_PIN);
}

// the loop routine runs over  and over again forever:
void loop() {
    button.loop();  // MUST call the loop() function first

  // read the current state of the rotary encoder's CLK pin
  CLK_state = digitalRead(CLK_PIN);

  // If the state of CLK is changed, then pulse occurred
  // React to only the rising edge (from LOW to HIGH) to avoid double count
  if (CLK_state != prev_CLK_state && CLK_state == HIGH) {
    // if the DT state is HIGH
    // the encoder is rotating in counter-clockwise direction => decrease the counter
    if ((digitalRead(DT_PIN) == HIGH) && settingTime) {
      timer += step*TIME;
    }
  }

  // save last CLK state
  prev_CLK_state = CLK_state;

  if (button.isPressed()) {
    if (!settingTime) settingTime = true;
    else {
      switch (setting) {
        case 0:
          setting = 1;
          step = 60UL;
          break;
        case 1:
          setting = 2;
          step = 600UL;
          break;
        case 2:
          setting = 3;
          step = 3600UL;
          break;
        case 3:
          setting = 4;
          step = 36000UL;
          break;
        case 4:
          setting = 0;
          step = 0UL;
          settingTime = false;
          break;
      }
    }
  }
  if (!settingTime) timer += (millis() - aux);
  timer %= (86400*TIME);
  if (!settingTime) aux = millis();
  Display(0, (int) floor(timer/(36000UL*TIME)%3)); // Obtengo la decena de la hora
  Display(1, (int) floor(timer/(3600UL*TIME))%10); // Obtengo la unidad de la hora
  Display(2, (int) floor(timer/(600UL*TIME))%6); // Obtengo la decena del minuto
  Display(3, (int) floor(timer/(60UL*TIME))%10); // Obtengo la unidad del minuto
  
  Serial.print(timer);
  Serial.println();
}

void Display(int display, int value) {
  Serial.print(value);
  Serial.print(" ");
  /*
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D1 + display, HIGH);
  switch (value) {
    case 0:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, HIGH);
      break;
    case 1:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
    case 2:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;
    case 3:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, LOW);
      break;
    case 4:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 5:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 6:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 7:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
    case 8:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, LOW);
      digitalWrite(pinE, LOW);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
    case 9:
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(pinC, LOW);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, LOW);
      digitalWrite(pinG, LOW);
      break;
    default:
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, HIGH);
      digitalWrite(pinC, HIGH);
      digitalWrite(pinD, HIGH);
      digitalWrite(pinE, HIGH);
      digitalWrite(pinF, HIGH);
      digitalWrite(pinG, HIGH);
      break;
  }
  delay(1);
  */
}
