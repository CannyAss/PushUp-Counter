int y = 0, pushup = 0, initial = 0;

// this constant won't change. It's the pin number of the sensor's output:
const int trigPin = 7; //Change to pin you use
const int echoPin = 6; //Here too
const int buzzer = 8;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 digitalWrite(trigPin, LOW);
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
  if ( cm < 6 && y == 0 ) {
    y++;
  }

  if ( cm > initial - 2 && y == 1) {
    tone(buzzer, 500); // Send 500Hz sound signal...
    delay(250);        // ...for 0.25 sec
    noTone(buzzer);     // Stop sound...}
    y--;
    pushup++;
  }
  delay(100);
}


long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2; // distance in cm
}
