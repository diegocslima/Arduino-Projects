#include <Servo.h>

int dist = 0;

int pos = 0;

int diste = 0;

int disd = 0;

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

Servo servo_9;

void setup()
{
  Serial.begin(9600);

  servo_9.attach(9);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  dist = 0.01723 * readUltrasonicDistance(12, 12);
  Serial.println(dist);
  servo_9.write(90);
  delay(600); // Wait for 600 millisecond(s)
  if (dist > 50) {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  } else {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(1000); // Wait for 1000 millisecond(s)
    servo_9.write(180);
    delay(600); // Wait for 600 millisecond(s)
    diste = 0.01723 * readUltrasonicDistance(12, 12);
    Serial.println(diste);
    servo_9.write(0);
    delay(1200); // Wait for 1200 millisecond(s)
    disd = 0.01723 * readUltrasonicDistance(12, 12);
    Serial.println(disd);
    servo_9.write(90);
    delay(600); // Wait for 600 millisecond(s)
    digitalWrite(4, HIGH);
    delay(500); // Wait for 500 millisecond(s)
    digitalWrite(4, LOW);
  }
}
