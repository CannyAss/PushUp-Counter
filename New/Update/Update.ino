#include <LiquidCrystal.h> 
int y = 0, pushup = 0, initial = 0, Contrast = 2000;

// this constant won't change. It's the pin number of the sensor's output:
const int trigPin = 7; //Change to pin you use
const int echoPin = 6; //Here too
const int buzzer = 8;

 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   
 
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 digitalWrite(trigPin, LOW);
    analogWrite(9,Contrast);
    lcd.begin(16, 2);
}

void loop() {
  // establish variables for duration of the ping, and the distance result
  // in centimeters:
  long duration, cm;

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration); /* Finding the distance */

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (initial == 0) initial = cm;
  if ( cm < 7 && y == 0 ) {
    y++;
  }

  if ( cm > initial && y == 1) {
    tone(buzzer, 1500); // Send 500Hz sound signal...
    delay(100);        // ...for 0.1 sec
    noTone(buzzer);     // Stop sound...}
    y--;
    pushup++;
  }
     lcd.setCursor(0, 0);
     lcd.print("Pushups Done: ");
     lcd.print(pushup);
}


long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2; // distance in cm
}
