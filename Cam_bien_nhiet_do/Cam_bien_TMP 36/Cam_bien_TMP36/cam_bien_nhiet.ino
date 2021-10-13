#define SENSOR_PIN A0
#define LED 12
float voltage = 0; // Thiết lập một số giá trị ban đầu
float sensor = 0;

float celsius = 0;

float fahrenheit = 0;

void setup() {
  Serial.begin(9600);   // Bật serial monitor
  pinMode(LED,OUTPUT);
}


void loop()

{              // Bắt đầu đo

  sensor = analogRead(SENSOR_PIN);
  
  voltage = (sensor*5000)/1024; // Chuyển đổi tín hiệu cảm biến sang mili Volt
  
  voltage = voltage-500;        // Trừ đi điện áp bù
  
  celsius = voltage/10;         // Chuyển đổi mV sang độ C
  fahrenheit = ((celsius * 1.8)+32); // Đổi độ C sang độ F
  
  Serial.print("Nhiet do: ");
  
  Serial.print(celsius,2);
  
  Serial.println(" do C");
  
 Serial.print("Nhiet do: ");
  
  Serial.print(fahrenheit,2);
  
  Serial.println(" do F");
  
  Serial.println("____");
  if(celsius >30)
  {
    digitalWrite(LED,HIGH);
  }
  else 
    digitalWrite(LED,LOW);
  delay (1000); // delay 1s để khổi trôi dư liệu
}
