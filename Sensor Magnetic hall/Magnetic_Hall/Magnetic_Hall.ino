#include <Arduino.h>

//Definir el pin de señal al que está conectado el sensor KY-003
#define SENSOR_PIN 2

//Inicializar la comunicación serial
void setup() {
  Serial.begin(9600);
}

void loop() {
  //Leer el valor analógico del sensor KY-003
  int sensorValue = analogRead(SENSOR_PIN);

  //Imprimir el valor leído en la consola
  Serial.print("Valor del sensor KY-003: ");
  Serial.println(sensorValue);

  //Esperar 100ms antes de volver a leer el sensor
  delay(100);
}
