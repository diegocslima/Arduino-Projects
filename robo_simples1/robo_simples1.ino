int dist = 0;

int i = 0;

int j = 0;

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
  Serial.begin(9600);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(11, 12);
  Serial.println(dist);
  if (dist > 20) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(4, HIGH);
    delay(500); // Wait for 1000 millisecond(s)
  }
}
