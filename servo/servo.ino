#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h> 

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 20 chars and 4 line display

Servo myservo;
int pos = 0;
int potpin = 0;  // analog pin used to connect the potentiometer
int respin = 7;
int wait;

int servoWait(int potpin)
{
  int wait = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  wait = map(wait, 0, 1023, 2, 99);
  
/*
  if(wait <= 4)
    lcd.noBacklight();
  else
    lcd.backlight();
*/
  
  return wait;
}

void setup()
{
  lcd.init();
  lcd.backlight();
  myservo.attach(9);
}

void loop() 
{
  for(pos = 0; pos < 180; pos += 1)
  {
    myservo.write(pos);
    wait = servoWait(potpin);
    delay(wait);
    if(analogRead(respin) > 450)
    {
      lcd.home();
      lcd.print("- no elo");
    }
    else
      lcd.clear();
  }
  
  for(pos = 180; pos>=1; pos-=1)
  {                                
     myservo.write(pos);
    wait = servoWait(potpin);
    delay(wait);
    if(analogRead(respin) > 450)
    {
      lcd.home();
      lcd.print("- hej swiatelko");
    }
    else
      lcd.clear();
  } 
} 
