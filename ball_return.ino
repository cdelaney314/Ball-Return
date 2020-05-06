#define outPin 8
#define inPin 0

const int tolerance = 100;
int emptyLevel;
long int timeNoticed;
bool noticed = false;

void setup()
{
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(outPin, OUTPUT);
  pinMode(inPin, INPUT);
  Serial.begin(9600);
  
  emptyLevel = analogRead(inPin);
}

void loop()
{
  int x = analogRead(inPin);
  Serial.println(x);

  if(!noticed && emptyLevel - x > tolerance)
  {
    noticed = true;
    timeNoticed = millis();
  }

  if(noticed)
  {
    int elapsed = millis() - timeNoticed;
    
    if(elapsed <= 1000)
    {
      // wait 1 seconds
      Serial.println("NOTICED");
    }
    else if(elapsed <= 3000)
    {
      // turn on for 2 seconds
      digitalWrite(outPin, HIGH);
      Serial.println("ON");
    }
    else
    {
      // turn off and reset
      digitalWrite(outPin, LOW);
      noticed = false;
      Serial.println("OFF");
    }
  }
}
