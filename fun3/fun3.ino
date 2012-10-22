int fanPin=8;
int tempPin=0;
int ledPin=9;
int fanState=LOW;
float temp;

float getTemp(int);

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

float getTemp(int tempPin=0)
{
  float temp=0;
  temp=analogRead(tempPin)*5/1024.0;
  temp=temp-0.5;
  return temp/0.01;
}
