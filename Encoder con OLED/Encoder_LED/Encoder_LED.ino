#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

const int ENCODER_DT_PIN = 19;
const int ENCODER_CLK_PIN = 18;
const int RELAY_PIN = 12;

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
  pinMode(RELAY_PIN, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(ENCODER_DT_PIN), encoderDTInterrupt, CHANGE);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Encoder rotativo");
  display.display();
}

void loop() {
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Valor del encoder: ");
  display.println(encoderValue);
  display.display();

  if (encoderValue >= 50) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(100);
}
