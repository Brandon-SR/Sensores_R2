const int reedSwitchPin = 14;
const int relayPin = 12;

volatile bool reedSwitchState = false;
volatile bool lastReedSwitchState = false;

void ICACHE_RAM_ATTR reedSwitchInterrupt() {
  reedSwitchState = !digitalRead(reedSwitchPin);
}

void setup() {
  pinMode(reedSwitchPin, INPUT_PULLUP);
  pinMode(relayPin, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(reedSwitchPin), reedSwitchInterrupt, CHANGE);

  Serial.begin(9600);
}

void loop() {
  if (reedSwitchState != lastReedSwitchState) {
    digitalWrite(relayPin, reedSwitchState);

    if (reedSwitchState) {
      Serial.println("El relé se ha activado.");
    } else {
      Serial.println("El relé se ha desactivado.");
    }

    lastReedSwitchState = reedSwitchState;
  }

  delay(100);
}
