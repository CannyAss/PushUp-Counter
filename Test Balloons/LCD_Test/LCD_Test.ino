

#include <LiquidCrystal.h>  
int Contrast=90, x=5;
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   

 void setup()
 { 
    analogWrite(9,Contrast);
     lcd.begin(16, 2);
  }  
     void loop()
 {  
     lcd.setCursor(0, 0);
     lcd.print("Pushups Done" );
     lcd.print(x);
 }
