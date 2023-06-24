#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
int cambien = 2;// khai bÃ¡o chÃ¢n digital 2 cho cáº£m biáº¿n
int Led = 6;//khÃ¡o bÃ¡o chÃ¢n digital 6 cho Ä‘Ã¨n LED

#include <DHT.h>
#define MB 3
#define DA A0
#define DHT11Pin 2
#define DHTType DHT11
DHT HT(DHT11Pin,DHTType);

float humi;
int tempC;

void setup()
{
  Serial.begin(9600);
  pinMode(Led,OUTPUT);//pinMode xuáº¥t tÃ­n hiá»‡u Ä‘áº§u ra cho led
  pinMode(cambien,INPUT);//pinMode nháº­n tÃ­n hiá»‡u Ä‘áº§u vÃ o cho cáº£m biÃªn
  lcd.init();
  lcd.begin(20,4);
  lcd.backlight();
  lcd.print("VIET ANH");
  lcd.setCursor(0,1);
  lcd.print("Xin chao cac ban");
  
  pinMode(MB, OUTPUT);
  pinMode(DA,INPUT);
  digitalWrite(MB, LOW);

  HT.begin();

  delay(2000);
}
void loop()
{
  int value = digitalRead(cambien);//lÆ°u giÃ¡ trá»‹ cáº£m biáº¿n vÃ o biáº¿n value
  digitalWrite(Led,value);//xuáº¥t giÃ¡ trá»‹ ra Ä‘Ã¨n LED

  int analog = analogRead(DA);
  int phantramao = map(analog, 0 , 1023, 0, 100);
  int phantramthuc = 100 - phantramao;

  humi = HT.readHumidity();
  tempC = HT.readTemperature();
  
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("CHI SO MOI TRUONG");
  lcd.setCursor(0,1);
  lcd.print("DO AM DAT: ");
  lcd.print(phantramthuc);
  lcd.print("%");
  lcd.setCursor(0,2);
  lcd.print("DO AM KK: ");
  lcd.print(humi,0);lcd.print("%");
  lcd.setCursor(0,3);
  lcd.print("NHIET DO KK: ");lcd.print(tempC);lcd.print("oC");

  if ( phantramthuc < 50 && tempC < 35 && humi < 50 )
  {
    digitalWrite(MB,HIGH);
  }
  else 
  {
    digitalWrite(MB,LOW);
  }
  delay(2000);
}
