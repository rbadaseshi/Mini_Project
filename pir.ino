#include <LiquidCrystal_I2C.h>
int led = 13;                // the pin that the LED is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

LiquidCrystal_I2C lcd(0x27,20,4); 

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop(){

  
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(1000);                // delay 100 milliseconds 
    
    if (state == LOW) {
      Serial.println("Motion detected!");
      lcd.setCursor(0,0);
      lcd.print("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(500);             // delay 200 milliseconds 
      
      if (state == HIGH){
        Serial.println("Motion stopped!");
        lcd.setCursor(0,0);
        lcd.print("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
