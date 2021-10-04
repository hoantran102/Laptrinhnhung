const int buttonPin = 2;     
const int ledPin =  13;     
int buttonState = 0; 
void setup() { 
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}
void loop() {
  buttonState = digitalRead(buttonPin); //Đọc giá trị của cổng số 2 của nút
  if (buttonState == HIGH) {  // Kiểm tra nếu nút được bấm thì buttonState là HIGH
    digitalWrite(ledPin, HIGH);// Mở Led
  } else {
    digitalWrite(ledPin, LOW); // Tắt Led
  }
}
