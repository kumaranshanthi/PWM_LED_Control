#include <Servo.h>

Servo myservo;  // create servo object to control a servo

#define pwm_pin 2
const int relayPin1 =  8;      // the number of the LED pin
const int relayPin2 =  10;      // the number of the LED pin
volatile unsigned long pwm_start;
volatile int pwmvalue;

void setup() {
  Serial.begin(9600);
   // initialize the LED pin as an output:
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2),pwminput,CHANGE);

}

void loop() {

      //Serial.println("hi");
      Serial.println(pwmvalue);

      if((pwmvalue>1900)&&(pwmvalue<2200))
        {
          digitalWrite(relayPin1, HIGH);digitalWrite(relayPin2, HIGH);
          }
      else if((pwmvalue>1400)&&(pwmvalue<1600))
        {
          digitalWrite(relayPin1, HIGH);
          digitalWrite(relayPin2, LOW);
          }
      else     
      {
          digitalWrite(relayPin1, LOW);
          digitalWrite(relayPin2, LOW);
          }
}

void pwminput()
{
  // if the pin is high, its the start of an interrupt
  if(digitalRead(pwm_pin) == HIGH)
    pwm_start = micros();
  else
    if(pwm_start)
    {
      pwmvalue = (int)(micros() - pwm_start);
      pwm_start = 0;
    }
}
