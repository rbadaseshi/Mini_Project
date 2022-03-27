//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  char message[16]=" i love you :)  ";
  lcd.init(); // initialize the lcd 
  lcd.backlight();
  for(int i=0;i<=15;i++)
  {
    lcd.setCursor(i,0);
    lcd.print(message[i]);
    delay(250);
  }
  delay(1000);
  lcd.setCursor(4,1);
  lcd.print("gabbu");
  
}
void loop()
{
}
