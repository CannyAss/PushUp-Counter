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

void loop()
{
 // establish variables for duration of the ping, 
 // and the distance result in inches and centimeters:
 long duration, inches, cm;
 
 
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 duration = pulseIn(echoPin, HIGH);

 // convert the time into a distance
 cm = microsecondsToCentimeters(duration);
 
 Serial.print(cm);
 Serial.print("cm");
 Serial.println();
 
 delay(100);
 if ( cm < 6){
    tone(buzzer, 500); // Send 1KHz sound signal...
    delay(100);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...}
}
}


long microsecondsToCentimeters(long microseconds)
{
 // The speed of sound is 340 m/s or 29 microseconds per centimeter.
 // The ping travels out and back, so to find the distance of the
 // object we take half of the distance travelled.
 return microseconds / 29 / 2;
 
}



