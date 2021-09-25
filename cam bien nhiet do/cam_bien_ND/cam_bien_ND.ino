int sensorPin = A0;// chân analog kết nối tới cảm biến LM35
void setup()
{
  pinMode(12, OUTPUT);
  Serial.begin(96000);
}

void loop()
{
  int x = analogRead(A0);
  int t = map(x, 0 ,410 ,-50 , 150);
  if(t>36)
  digitalWrite(12, HIGH);
  else
  digitalWrite(12, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}
