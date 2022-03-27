#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include "pir.h"
#include "ultrasonic.h"
 

void setup() {
  lcd.begin(16,2); // Start-Up Display
  lcd.setCursor(0,0);
  u.ultrasonic_setup(2,4); //(Triger,Echo)
  p.pir_setup(13,3); //(Led,Sensor)

}

void loop() {
  u.ultrasonicloop();
  p.pirloop();
}
