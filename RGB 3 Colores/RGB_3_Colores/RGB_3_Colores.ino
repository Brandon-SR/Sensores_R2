const int led_pinR = 2;
const int led_pinG = 4;
const int led_pinB = 5;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(led_pinR, OUTPUT);
  pinMode(led_pinG, OUTPUT);
  pinMode(led_pinB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led_pinR, HIGH);
delay(200);
digitalWrite(led_pinR, LOW);
delay(200);
digitalWrite(led_pinG, HIGH);
delay(200);
digitalWrite(led_pinG, LOW);
delay(200);
digitalWrite(led_pinB, HIGH);
delay(200);
digitalWrite(led_pinB, LOW);
delay(200);

digitalWrite(led_pinR, HIGH);
digitalWrite(led_pinG, HIGH);
digitalWrite(led_pinB, HIGH);

delay(200);

digitalWrite(led_pinR, LOW);
digitalWrite(led_pinG, LOW);
digitalWrite(led_pinB, LOW);
}
