
#include <LiquidCrystal.h>
#include <LCDKeypad.h>

#define UNUSED_ANALOG_PIN 7

byte c_arrow[8] = {
  B00000,
  B00000,
  B00000,
  B00100,
  B00010,
  B11111,
  B00010,
  B00100,
};

LCDKeypad lcd;
char buffer[40];

class Room
{
  public:
  
  int number;
  int neighbors[3];
  bool bat;
  bool pit;
  bool wumpus;
 
  Room() { Reset(); }

  void Reset() { bat=0; pit =0; wumpus =0; } 
    
  void SetNeighbors(int n1, int n2, int n3)
  {
    neighbors[0] = n1; neighbors[1]=n2; neighbors[2]=n3;
  }
};

Room rooms[21];
int currentRoom  = 1;



void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(UNUSED_ANALOG_PIN));
  
 // lcd.createChar(1,c_arrow);
  lcd.begin(16, 2);
  // put your setup code here, to run once:
  SetupCaves();
  PlaceHazards();
  
}

void loop() {
  
  // put your main code here, to run repeatedly:
  PrintRoom();
  delay(100);
  
  lcd.setCursor(0,1);
  lcd.print("L=Move R=Shoot"); 
  
  int buttonPressed=0;
  do
  {
    buttonPressed=waitButton();
  }
  while(!(buttonPressed==KEYPAD_LEFT || buttonPressed==KEYPAD_RIGHT));
  
  int ms = buttonPressed;
  //ask the player for the room
  print((char*)"Which room?");
  sprintf(buffer,"%d %d %d?", 
    rooms[currentRoom].neighbors[0],
    rooms[currentRoom].neighbors[1],
    rooms[currentRoom].neighbors[2]);
  lcd.setCursor(0,1);  
  lcd.print(buffer);

  do
  {
    buttonPressed=waitButton();
  }
  while(!(buttonPressed==KEYPAD_LEFT || buttonPressed==KEYPAD_UP || buttonPressed==KEYPAD_RIGHT));

  int newRoom = 0;
  if (buttonPressed == KEYPAD_LEFT) newRoom = rooms[currentRoom].neighbors[0];
  else if (buttonPressed == KEYPAD_UP) newRoom = rooms[currentRoom].neighbors[1];
  else newRoom = rooms[currentRoom].neighbors[2];

  if (ms == KEYPAD_LEFT)
    Move(newRoom);
  else if (ms == KEYPAD_RIGHT)
    Shoot(newRoom);
 
}

void SetNeighbors(int r, int n1, int n2, int n3)
{
    rooms[r].SetNeighbors(n1,n2,n3);
}

void SetupCaves()
{
        SetNeighbors(1, 2, 5, 8);
        SetNeighbors(2, 1, 3, 10);
        SetNeighbors(3, 2, 4, 12);
        SetNeighbors(4, 3, 5, 14);
        SetNeighbors(5, 1, 4, 6);
        SetNeighbors(6, 5, 7, 15);
        SetNeighbors(7, 6, 8, 17);
        SetNeighbors(8, 1, 7, 9);
        SetNeighbors(9, 8, 10, 18);
        SetNeighbors(10, 2, 9, 11);
        SetNeighbors(11, 10, 12, 19);
        SetNeighbors(12, 3, 11, 13);
        SetNeighbors(13, 12, 14, 20);
        SetNeighbors(14, 4, 13, 15);
        SetNeighbors(15, 6, 14, 16);
        SetNeighbors(16, 15, 17, 20);
        SetNeighbors(17,7,16,18);
        SetNeighbors(18, 9, 17, 19);
        SetNeighbors(19, 11, 18, 20);
        SetNeighbors(20, 13, 16, 19);  
}

void ClearCaves()
{
  for (int i=0; i < 21; i++) rooms[i].Reset();
}

void PlaceHazards()
{
  ClearCaves();
  
  //place 1st bat
  int r = random(1,21);
  rooms[r].bat = true;        
  
  //place 2nd bat
  r = random(1,21);
  while (rooms[r].bat == true)
  {
    r = random(1,21);
  }
  rooms[r].bat = true;        

  //place 1st pit
  r = random(1,21);
  rooms[r].pit = true;        
    
  while (rooms[r].bat == true)
  {
    r = random(1,21);
  }
  rooms[r].pit = true;        

  //place wumpus
  r = random(1,21);
  rooms[r].wumpus = true;        

  //place player somewhere safe
   r = random(1,21);
   while (rooms[r].bat == true || rooms[r].pit == true || rooms[r].wumpus == true)
    {
     r = random(1,21);
    }
   currentRoom = r;  
}

