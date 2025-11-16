//Godzilla Enclosure
#include <Servo.h>
const int STOP = 90 // For all servos if we want them to stop
// Julian 1
Servo doorservo;
const int doorPin = 2; // We can change these specific pins later if needed
const int knobPin = 7;

int lastKnobState = HIGH; // These are for the copper tape switch
int currentKnobState;

const int eyeside = 180; // The side of the door Ghidorah's eye is on
const int wallside = 0; // The normal building wall side

// Julian 2

// Rodolfo 3-4

// Connor 5-6

// Code that runs once
void setup() {
// Julian Setup 1-2
doorservo.attach(doorPin); 
pinMode(knobPin, INPUT_PULLUP); 
doorservo.write(wallside); // Starting position of "door"

// Rodolfo Setup 3-4
/* Panel 3: Godzilla dodges attack.
Soldier motioning direction by waving arm - (1) 180 servo
Godzilla is manully moved from point A (left) to point B (right) - (1) Copper tape Switch */
/* Panel 4: Godzilla Charges beam.
Pressing crystal cutouts (batteries) on Godzilla's back) - (3) Copper tape switch
Light emited by godzilla's mouth changes - (1) LED light */

// Connor Setup 5-6

}

// Code that runs repeatedly
void loop() {
// Julian Loop 1-2
currentKnobState = digitalRead(knobPin);
// One flaw is if you accidently turn on/off the switch while the door is still moving it could mess up the way the door is facing
// For when the copper switch is switched(?)
if (currentKnobState == LOW && lastKnobState == HIGH) { //Anyone know a better way to write this maybe?
    doorservo.write(eyeside); 
    delay(500); // We'll have to play around with this value to make the door turn good
    doorservo.write(STOP); 
}
// For when the copper switch is unswitched(?)
if (currentKnobState == HIGH && lastKnobState == LOW) {
    doorservo.write(wallside); 
    delay(500); // Same thing as the other delay
    doorservo.write(STOP); 
}

lastKnobState = currentKnobState; //Maybe a delay so if you accidently turn on/off the switch it doesn't switch the panel

// Rodolfo Loop 3-4

// Connor Loop 5-6

}
