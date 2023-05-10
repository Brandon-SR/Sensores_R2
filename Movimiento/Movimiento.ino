const int PIR_PIN = 21;

volatile bool motionDetected = false;

void IRAM_ATTR handleMotionDetection() {
  motionDetected = true;
}

void setup() {
  pinMode(PIR_PIN, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(PIR_PIN), handleMotionDetection, RISING);

  Serial.begin(9600);
  while (!Serial) continue; // esperar a que el puerto serie se conecte
}

void loop() {
  if (motionDetected) {
    Serial.println("¡Movimiento detectado!");
    motionDetected = false;
  }

  delay(100);
}
