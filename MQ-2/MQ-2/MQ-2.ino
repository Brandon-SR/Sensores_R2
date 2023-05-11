const int MQ2_PIN = 34;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float sensorValue = analogRead(MQ2_PIN);
  float voltage = sensorValue / 4095.0 * 3.3;  // Convertir la lectura del pin analógico en voltaje
  float ppm = voltage * 1000.0 / 1.4;  // Calcular la concentración de gas en partes por millón (ppm)
  
  Serial.print("Lectura del sensor: ");
  Serial.print(sensorValue);
  Serial.print("\tVoltaje: ");
  Serial.print(voltage);
  Serial.print("\tConcentracion (ppm): ");
  Serial.println(ppm);

  delay(1000);
}
