

#include <LiquidCrystal.h> 
int y = 0, pushup = 0, initial = 0, Contrast = 2000, x=0, i=0, l=0, sensor, degrees;

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
      delay(5000); 
  pinMode(13, OUTPUT);

    
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

if (cm<100 && initial==0){
    digitalWrite(13, LOW); //Not Ready (LED is off)
  for (int i = 0; i<100; i++){
    x=x+cm; /* Total initial distance recorded */
    if (i==99){
      initial = x/99; /*Average initial distance*/
    tone(buzzer, 500); // Send 500Hz sound signal...
    delay(200);        // ...for 0.2 sec
    noTone(buzzer);     // Stop sound...}
    tone(buzzer, 500); // Send 500Hz sound signal...
    delay(200);        // ...for 0.2 sec
    noTone(buzzer);     // Stop sound...}
    
    }
  }
    digitalWrite(13, HIGH); //Ready (LED is green)
}



  if (initial > 0){
      sensor = analogRead(5);
        degrees = map(sensor, 768, 853, 0, 90);
  if ( cm < 7 && y == 0 && degrees <-130 && degrees > -270) {
    y++;
  }

  if ( cm >= initial && y == 1 && cm<100) {
    digitalWrite(13, LOW); //Push up started(LED is off)
    tone(buzzer, 1500); // Send 1500Hz sound signal...
    delay(100);        // ...for 0.1 sec
    noTone(buzzer);     // Stop sound...}
    y--;
    pushup++;
  }
     lcd.setCursor(0, 0);
     lcd.print("Pushups Done: ");
     lcd.print(pushup);
  
}

if (cm>100){
  l++;
  if (l>200){
  for (;;);
  }
} /*End Function*/

}



long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2; // distance in cm
}
