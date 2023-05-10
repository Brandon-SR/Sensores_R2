const int TERMISTOR_RESISTANCE = 10000;

void setup() {
  Serial.begin(9600);  // inicializa la interfaz serial a 9600bps
}

void loop() {
  // lee el valor del pin
  int v_input = analogRead(4);

  // calcula la resistencia del termistor comparándola con la resistencia de 10K ohmios a bordo del módulo
  float r_ohms = TERMISTOR_RESISTANCE * (1023.0 / (float)v_input - 1.0);

  // calcula la temperatura en grados Celsius
  float temp_c = (1.0 / (0.001129148 + (0.000234125 * log(r_ohms)) + 0.0000000876741 * log(r_ohms) * log(r_ohms) * log(r_ohms))) - 273.15;

  // imprime el resultado en la interfaz serial
  Serial.print("Temperatura (degC): ");
  Serial.println(temp_c);

  delay(1000);  // espera de 2 segundos
}
