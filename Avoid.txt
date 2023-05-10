const int LED = 4;
const int SENSOR = 14;
int valor;
void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SENSOR, INPUT);
}

void loop() {
  valor = digitalRead(SENSOR);
  if(valor == 0){
    digitalWrite(LED, 1);
  }else{
    digitalWrite(LED, 0);
  }
} 