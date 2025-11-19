//Godzilla Enclosure
#include <Servo.h>

// Julian
// Panel 1 (Awakening)
Servo myservo; // attached to pin 3 in setup (180)
const int buttonPin = 2; // Panel one switch 
int buttonState = 0;
int previousButtonState = 0;
// Panel 2 (Defense)


// Rodolfo
// Panel 3 (Dodge)
Servo myservo3; // attached to pin 6 in setup (360)
const int buttonPin3 = 7;
int buttonState3 = 0;
int previousButtonState3 = 0;

// Panel 4 (Charge)
const int ledPin = 9;
//Servo myservo4; // attached to pin 9 in setup
const int buttonPin4 = 8;
int buttonState4 = 0;
int previousButtonState4 = 0;

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
  //Panel 3 Switch
  myservo3.attach(6);
  pinMode(buttonPin3, INPUT);
  //Panel 4 Switch
  //myservo4.attach(9);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin4, INPUT);
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
    myservo.write(180); // tells the servo what angle to turn to 0 - 180
  
  } else {
    myservo.write(0);
  }
  // Panel 3: Claw Attack
  // Panel 4: Godzilla Charge
  Panel5();
  Panel3();
  Panel4();
  //analogWrite(ledPin, 255);
  //myservo3.write(180); // tells the servo what angle to turn to 0 - 180 
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
// Panel 3 start
void Panel3() {
   //Panel 5 Switch. Activated when pressing the beam on King Ghidorah's throat.
  buttonState3 = digitalRead(buttonPin3);
  if (buttonState3 != previousButtonState3) {
    if (buttonState3 == HIGH) {
      Serial.println("Switch 3 Pressed! Godzilla on safe spot");
    } else {
      Serial.println("button 3 released, Godzilla off safe spot");
    }
  }
  
  previousButtonState3 = buttonState3;
  // Panel 5 Servo code. Switches facial expression of king Ghidorah
  if (digitalRead(buttonPin3) == HIGH){
    myservo3.write(20); // tells the servo what angle to turn to 0 - 180 
    //Serial.println("panel 5 Switch High");
  } else {
    myservo3.write(90);
    //Serial.println("Panel 5 switch Low");
  }
} 
// Panel 4 start
void Panel4() {
   //Panel 4 Switch. Activated when pressing the beam on King Ghidorah's throat.
  buttonState4 = digitalRead(buttonPin4);
  if (buttonState4 != previousButtonState4) {
    if (buttonState4 == HIGH) {
      Serial.println("Switch 4 Pressed! King Ghidorah is targeted");
    } else {
      Serial.println("button 4 released, King Ghidorah is not targeted anymore");
    }
  }
  
  previousButtonState4 = buttonState4;
  // Panel 4 Servo code. Switches facial expression of king Ghidorah
  if (digitalRead(buttonPin4) == HIGH){
    analogWrite(ledPin, 255);
    //myservo4.write(20); // tells the servo what angle to turn to 0 - 180 
    //Serial.println("panel 5 Switch High");
  } else {
    analogWrite(ledPin, 0);
    //myservo4.write(90);
    //Serial.println("Panel 5 switch Low");
  }
} 
