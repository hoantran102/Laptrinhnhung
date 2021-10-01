// C++ code
//
int X= 0;
void setup()
{
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  
}

void loop()
{
  X=analogRead(A0);
  int brightness= map(X,0,1023,0,255);
  analogWrite(10,brightness);
  Serial.println(brightness);
  delay(200);
}
