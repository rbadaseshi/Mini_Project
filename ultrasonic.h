class ultrasonic {

  private:

    int echoPin; // attach pin D2 Arduino to pin Echo of HC-SR04
    int trigPin; //attach pin D3 Arduino to pin Trig of HC-SR04
    long duration;
    int distance;

  public:

    void ultrasonic_setup(int TrigPin, int EchoPin) {
      long duration;
      int distance;
      trigPin = TrigPin;
      echoPin = EchoPin;
      int Duration = duration;
      int Distance = distance;
      pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
      pinMode(echoPin, INPUT);// Sets the echoPin as an INPUT
      
      }
    void ultrasonicloop()
    {
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
      distance = duration * 0.034 / 2;
      lcd.init(); 
      lcd.backlight();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Distance: ");
      lcd.setCursor(11, 0);
      lcd.print(distance);
        Serial.print("Distance: ");
        Serial.print(distance);
        Serial.println(" cm");
        delay(1000);
     
    }
};
ultrasonic u;
