int dist = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(10, 12);
  Serial.println(dist);

  if (dist > 30) {
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    delay(800); // Wait for 500 millisecond(s)
    digitalWrite(6, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(6, LOW);
    delay(500);
  }
}
