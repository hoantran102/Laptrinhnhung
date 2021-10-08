void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  int lux= analogRead(A0);
  Serial.println(analogRead(A0));
  
 if (lux < 902 )
 {
  digitalWrite(13,HIGH);
 }
 else digitalWrite(13, LOW);
 }
