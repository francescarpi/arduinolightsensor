
#define LED 3
#define CALIBRATION 10 // Segons...
#define LSENSOR 0
#define LMINVALUE 400

int lValue; // Lee el valor del sensor de luz.

void setup() {
  //Serial.begin(9600);
  pinMode(LED, OUTPUT);
  calibrate();
}

void loop() {
  lValue = analogRead(LSENSOR);

  //Serial.println(lValue);
  
  if (lValue < LMINVALUE) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  // Esperamos 1s antes de la siguiente lectura.
  delay(1000);
}

// Esperem un temps prudencial per què el HC-SR501 es calibri
void calibrate() {
  int status = HIGH;
  for (int i=0;i<CALIBRATION;i++) {
    digitalWrite(LED, status);
    delay(1000);
    status = status ? LOW : HIGH;
  }
}

