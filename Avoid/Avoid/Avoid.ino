const int LED = 4;
const int SENSOR = 14;
int valor;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  valor = digitalRead(SENSOR);
  if(valor == LOW){ // Si recibe señal
    digitalWrite(LED, HIGH); // Enciende el LED
    Serial.println("Se ha detectado una señal!"); // Muestra mensaje en el monitor serie
    delay(1000);
  }else{
    digitalWrite(LED, LOW); // Apaga el LED
  }
}
