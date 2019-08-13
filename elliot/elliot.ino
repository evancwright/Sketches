
#define SHORT 100
#define LONG 500
#define LETTER_SPACE 1500
 
 void setup() {
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(3000); 
  e();
  NextLetter();
  l();
  NextLetter();
  l();
  NextLetter();
  i();
  NextLetter();
  o();
  NextLetter();
  t();
  NextLetter();
  NextLetter();
  NextLetter();
}

void NextLetter()
{
  delay(LETTER_SPACE);
}

void e()
{
  Short();
}

void i()
{
  Short();
  Short();
}

void o()
{
  Long();
  Long();
  Long();
}

void t()
{
  Long();
}


void l()
{
  Short();
  Long();
  Short();
  Short();
}


void Short()
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(SHORT);
  digitalWrite(LED_BUILTIN,LOW);
  delay(200);
}

void Long()
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(LONG);
  digitalWrite(LED_BUILTIN,LOW);
  delay(200);
}
