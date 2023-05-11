#include <Wire.h>

const int ENCODER_DT_PIN = 19;
const int ENCODER_CLK_PIN = 18;

volatile long encoderValue = 0;
volatile int lastEncoderDTState = LOW;
volatile int currentEncoderDTState = LOW;

void ICACHE_RAM_ATTR encoderDTInterrupt() {
  currentEncoderDTState = digitalRead(ENCODER_DT_PIN);

  if (currentEncoderDTState != lastEncoderDTState) {
    if (digitalRead(ENCODER_CLK_PIN) == currentEncoderDTState) {
      encoderValue++;
    } else {
      encoderValue--;
    }
  }

  lastEncoderDTState = currentEncoderDTState;
}

void setup() {
  pinMode(ENCODER_DT_PIN, INPUT_PULLUP);
  pinMode(ENCODER_CLK_PIN, INPUT_PULLUP);
  
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(ENCODER_DT_PIN), encoderDTInterrupt, CHANGE);
}

void loop() {
  Serial.print("Valor del encoder: ");
  Serial.println(encoderValue);
  delay(100);
}
