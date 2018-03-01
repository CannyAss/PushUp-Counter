// this constant won't change. It's the pin number of the sensor's output:
  const int pingPin = 7;
  long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are 73.746
  // microseconds per inch (i.e. sound travels at 1130 feet per second).
  // This gives the distance travelled by the ping, outbound and return,
  // so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
  }

  long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
  }

void setup() {
  // put your setup code here, to run once:
  /* Record initial value of z, when d is within 3cm for 5 seconds (Using a x=x+1 function)
      Emit a sound to indicate ready status
  */
    // initialize serial communication:
  Serial.begin(9600);

}

void loop() {
  // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);

  using namespace std;
    int x, y, z, d;
    /* x is the number of push-ups
        y is the 'down' state
        z is the 'up' position distance
        d is the distance sensor
    */


    do {
      if (d <= 6 || y == 0) {
        y++;
      }
      if ( d > z || y == 1) {
        x++;
        y--;
      }
    } while ( d < z || d > 5); /* entering push-up status, d is smaller than initial position while further than 5cm) */


      return 0;
}

