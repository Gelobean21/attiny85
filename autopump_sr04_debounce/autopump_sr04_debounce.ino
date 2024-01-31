#include <MyButton.h>

byte pumpvcc = 3;
const int trigPin = 4;
const int echoPin = 2;
//byte pumptogglepin = 0;
//byte autotogglepin = 1;

bool option_forcepump = 0;
bool option_autopump = 1;

unsigned long previousmillis = 0;
const long period = 5000;

MyButton p(0,1,0,60);
MyButton a(1,1,0,60);

void setup(){
pinMode(pumpvcc, OUTPUT);
digitalWrite(pumpvcc, LOW);
}

void loop(){

unsigned long currentmillis = millis();

if(p.isClicked()){
option_forcepump = !option_forcepump;
}

if(a.isClicked()){
option_autopump = !option_autopump;
}

if(option_forcepump){
 digitalWrite(pumpvcc, HIGH);
 option_autopump = 0;
}
else{
 if(!option_autopump){
  digitalWrite(pumpvcc, LOW);
 }
}

if(option_autopump){
 option_forcepump = 0;
 
 long duration, inches, cm;
 pinMode(trigPin, OUTPUT);
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 pinMode(echoPin, INPUT);
 duration = pulseIn(echoPin, HIGH);
 inches = microsecondsToInches(duration);
 cm = microsecondsToCentimeters(duration);
 if(cm < 15){
  digitalWrite(pumpvcc, HIGH);
 }
 else{
  digitalWrite(pumpvcc, LOW);
 }

 delay(10000);
}
}

long microsecondsToInches(long microseconds){
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
