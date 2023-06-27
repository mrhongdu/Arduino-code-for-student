#include <Servo.h>

Servo myservo;

int pos = 0;

const int buzzerPin = 6;
const int ledPin = 13;
const int servoPin = 9;
const int inPin = 5;
int currentState = LOW;

int delaytime = 3000;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
pinMode(buzzerPin, OUTPUT);
pinMode(ledPin, OUTPUT);
digitalWrite(servoPin, LOW);
digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentState=digitalRead(inPin);
  if (currentState == HIGH) {
    
for (int a = 0; a <5; a++){
  for (pos = 120; pos < 180; pos += 20)
  {
    myservo.write(pos);
    delay(1000);
  }
}


for (pos = 180; pos>=1; pos -= 180)

{ myservo.write(pos);
delay(3000); }

for (int a=0; a<5; a++){
  { analogWrite(buzzerPin, 200);
  digitalWrite(ledPin, HIGH);
  delay(delaytime);
  digitalWrite(buzzerPin, LOW);
   digitalWrite(ledPin, LOW);
   delay(1000);
   delaytime= delaytime - 500;
  }
}
for (pos=0; pos< 180; pos += 90)

myservo.write(pos);

}}
