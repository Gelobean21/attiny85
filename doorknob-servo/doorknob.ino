#include <SoftwareServo.h> 
#include <avr/io.h>

SoftwareServo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 

int pos = 0;    // variable to store the servo position 
int saan = 0;
int pin1 = 1;
int pin2 = 2;
int reed = 4;
int indicator = 3;

void setup() 
{ 
  myservo.attach(0);  // attaches the servo on pin 1 to the servo object 
  pinMode(pin1,INPUT);
  pinMode(pin2,OUTPUT);
  pinMode(reed, INPUT);
  pinMode(indicator,OUTPUT);
  
  MCUCR = 0b01000000;
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(reed, HIGH);
  digitalWrite(indicator,LOW);
} 

void loop() 
{
  if(digitalRead(reed) == LOW){
  if(digitalRead(pin1) == HIGH || digitalRead(pin2) == HIGH){
    if(saan == 0){
      for(pos = 0; pos < 70; pos += 3)  // goes from 0 degrees to 180 degrees 
        {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        digitalWrite(indicator,LOW);
        delay(15);                       // waits 15ms for the servo to reach the position 
        SoftwareServo::refresh();
      }
      saan = 1;
    }
    else{ 
      for(pos = 70; pos>=1; pos-=3)     // goes from 180 degrees to 0 degrees 
      {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        digitalWrite(indicator,HIGH);
        delay(15);                       // waits 15ms for the servo to reach the position 
        SoftwareServo::refresh();
      }
      saan = 0;
    }
  }
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  }
}
