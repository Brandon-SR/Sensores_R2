int buzzerPin = 12; // Asignamos el pin digital 12 al buzzer

void setup() {
  pinMode(buzzerPin, OUTPUT); // Configuramos el pin como salida
}

void loop() {
  tone(buzzerPin, 1000); // Hacemos sonar el buzzer a una frecuencia de 1000 Hz
  delay(500); // Esperamos medio segundo
  noTone(buzzerPin); // Detenemos el sonido del buzzer
  delay(500); // Esperamos medio segundo
}
