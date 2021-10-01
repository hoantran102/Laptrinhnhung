int x=0;
int y=0;
int z=0;
int red=0;
int blue=0;
int green=0;
void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  x=analogRead(A0);
  y=analogRead(A1);
  z=analogRead(A2);
   red=map(x,0,1023,0,255);
   blue=map(y,0,1023,0,255);
   green=map(z,0,1023,0,255);
  
  
  analogWrite(11, red);
  analogWrite(10, blue);
  analogWrite(9, green);
  Serial.println(analogRead(A0));
  Serial.println(analogRead(A1));
  Serial.println(analogRead(A2));
  
  delay(1000);
}
