#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_RESET);

const int JOYSTICK_X_PIN = 34;
const int JOYSTICK_Y_PIN = 35;
const int RELAY_PIN = 26;


void setup() {
  pinMode(JOYSTICK_X_PIN, INPUT);
  pinMode(JOYSTICK_Y_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Joystick con OLED");
  display.display();
}

void loop() {
  int joystickXValue = analogRead(JOYSTICK_X_PIN);
  int joystickYValue = analogRead(JOYSTICK_Y_PIN);

  display.clearDisplay();
  display.setCursor(0,0);
  display.print("X: ");
  display.println(joystickXValue);
  display.print("Y: ");
  display.println(joystickYValue);
  display.display();

  if (joystickXValue < 100) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(100);
}
