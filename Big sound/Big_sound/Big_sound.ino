const int SOUND_ANALOG_PIN = 34; // Pin analógico al que está conectado el sensor de sonido
const int THRESHOLD = 2500; // Umbral de detección de sonido

void setup() {
  analogReadResolution(12); // Configura la resolución de lectura analógica a 12 bits
  Serial.begin(9600); // Inicia la comunicación serie a 9600 baudios
}

void loop() {
  int sound_analog = analogRead(SOUND_ANALOG_PIN);

  if (sound_analog > THRESHOLD) {
    Serial.println("Sonido detectado"); // Envía mensaje al monitor serie
  } else {
    Serial.print("Nivel de sonido: ");
    Serial.println(sound_analog); // Envía nivel de sonido al monitor serie
  }

  delay(1000); // Pequeña pausa para reducir la frecuencia de muestreo del sensor
}
