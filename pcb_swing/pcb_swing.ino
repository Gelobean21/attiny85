#include <SoftwareServo.h> 
SoftwareServo myservo;

#define ledl 3
#define ledr 1
#define servopin 0
#define anglepin A1 
#define speedpin A2

void setup() {
  myservo.attach(0);
  pinMode(ledl, OUTPUT);
  pinMode(ledr, OUTPUT);

  digitalWrite(ledl, LOW);
  digitalWrite(ledr, LOW);
}

void loop() {
int i = 0;
int angle = (analogRead(anglepin) / 50);
int yaled = analogRead(speedpin) * 2;

for(i = 0 ; i < angle; i++)
{
  myservo.write(i);
  delay(15);
}
SoftwareServo::refresh();
digitalWrite(ledl, HIGH);
digitalWrite(ledr, LOW);
delay(yaled);

for(i = angle ; i > 0 ; i--)
{
 myservo.write(i);
 delay(15);
}
SoftwareServo::refresh();
digitalWrite(ledl, LOW);
digitalWrite(ledr, HIGH);
delay(yaled);
}
