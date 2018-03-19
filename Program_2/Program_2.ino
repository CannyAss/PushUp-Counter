// this constant won't change. It's the pin number of the sensor's output:
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

// defines variables
long duration;
int distance;

int x, y, z, t;
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

  for ( t = 0; t < 50; t++ ) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;

    if ( z == 0 ) distance = z; /* initial z value */

    if ( distance ==  distance < z + 3 || distance > z - 3 ) {
      distance = z;
    }
    else t = 0; /* Resets the distance */

    if ( t == 50 ) {
      digitalWrite(buzzer, HIGH);
      delayMicroseconds(10);
      digitalWrite(buzzer, LOW); /* Beeps once to indicated 'ready' status*/
    }
  } /* Setting 'Up' Status position */

  if ( t == 50) {
    do {

      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);

      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);

      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2;

      if (distance <= 6 || y == 0) {
        y++;
      }
      if ( distance >= z || y == 1) {
        x++;
        y = 0;
        digitalWrite(buzzer, HIGH);
        delayMicroseconds(10);
        digitalWrite(buzzer, LOW); /* beeps whenever 1 push up is done*/
      }
    } while ( distance > z + 40 ); /* Ends the moment you stand up */


  }

  return 0;
}

