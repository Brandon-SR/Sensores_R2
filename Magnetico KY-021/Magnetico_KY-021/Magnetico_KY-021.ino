// Definimos el pin GPIO al que está conectado el módulo mini reed
#define REED_PIN 27

void setup() {
  // Inicializamos el puerto serie a una velocidad de 9600 baudios
  Serial.begin(9600);

  // Configuramos el pin GPIO como entrada con resistencia pull-up activada
  pinMode(REED_PIN, INPUT_PULLUP);
}

void loop() {
  // Leemos el valor del pin GPIO
  int reedValue = digitalRead(REED_PIN);

  // Si el valor es 0, significa que el imán está cerca del sensor
  if (reedValue == 0) {
    // Enviamos la cadena por el puerto serie
    Serial.write("¡Se detectó un campo magnético!\n");
  }

  // Esperamos un breve periodo de tiempo para evitar lecturas innecesarias
  delay(1000);
}
