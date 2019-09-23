#include <TimerOne.h>

#define SEG_A 11
#define SEG_B 7
#define SEG_C 4
#define SEG_D 2 
#define SEG_E 1
#define SEG_F 10
#define SEG_G 5
#define SEG_DP 3

#define LED1_SELECT 12
#define LED2_SELECT 9
#define LED3_SELECT 8
#define LED4_SELECT 6

int bits[4] = { 1,0,1,1 };
int segPins[8] = { 11,7,4,2,1,10,5,3 };
int ledSelectPins[4] = { LED4_SELECT, LED3_SELECT, LED2_SELECT, LED1_SELECT };

void setup() {
  // put your setup code here, to run once:
  
  for (int i=0; i <= 12; i++)
  {
    pinMode(i, OUTPUT);
  } 

  Timer1.initialize(1000000);
  Timer1.attachInterrupt(increment);
}

void loop() {
//  allOff();
//  carry(0);
  showNumber();
  //delay(500);
}

void increment()
{
  carry(0);
}

void carry(int position)
{
  if (position == 4) return;
  
  bits[position]++;

  if (bits[position] == 2)
  {
    bits[position] = 0;
    carry(++position);
  } 
}


//sets the LED to write to
void selectLED(int ledPin)
{
  //turn off all select pins
  for (int i=0; i < 4; i++)
    digitalWrite(ledSelectPins[i],HIGH);

  //turn on LED to write to
    digitalWrite(ledPin,LOW);     
}

//turns off all segments of currrently selected LED
void allOff()
{
   for (int i=0; i < 8; i++)
    digitalWrite(segPins[i],LOW);
}

void allOn()
{
   for (int i=0; i < 8; i++)
    digitalWrite(segPins[i],HIGH);
}


//draws a zero to the currently selected LED
void draw0()
{
  allOff();
  digitalWrite(SEG_A,HIGH);
  digitalWrite(SEG_B,HIGH);
  digitalWrite(SEG_C,HIGH);
  digitalWrite(SEG_D,HIGH);
  digitalWrite(SEG_E,HIGH);
  digitalWrite(SEG_F,HIGH);

}

void draw1()
{
  allOff();
  digitalWrite(SEG_B,HIGH);
  digitalWrite(SEG_C,HIGH);
}

void showNumber()
{
  
  for (int i=0; i < 4; i++)
  //int i=3;
  {
      allOff();
      selectLED( ledSelectPins[i] );
      
       if (bits[i] == 0) 
          draw0();
       else 
          draw1();
  }
}
