// chân analog kết nối tới cảm biến LM35
float temp;
void setup()
{
  pinMode(12, OUTPUT);
  Serial.begin(9600);
  //không cần phải pinMode cho các chân analog trước khi dùng
}

void loop()
{
  int x = analogRead(A0);
  float voltage = x * 5.0 / 1024.0;
  temp = voltage * 100.0;
  Serial.println(temp);
  if (temp > 36){
    digitalWrite(12, HIGH);}
  else
  {
    digitalWrite(12, LOW);
  }
  delay(1000); // Wait for 1000 millisecond(s)
}
