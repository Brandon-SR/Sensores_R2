int PulseSensorPurplePin = 4;
int LED13 = 2;


int Signal;
int Threshold = 550;

void setup() {
  pinMode(LED13, OUTPUT);
  Serial.begin(9600);
}


void loop() {

  Signal = analogRead(PulseSensorPurplePin);
  Serial.println(Signal);

  if (Signal > Threshold) {
    digitalWrite(LED13, HIGH);
  } else {
    digitalWrite(LED13, LOW);
  }

  delay(1000);
}