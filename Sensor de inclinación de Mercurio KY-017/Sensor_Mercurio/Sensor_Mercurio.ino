int KY017_pin = 5;

void setup() {
  Serial.begin(9600);
  pinMode(KY017_pin, INPUT);
}

void loop() {
  int inclinacion = digitalRead(KY017_pin);

  if (inclinacion == HIGH) {
    Serial.println("El sensor está inclinado");
  }
  else {
    Serial.println("El sensor no está inclinado");
  }

  delay(2000);
}