void Move(int newRoom)
{
    //TODO Complete this function using the flowchart
    //in the PDF
    currentRoom = newRoom;

    if (rooms[currentRoom].wumpus)
    {
        lcd.clear();
        lcd.print("WUMPUS!");
        delay(1000);
        lcd.setCursor(0,1);
        lcd.print("***YOU DIED***");
        //losses++;
        delay(1000);
        PlayAgain();
        
    }
    else if (rooms[currentRoom].pit)
    {
        lcd.clear();
        for(int i=0; i < 17; i++)
        {
          lcd.write("A");  
          lcd.setCursor(i,0);
          delay(100);
        }
        
        delay(1000);
        lcd.setCursor(4,1);
        lcd.print("*THUD*");
        delay(1000);
        //losses++;
        PlayAgain();
    }
    else if (rooms[currentRoom].bat)
    {
        lcd.clear();
        lcd.print("*FLAP*FLAP*FLAP*");
        delay(1000);
        int n = random(1, 21);
        Move(n);
    }
}

void Shoot(int r)
{
    //TODO Complete this function based on the flowchart in the PDF
    lcd.clear();

  //  lcd.write(1);
    lcd.write("->");
    for (int k=0;k<16;k++)
    {
      lcd.scrollDisplayRight();
      delay(100);
    }
    
    delay(1000);
    if (rooms[r].wumpus)
    {
        lcd.clear();
        lcd.print("Thwack!");
        delay(1000);
        lcd.setCursor(8,0);
        lcd.print("Thud!");
        delay(1000);
        lcd.setCursor(1,1);
        lcd.print("WUMPUS SLAIN!!!");
        delay(3000);
        PlayAgain();
        //wins++;
    }
    else
    {
        lcd.clear();
        lcd.setCursor(2,0);
        lcd.print((char*)"YOU MISSED!");

        //pick a random neighbor
        int newWumpRoom = random(3);
        int oldWumpusRoom = findWumpus();
        newWumpRoom = rooms[oldWumpusRoom].neighbors[newWumpRoom];

        rooms[oldWumpusRoom].wumpus = 0; //remove wumpus from old room
        rooms[newWumpRoom].wumpus = 1; //put wumpus in new room
        
        if (newWumpRoom == currentRoom)
        {
          lcd.clear();
          lcd.print("*GROWL*");
          delay(1000);
          lcd.setCursor(4,1);
          lcd.print("*GULP*");
          delay(1000);
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print((char*)"YOU'VE HAVE DIED");
          delay(2000);
          PlayAgain();
        }
        else
        {
          lcd.setCursor(0,1);
          lcd.print((char*)"WUMPUS HAS MOVED");
          delay(2000);
        }
        
        //losses++;
    }


}

void PrintRoom()
{
  sprintf(buffer,"%d: %d %d %d", currentRoom,rooms[currentRoom].neighbors[0],
    rooms[currentRoom].neighbors[1],
    rooms[currentRoom].neighbors[2]);

  if (HearBats())
    strcat(buffer, "B ");
  if (FeelDraft())
    strcat(buffer, "P ");
  if (SmellWumpus())
    strcat(buffer, "W!");
  print(buffer);  
}

bool HearBats()
{
  int n1 = rooms[currentRoom].neighbors[0];
  int n2 = rooms[currentRoom].neighbors[1];
  int n3 = rooms[currentRoom].neighbors[2];
  return (rooms[n1].bat || rooms[n2].bat || rooms[n3].bat);
}

bool FeelDraft()
{
  int n1 = rooms[currentRoom].neighbors[0];
  int n2 = rooms[currentRoom].neighbors[1];
  int n3 = rooms[currentRoom].neighbors[2];
  return (rooms[n1].pit || rooms[n2].pit || rooms[n3].pit);
}

bool SmellWumpus()
{
  int n1 = rooms[currentRoom].neighbors[0];
  int n2 = rooms[currentRoom].neighbors[1];
  int n3 = rooms[currentRoom].neighbors[2];
  return (rooms[n1].wumpus || rooms[n2].wumpus || rooms[n3].wumpus);
}

void PlayAgain()
{
  PlaceHazards();
  PrintRoom();
}

//copied from Guess the number
int waitButton()
{
  int buttonPressed; 
  waitReleaseButton();
  lcd.blink();
  while((buttonPressed=lcd.button())==KEYPAD_NONE)
  {
  }
  delay(50);  
  lcd.noBlink();
  return buttonPressed;
}

//copied from Guess the number
void waitReleaseButton()
{
  delay(50);
  while(lcd.button()!=KEYPAD_NONE)
  {
  }
  delay(50);
}

void print(char *msg)
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(msg);
}

//returns the room the wumpus is in
int findWumpus()
{
  for (int i=0; i < 21; i++)
  {
    if (rooms[i].wumpus == 1)
      return i;
  }
  return 0;
}
