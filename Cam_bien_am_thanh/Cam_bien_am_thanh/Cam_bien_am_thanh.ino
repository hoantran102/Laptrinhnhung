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
  inches = duration *0.034*0.39/2; // calling method
  cm = duration * 0.034 / 2; // calling method
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
