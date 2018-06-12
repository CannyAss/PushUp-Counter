// this constant won't change. It's the pin number of the sensor's output:
// defines pins numbers
const int trigPin = 7;
const int echoPin = 7;

// defines variables
long duration;
int distance;

int x, y, z, t;

void setup() {
  // put your setup code here, to run once:

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Inpu
  Serial.begin(9600); // Starts the serial communication

}

void loop() {
  // put your main code here, to run repeatedly:

  for ( t = 0; t < 50; t++) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.034 / 2;
    Serial.print(distance);
  }
  return 0;

}
