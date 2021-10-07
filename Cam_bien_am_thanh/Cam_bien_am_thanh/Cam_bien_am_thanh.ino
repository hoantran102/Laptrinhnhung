const int Echo = 2; // Echo Pin of Ultrasonic Sensor
const int Trig = 3; // Trigger Pin of Ultrasonic Sensor
int led = 13  ;
void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600); // Starting Serial Communication
  pinMode(Trig, OUTPUT); // initialising pin 3 as output
  pinMode(Echo, INPUT); // initialising pin 2 as input
}
void loop()
{
  float duration, inches, cm;

  digitalWrite(Trig, LOW);
  delayMicroseconds(2);

  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);

  digitalWrite(Trig, LOW);

  duration = pulseIn(Echo, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
  cm = microsecondsToCentimeters(duration); // calling method

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if (inches < 10)
  {
    digitalWrite(led, HIGH);
  }
  else {
    digitalWrite(led, LOW);
  }
  delay(1000);
}
float microsecondsToInches(float x) // method to covert microsec to inches
{
  return x / 74.16 / 2;
}
float microsecondsToCentimeters(float x) // method to covert microsec to centimeters
{
  return x / 29.41 / 2;
}
