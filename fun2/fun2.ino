int tempPin=0;
int spkrPin=2;
int prevTone=0;

float getTemp(int tempPin=0)
{
  float temp;
  temp=analogRead(tempPin)*5/1024.0;
  temp=temp-0.5;
  return temp/0.01;
}

void setup()
{
  pinMode(spkrPin, OUTPUT);
  //Serial.begin(57600);  
}

void loop()
{
    int aTone=getTemp(tempPin)*((aTone<prevTone)?100:500);
    tone(spkrPin, aTone);   
    (aTone<prevTone)?delay(75):delay(25);
    prevTone=aTone;
}

