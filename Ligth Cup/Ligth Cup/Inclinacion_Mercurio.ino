int led_pin = 12;
int switch_pin = 13;
int val;

void setup() {
  pinMode(led_pin, OUTPUT);
  pinMode(switch_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(switch_pin);
  if(val == HIGH) {
    digitalWrite(led_pin, HIGH);
    Serial.println("El sensor esta inclinado");
    delay(1000);
  } else {
    digitalWrite(led_pin, LOW);
  }
}
