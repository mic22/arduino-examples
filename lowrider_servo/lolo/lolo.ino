#include <Wire.h>
#include <Servo.h> 

Servo myservo;

int servoWait(int potpin)
{
  int wait = analogRead(potpin);
  wait = map(wait, 0, 1023, 90, 180);
  return wait;
}

void setup()
{
  myservo.attach(9);
}

void loop() 
{
    myservo.write(servoWait(8));
} 
