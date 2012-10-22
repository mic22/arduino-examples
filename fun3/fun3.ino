int fanPin=8;
int tempPin=0;
int ledPin=9;
int fanState=LOW;
float temp;

float getTemp(int tempPin=0)
{
  return 10;
}

void setup()
{
  pinMode(fanPin, OUTPUT);
  pinMode(ledPin, OUTPUT);;
  //Serial.begin(57600);  
}

void loop()
{
    temp=getTemp(tempPin);
    fanState=(temp>25)?HIGH:LOW;
    //Serial.println(temp);
    digitalWrite(fanPin, fanState);
    digitalWrite(ledPin, fanState);
}

