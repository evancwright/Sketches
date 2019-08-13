/*
 *    A
 *   F B
 *    G
 *   E C
 *    D  DP
 */
#define SHORT 100
#define LONG 500
#define LETTER_SPACE 1500
#define PIN_1_SEG_E 22
#define PIN_2_SEG_D 24
 
#define PIN_4_SEG_C 28
//#define PIN_5_DP 30
#define PIN_6_SEG_B 39
#define PIN_7_SEG_A 33
//#define PIN_8_SEG_A 35
#define PIN_9_SEG_F 35
#define PIN_10_SEG_G 37
#define NUM_PINS 8
int pins[] = { PIN_1_SEG_E , PIN_2_SEG_D, PIN_4_SEG_C, PIN_6_SEG_B, PIN_7_SEG_A, PIN_9_SEG_F, PIN_10_SEG_G };
int digit=0;

void setup() {
  // put your setup code here, to run once:
  for (int i=0; i < NUM_PINS; i++)
  {
    pinMode(pins[i],OUTPUT);
  }
  
 //show2();
 allOn();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  show0();
  delay(1000);
  show1();
  delay(1000); 
  show2();
  delay(1000); 
  show3();
  delay(1000); 
  show4();
  delay(1000); 
  show5();
  delay(1000); 
  show6();
  delay(1000); 
  show7();
  delay(1000); 
  show8();
  delay(1000); 
  show9();
  delay(1000); 

}

void allOff()
{
  for (int i=0; i < NUM_PINS; i++)
  {
    digitalWrite(pins[i],LOW);
  }  
}

void allOn()
{
  for (int i=0; i < NUM_PINS; i++)
  {
    digitalWrite(pins[i],HIGH);
  }  
}
/*
 * /*
 *    A
 *   F B
 *    G
 *   E C
 *    D  DP
 *
 * #define PIN_1_SEG_E 22 
 *#define PIN_2_SEG_D 24 
 *#define PIN_4_SEG_C 26
 *#define PIN_5_DP 28
 *#define PIN_6_SEG_B 30
 *#define PIN_7_SEG_A 32
 *#define PIN_9_SEG_F 34
 */
void show0()
{
  allOff();
  digitalWrite(PIN_7_SEG_A,HIGH);
  digitalWrite(PIN_9_SEG_F,HIGH);
  digitalWrite(PIN_6_SEG_B,HIGH);
  digitalWrite(PIN_1_SEG_E,HIGH);
  digitalWrite(PIN_4_SEG_C,HIGH);
  digitalWrite(PIN_2_SEG_D,HIGH);
}

void show1()
{
  allOff();
  digitalWrite(PIN_6_SEG_B,HIGH);
  digitalWrite(PIN_4_SEG_C,HIGH);
 
}

/*
 * #define PIN_1_SEG_E 22
#define PIN_2_SEG_D 24 
#define PIN_4_SEG_C 28
#define PIN_5_DP 30
#define PIN_6_SEG_B 31
#define PIN_7_SEG_A 33
#define PIN_9_SEG_F 35
#define PIN_10_SEG_G 37
 */
void show2()
{
  allOff();
  digitalWrite(PIN_7_SEG_A,HIGH);
  digitalWrite(PIN_10_SEG_G,HIGH);
  digitalWrite(PIN_2_SEG_D,HIGH);
  digitalWrite(PIN_6_SEG_B,HIGH);
  digitalWrite(PIN_1_SEG_E,HIGH);
}

void show3()
{
  allOff();
  digitalWrite(PIN_7_SEG_A,HIGH);
  digitalWrite(PIN_6_SEG_B,HIGH);
  digitalWrite(PIN_4_SEG_C,HIGH);
  digitalWrite(PIN_2_SEG_D,HIGH);
  digitalWrite(PIN_10_SEG_G,HIGH);  
}


void show4()
{
  allOff();
  //digitalWrite(PIN_7_SEG_A,HIGH);
  digitalWrite(PIN_9_SEG_F,HIGH);
  digitalWrite(PIN_6_SEG_B,HIGH);
  //digitalWrite(PIN_1_SEG_E,HIGH);
  digitalWrite(PIN_4_SEG_C,HIGH);
  //digitalWrite(PIN_2_SEG_D,HIGH);
  digitalWrite(PIN_10_SEG_G,HIGH);  
}


void show5()
{
  allOff();
  digitalWrite(PIN_7_SEG_A,HIGH);
  digitalWrite(PIN_9_SEG_F,HIGH);
  //digitalWrite(PIN_6_SEG_B,HIGH);
  //digitalWrite(PIN_1_SEG_E,HIGH);
  digitalWrite(PIN_4_SEG_C,HIGH);
  digitalWrite(PIN_2_SEG_D,HIGH);
  digitalWrite(PIN_10_SEG_G,HIGH);  
}

void show6()
{
  allOff();
  digitalWrite(PIN_7_SEG_A,HIGH);
  digitalWrite(PIN_9_SEG_F,HIGH);
  //digitalWrite(PIN_6_SEG_B,HIGH);
  digitalWrite(PIN_1_SEG_E,HIGH);
  digitalWrite(PIN_4_SEG_C,HIGH);
  digitalWrite(PIN_2_SEG_D,HIGH);
  digitalWrite(PIN_10_SEG_G,HIGH);  
}

void show7()
{
  allOff();
  digitalWrite(PIN_7_SEG_A,HIGH);
  //digitalWrite(PIN_9_SEG_F,HIGH);
  digitalWrite(PIN_6_SEG_B,HIGH);
  //digitalWrite(PIN_1_SEG_E,HIGH);
  digitalWrite(PIN_4_SEG_C,HIGH);
  //digitalWrite(PIN_2_SEG_D,HIGH);
  //digitalWrite(PIN_10_SEG_G,HIGH);  
}

void show8()
{
  allOn();
  
}

void show9()
{
  allOff();
  digitalWrite(PIN_7_SEG_A,HIGH);
  digitalWrite(PIN_9_SEG_F,HIGH);
  digitalWrite(PIN_6_SEG_B,HIGH);
  //digitalWrite(PIN_1_SEG_E,HIGH);
  digitalWrite(PIN_4_SEG_C,HIGH);
  digitalWrite(PIN_2_SEG_D,HIGH);
  digitalWrite(PIN_10_SEG_G,HIGH);  
}
