int x,y,z;
const int red=11; // Chân Red 
const int blue=10;// Chân Blue 
const int green=9;// Chân Green
void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}
void loop()
{
   x=map(analogRead(A0),0,1023,0,255);
   y=map(analogRead(A1),0,1023,0,255);
   z=map(analogRead(A2),0,1023,0,255);
  analogWrite(red, x);
  analogWrite(blue, y);
  analogWrite(green, z);
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  delay(100);
}
