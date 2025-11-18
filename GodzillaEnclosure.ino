//Godzilla Enclosure
#include <Servo.h>

// Julian
// Panel 1 (Awakening)
Servo doorservo; // attached to pin 3 in setup (180)
const int buttonPin = 2; // Panel one switch 
int buttonState = 0;
int previousButtonState = 0;
// Panel 2 (Defense)


// Rodolfo
// Panel 3 (Dodge)
// Panel 4 (Charge)

// Conner
// Panel 5 (Attack)
Servo myservo5; // attached to pin 10 in setup
const int buttonPin5 = 12;
int buttonState5 = 0;
int previousButtonState5 = 0;
// Panel 6 (Celebrate)

void setup() {
  // put your setup code here, to run once:
  //Panel 1 Switch
  myservo.attach(3);
  pinMode(buttonPin, INPUT);
  //Panel 5 Switch
  myservo5.attach(10);
  pinMode(buttonPin5, INPUT);
  Serial.begin(9600);
}

void loop() {// put your main code here, to run repeatedly:
  //Panel 1 Switch
  buttonState = digitalRead(buttonPin);
  if (buttonState != previousButtonState) {
    if (buttonState == HIGH) {
      Serial.println("Switch Pressed! Boulder hit ground");
    } else {
      Serial.println("button released, Boulder removed");
    }
  }
  previousButtonState = buttonState;

  // Panel 1 Servo code
  if (digitalRead(buttonPin) == HIGH){
    doorservo.write(180); // tells the servo what angle to turn to 0 - 180
  
  } else {
    doorservo.write(0);
  }
  // Panel 3: Claw Attack
  // Panel 4: Godzilla Charge
  Panel5();
}
// Panel 5 must be here or the code will get error "x was not declared in this scope"
void Panel5() {
   //Panel 5 Switch. Activated when pressing the beam on King Ghidorah's throat.
  buttonState5 = digitalRead(buttonPin5);
  if (buttonState5 != previousButtonState5) {
    if (buttonState5 == HIGH) {
      Serial.println("Switch Pressed! Beam on Ghidorah");
    } else {
      Serial.println("button released, Beam off ghidorah");
    }
  }
  previousButtonState5 = buttonState5;
  // Panel 5 Servo code. Switches facial expression of king Ghidorah
  if (digitalRead(buttonPin5) == HIGH){
    myservo5.write(20); // tells the servo what angle to turn to 0 - 180 
    //Serial.println("panel 5 Switch High");
  } else {
    myservo5.write(90);
    //Serial.println("Panel 5 switch Low");
  } 
}

