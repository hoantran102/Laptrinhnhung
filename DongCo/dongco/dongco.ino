
#define motorPin1 12 // L293D Input 12
#define motorPin2 11 // L293D Input 11
#define speedPin 10 // L293D enable chân 10
 // chân biến trở nối với A0
int Mspeed = 0;
void setup() {
pinMode(motorPin1, OUTPUT);
pinMode(motorPin2, OUTPUT);
pinMode(speedPin, OUTPUT);
Serial.begin(9600);
}
void loop() {
int switchPin= analogRead(A1);
Mspeed = analogRead(A0)/4;
int x=digitalRead(2);
analogWrite (speedPin, Mspeed);
Serial.println(switchPin);
Serial.println("Toc Do: ");
Serial.println(Mspeed);
delay(1000);
if (digitalRead(switchPin)) {
digitalWrite(motorPin1, LOW);
digitalWrite(motorPin2, HIGH); 
}
else {
digitalWrite(motorPin1, HIGH);
digitalWrite(motorPin2, LOW);
}

}
