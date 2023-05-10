#include "pitches.h"

// Notas del tema principal de Mortal Kombat
int melody[] = {
  NOTE_E2, NOTE_G2, NOTE_D3, NOTE_C3, NOTE_A2, NOTE_A2, NOTE_A2, NOTE_GS2,
  NOTE_AS2, NOTE_A2, NOTE_A2, NOTE_E3, NOTE_GS3, NOTE_G3, NOTE_FS3, NOTE_F3,
  NOTE_E3, NOTE_D3, NOTE_E3, NOTE_A3, NOTE_C4, NOTE_E4, NOTE_D4, NOTE_C4,
  NOTE_A3, NOTE_A3, NOTE_B3, NOTE_C4, NOTE_B3, NOTE_A3
};

// Duración de las notas del tema principal de Mortal Kombat
int noteDurations[] = {
  8, 8, 4, 8, 8, 8, 4, 8,
  8, 8, 8, 4, 8, 8, 8, 8,
  8, 8, 8, 4, 8, 8, 8, 8,
  8, 8, 8, 8, 8, 2
};

// Pin del buzzer
int buzzerPin = 4;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
    int duration = 1000 / noteDurations[i];
    tone(buzzerPin, melody[i], duration);
    delay(duration * 1.30); // Para hacer la canción más lenta, aumenta este valor
    noTone(buzzerPin);
    delay(duration / 2);
  }
}
