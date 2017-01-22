/**
 * lightsensor
 * Autor: Francesc Arpí @ 2017
 * Circuit per a controlar el llum de la entrada. Només s'encendrà quan sigui fosc i
 * detecti moviment.
 */
#define CALIBRATION 10 // Segons... TODO: Valor recomenat: 60s
#define LSENSOR 0
#define LMINVALUE 400

int lValue; // Lee el valor del sensor de luz.

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  
  // Temps d'espera per què es calibri el sensor de moviment
  calibrate();
}

void loop() {
  lValue = analogRead(LSENSOR);

  //Serial.println(lValue);
  
  if (lValue < LMINVALUE) {
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(LED_BUILTIN, LOW);
  }

  // Esperamos 1s antes de la siguiente lectura.
  delay(1000);
}

// Esperem un temps prudencial per què el HC-SR501 es calibri
void calibrate() {
  int status = HIGH;
  for (int i=0;i<CALIBRATION;i++) {
    digitalWrite(LED_BUILTIN, status);
    delay(1000);
    status = status ? LOW : HIGH;
  }
}

