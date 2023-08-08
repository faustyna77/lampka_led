#include <Arduino.h>

#define foto A0

#define button 2
#define buttontwo 8
#define goon 9
void motorgo();
void motorback();
void przekaznik();
void przekaznikon();
  int start=millis();
  long int startup=millis();
  long int buttonpressed_start=millis();
  long int button_pressed_two=millis();
void setup()
{
  pinMode(button,INPUT_PULLUP);
  pinMode(buttontwo,INPUT_PULLUP);
  pinMode(goon,OUTPUT);
 //digitalWrite(goon,HIGH);
//attachInterrupt(digitalPinToInterrupt(2),przekaznik,FALLING);
pinMode(foto,INPUT);
//int tab[]={1,2,3,4};
for(int i=3;i<=6;i++)
{
  pinMode(i,OUTPUT);
}
Serial.begin(9600);

}

void loop()
{

  int var=analogRead(foto);
  Serial.println(var);
 //delay(2000);
  //digitalWrite(goon,HIGH);
/* if(var>=500)
 {
  motorgo();
 }
 if(var<500)
 {
  motorback();
 }
  */
/*if(digitalRead(button)==LOW)
{
  digitalWrite(goon,HIGH);
}
*/


if(digitalRead(button)==LOW)
{
 
  if(millis()-buttonpressed_start>=5000)
  {
   przekaznik();
   buttonpressed_start=millis();
  }
  
}else if(digitalRead(buttontwo)==LOW)
{
  if(millis()-button_pressed_two>=5000)
  {
   przekaznikon(); 
   button_pressed_two=millis();
  }
  
}

if(millis()-startup>=20)
{
  //delay(300);
  
   motorgo();

  
   startup=millis();
}

}

void motorgo()

{

  for( int p=0;p<100;p++)
  {

  
 for(int j=3;j<=6;j++)
 {

 
  digitalWrite(j,HIGH);
  delay(3);
  
  digitalWrite(j,LOW);
 }
  
  }

}
void motorback()
{
  for(int t=0;t<100;t++)
  {
  for(int k=6;k>=3;k--)
  {
    digitalWrite(k,HIGH);
  delay(3);
  
  digitalWrite(k,LOW);
  }
  }
}
void przekaznik()
{
  digitalWrite(goon,LOW);
  //delay(5000);
 
}
void przekaznikon()
{

   digitalWrite(goon,HIGH);
 
   
}
/*
void fall()
{
  
  digitalWrite(9,LOW);

}

void setup()
{
  pinMode(2,INPUT_PULLUP);
  pinMode(9,OUTPUT);
  //digitalWrite(7,HIGH);
  
  attachInterrupt(digitalPinToInterrupt(2),fall,FALLING);
}

void loop()
{
  digitalWrite(9,HIGH);
   delay(50000);
}

*/