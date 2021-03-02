#include <Servo.h>

Servo servo_9;

int pos = 0;
int cm = 0;

void setup()
{
  servo_9.attach(9);
  pinMode(13, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  servo_9.write(pos);

  cm = 0.01723 * readUltrasonicDistance(7, 7);
  
  if (cm < 100) {
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    pos-=2;
  } else {
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    pos+=2;
  }
  
  if (pos <= 0) {
    pos = 0;
  }
  
  if (pos >= 180) {
    pos = 180;
  }
  
  delay(200);
}


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

