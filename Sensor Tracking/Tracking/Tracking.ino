const int TRACKER_PIN = 14;
bool objectDetected = false;

void setup() {
  pinMode(TRACKER_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  int trackerValue = digitalRead(TRACKER_PIN);

  if (trackerValue == LOW && !objectDetected) {
    Serial.println("Objeto detectado!");
    objectDetected = true;
    delay(1000);
  } else if (trackerValue == HIGH && objectDetected) {
    objectDetected = false;
  }
}
