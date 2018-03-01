// this constant won't change. It's the pin number of the sensor's output:
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;
int safetyDistance;

int x, y, z, d, t;
/* x is the number of push-ups
    y is the 'down' state
    z is the 'up' position distance
    d is the distance sensor
*/

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication

}

void loop() {

  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;

  for ( t = 0; t < 300; t++ ) {
    if ( distance == distance + 3 || distance - 3 ) {
      distance = z;
    }
  } /* Setting 'Up' Status position */


  do {
    if (distance <= 6 || y == 0) {
      y++;
    }
    if ( distance > z || y == 1) {
      x++;
      y--;
    }
  } while ( distance < z || distance > 5); /* entering push-up status, d is smaller than initial position while further than 5cm) */
   digitalWrite(buzzer, HIGH);

  return 0;
}

