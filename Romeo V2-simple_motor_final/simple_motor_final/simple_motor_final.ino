#include <Romeo_m.h>

int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M2 Direction Control

void stop(void)                    //Stop
{
  digitalWrite(E1,LOW);   
  digitalWrite(E2,LOW);      
}   
void advance(char a,char b)          //Move forward
{
  analogWrite (E1,a);      //PWM Speed Control
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}  
void back_off (char a,char b)          //Move backward
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);   
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}
void turn_L (char a,char b)             //Turn Left
{
  analogWrite (E1,a);
  digitalWrite(M1,LOW);    
  analogWrite (E2,b);    
  digitalWrite(M2,HIGH);
}
void turn_R (char a,char b)             //Turn Right
{
  analogWrite (E1,a);
  digitalWrite(M1,HIGH);    
  analogWrite (E2,b);    
  digitalWrite(M2,LOW);
}

void setup()
{ 
  int i;
  for (i=4; i <=7; i++)
  pinMode(i, OUTPUT);
  
     Romeo_m.Initialise();
     Serial.begin(115200); //Set Serial Baud
     
   
    
} 
void loop()
{ 
  char val;
  if(Serial.available()>0)
    {  
     val = Serial.read();
     }
      switch(val){

        case 'a'://Move Forward
        advance (0,100);   //move forward in max speed
        break;
        
     
      case 'b':
        stop();
        break;
        
            case 'c'://Move Forward
        advance (0,200);   //move forward in max speed
        break;

        case 'r'://Move Forward
        back_off (0,100);   //move forward in max speed
        break;
        
            default: break;

            
            }
}
