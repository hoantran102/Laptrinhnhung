
// include the library code:
#include <LiquidCrystal.h>
#include <Keypad.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 13, en = 12, d4 = A3, d5 = A2, d6 = A1, d7 = A0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {3, 2, 4, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 6, 7}; //connect to the column pinouts of the keypad
int LCDCol = 0;
int LCDRow = 0;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String v_passcode="";

void setup(){
   Serial.begin(9600);
   lcd.begin(16, 2);
   lcd.setCursor(LCDCol, LCDRow);
   pinMode(11,OUTPUT);
   }
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
           
    
    if ( LCDCol > 5  )
    {   
     ++LCDRow; 
      
      if (LCDRow>1)
      { LCDRow=0; LCDCol = 0 ;  lcd.clear(); }
   
    LCDCol = 0 ;
    }
    
      
       
    lcd.setCursor (LCDCol, LCDRow); 
       
       lcd.print(key);
    
    ++LCDCol;
    
  }
  
  if (key != NO_KEY){
    //Serial.println(key);
    
    v_passcode = v_passcode + key;
    
    if(key=='*')
    { lcd.setCursor(1,2);
  lcd.print("Enter Password");
      Serial.println("Enter Password");
        v_passcode="";
    }
    
    if(key=='#')
    {
      Serial.println("Validate the Password");
        Serial.println(v_passcode);
        
        if (v_passcode=="1234#")
        {
          lcd.setCursor(1,2);
  lcd.print("Access Granted");
 digitalWrite(11,HIGH);
        }
        else
        {
          lcd.setCursor(1,2);
  lcd.print("Access Denied");
  delay(2000);
  LCDRow=0; LCDCol = 0 ;  lcd.clear();
        }      
    }        
  }
}
