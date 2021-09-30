// C++ code
//
int X= 0;
void setup()
{
  pinMode(13, OUTPUT);
  
}

void loop()
{
  X=analogRead(A0);
  int brightness= map(X,0,1023,0,255);
  analogWrite(13,brightness);
}
