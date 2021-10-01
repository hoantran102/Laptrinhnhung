int x=0;
int y=0;
int z=0;
void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop()
{
  x=analogRead(A0)/4;
  y=analogRead(A1)/4;
  z=analogRead(A2)/4;
  if(x>255) 
  {
    x = 255;
  }
  if(y>255)
  {
    y=255;
  }
  if(z>255)
  {
    z=255;
  }
  
  analogWrite(11, x);
  analogWrite(10, y);
  analogWrite(9, z);
  Serial.println(analogRead(A0));
  Serial.println(analogRead(A1));
  Serial.println(analogRead(A2));
  
  delay(1000);
}
