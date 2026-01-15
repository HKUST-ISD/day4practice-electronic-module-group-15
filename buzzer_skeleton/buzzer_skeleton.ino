#include <Arduino.h>
/*

    "pitches.h" is a library that contains pre-defined melodies and note durations for common musical notes.
    You can use this library to create your own melodies and note durations.
    You may refer to the file "pitches.h" in the same folder to see the available melodies.

*/
#include "pitches.h" 
// Built in BUZZER_PIN 35, it is already defined in ISDDevBoard.h
#define BUZZER_PIN 35

//  notes in melody Jingle Bells
int melody[] = {
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_G4
};

// note durations: 4 = quarter note, 8 = eighth note, 2= half note, 1= whole note
int noteDurations[] = {
  8, 8, 4, 8, 8, 4, 8, 8, 8, 8, 2, 8, 8, 8, 8, 4, 8, 8, 8, 8, 4, 8, 8, 8, 2
};

void setup() {

    Serial.begin(115200); 
   

    
}



void loop() {
    // Serial.println("Playing F4...");
    // tone(BUZZER_PIN, NOTE_F4, 500);
    // delay(1000);
    // noTone(BUZZER_PIN);

    // Serial.println("Playing G4...");
    // tone(BUZZER_PIN, NOTE_G4, 500);
    // delay(1000);
    // noTone(BUZZER_PIN);

    Serial.println("Playing Jingle Bells...");
    // Iterate over the notes of the melody:
    for (int thisNote = 0; thisNote < 14 ; thisNote++) {
    // To calculate the note duration, take one second divided by the note type.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);
    // To distinguish the notes, set a minimum time between them.
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // Stop the tone playing:
    noTone(BUZZER_PIN);
    }
}
