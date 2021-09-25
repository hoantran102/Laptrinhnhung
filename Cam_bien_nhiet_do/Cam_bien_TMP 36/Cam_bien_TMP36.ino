void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int x = analogRead(A0);
  float t = map(x, 0 , 410 , -50 , 150);
  t=t+1;
  Serial.println(t);
  if (t > 36)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
