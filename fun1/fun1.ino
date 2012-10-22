int leds[] = {-1,1,2,3,4,5,6,7};
int photoPin = 0;
int size=8;
int val = 0;

void setup()
{
  //ustawiamy
  for (int i=1; i< size; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  val = analogRead(photoPin)/128;
  for (int i=1;i<size;i++) {
    if (i<=val) {
      digitalWrite(leds[i], HIGH);
    } else {
      digitalWrite(leds[i], LOW);
    }
  }
}
