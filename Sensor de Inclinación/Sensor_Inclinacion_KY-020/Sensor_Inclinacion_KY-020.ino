const int tiltSensorPin = 4;
int tiltValue = 0;

void setup() {
  pinMode(tiltSensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  tiltValue = digitalRead(tiltSensorPin);

  if (tiltValue == HIGH) {
    Serial.println("El sensor de inclinación está en posición horizontal");
  } else {
    Serial.println("El sensor de inclinación está en posición vertical");
  }

  delay(2000);
}
