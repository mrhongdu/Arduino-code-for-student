// Arduino Car Parking System

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //Change the HEX address
#include <Servo.h> 

int led1 = 13;
Servo myservo;

int IR1 = 2;
int IR2 = 4;

int slot = 3;           //Enter Total number of parking Slots

void setup() 
{
lcd.init();
lcd.backlight();
pinMode(led1, OUTPUT);
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);
Serial.begin (9600);
myservo.attach(3);
myservo.write(90);
lcd.setCursor (0,0);
lcd.print("     VIET ANH    ");
lcd.setCursor (0,1);
lcd.print(" PARKING SYSTEM ");
delay (2000);
lcd.clear();
}
void loop()
{ 

Serial.print("Giá trị cảm biến ra là: ");
Serial.println(digitalRead(IR1));
Serial.print("Giá trị cảm biến vào là: ");
Serial.println(digitalRead(IR2));
delay(2000);
//Infrared 2 - Car in
if (digitalRead (IR2) == LOW)
{
  if (slot <= 3)
  {
    if (slot>0)
    {
      slot=slot-1;
      myservo.write(0);
      digitalWrite(led1,HIGH);
      lcd.setCursor (0,0);
      lcd.print("    WELCOME!    ");
      lcd.setCursor (0,1);
      lcd.print("  Slot Left: ");
      lcd.print(slot);
      delay (3000);
      myservo.write(90);
      digitalWrite(led1,LOW);
     }
    if (slot == 0)
    {
      lcd.setCursor (0,0);
      lcd.print("    SORRY :(    ");  
      lcd.setCursor (0,1);
      lcd.print("  Parking Full  "); 
      
      delay (3000);
      lcd.clear();
    }
  }

//Infrared 1 - Car out
if (digitalRead(IR1) == LOW)
{
  if (slot >= 0)
  {
    slot++;
    myservo.write(0);
    digitalWrite(led1,HIGH);
    lcd.setCursor (0,0);
    lcd.print("    GOODBYE!    ");
    lcd.setCursor (0,1);
    lcd.print("  Slot Left: ");
    lcd.print(slot);
    delay (3000);
    //lcd.clear();
    myservo.write(90);
    digitalWrite(led1,LOW);    
  }
  
}
}
}
