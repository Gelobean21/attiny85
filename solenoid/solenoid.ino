#include <MyButton.h>

#define solenoid 2
#define indicator 3
#define reedState 1
#define reed 4

bool isLocked = true;
unsigned long startmillis;
unsigned long currentmillis;
const unsigned long duration = 10000;
bool isGettingHot = true;

MyButton switchButton(0,0,1,60);

void setup() 
{
  pinMode(reed, INPUT_PULLUP);
  pinMode(indicator, OUTPUT);
  pinMode(solenoid, OUTPUT);
  pinMode(reedState, OUTPUT);
    
  digitalWrite(indicator,HIGH);
  digitalWrite(solenoid, LOW);
}

void loop() 
{
 if(digitalRead(reed) == LOW)
 {
   digitalWrite(reedState,LOW);
  if(switchButton.isClicked())
  {
   if(isLocked == false)
   {
    enableLock();
   }
   else
   { 
    disableLock();  //getting hotter if not enabled
   }
  }
 }
 else
 {
  delay(1000);
  digitalWrite(reedState, HIGH);
  enableLock();
 }
 
 if(isGettingHot == true)
 {
    currentmillis = millis();
    if(currentmillis - startmillis >= duration){
      enableLock();
      startmillis = currentmillis;
   }
 }
 
}

void disableLock(){
  digitalWrite(solenoid, HIGH);
  digitalWrite(indicator,LOW);
  delay(500);
  isLocked = false;
  isGettingHot = true;
  startmillis = millis();
}

void enableLock(){
  digitalWrite(solenoid, LOW);
  digitalWrite(indicator,HIGH);
  delay(500);
  isLocked = true;
  isGettingHot = false;
}
