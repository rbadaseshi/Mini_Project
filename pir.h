class pir
{
  private:
    int led;    // the pin that the LED is atteched to
    int sensor;   // the pin that the sensor is atteched to
    int state;  // by default, no motion detected
    int val = 0;

  public:
    void pir_setup(int Led, int Sensor)
    {
      led=Led;
      sensor=Sensor;
      pinMode(led, OUTPUT);      // initalize LED as an output
      pinMode(sensor, INPUT);    // initialize sensor as an input
    }
    void pirloop()
    {
      val = digitalRead(sensor);   // read sensor value
      if (val == HIGH) {           // check if the sensor is HIGH
        digitalWrite(led, HIGH);   // turn LED ON
        delay(500);                // delay 100 milliseconds

        if (state == LOW) {
          lcd.setCursor(0, 1);
          Serial.println("Motion detected!");
          lcd.print("Motion detected!");
          state = HIGH;       // update variable state to HIGH
        }
      }
      else {
        digitalWrite(led, LOW); // turn LED OFF
        delay(500);             // delay 200 milliseconds

        if (state == HIGH) {
          Serial.println("Motion stopped!");
          lcd.setCursor(0, 1);
          Serial.println("Motion stopped!");
          state = LOW;       // update variable state to LOW
        }
      }
    }
};
pir p;
