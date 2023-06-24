#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  //Change the HEX address
//int d_mq3 = 2;
int led1 = 12;
int led2 = 13;
int mq3;
void setup() 
{
Serial.begin (9600);
lcd.init();
lcd.begin(16, 2); 
lcd.backlight();
lcd.setCursor (0,0);
lcd.print("     VIET ANH    ");
lcd.setCursor (0,1);
lcd.print(" PARKING SYSTEM ");
delay (2000);
lcd.clear();
Serial.print(9600);
//pinMode(a_mq3, INPUT);
//pinMode(d_mq3, INPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}

void loop() 
{

  mq3 = analogRead(A0);
  delay(2000);
  if (digitalRead(2)==LOW)
  {
    digitalWrite(led1,HIGH);
    lcd.setCursor (0,0);
    lcd.print("NONG DO CON:");
    lcd.print(mq3);
    lcd.setCursor (0,1);
    lcd.print(" BAN TINH TAO ");
    delay(2000);
    lcd.clear();
    digitalWrite(led1,LOW);
  }
  else
  {
    digitalWrite(led2,HIGH);
    lcd.setCursor (0,0);
    lcd.print("NONG DO CON:");
    lcd.print(mq3);
    lcd.setCursor (0,1);
    lcd.print("   BAN DA SAY   ");
    delay(2000);
    lcd.clear();
    digitalWrite(led2,LOW);
  }
  /*if (trangthai_mq3 < 100 )
  {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }
  else
  {
    if ( trangthai_mq3 > 100 )
    {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
    }
  }*/

}
