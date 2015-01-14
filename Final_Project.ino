/*
ALlison Smith Final Project: Maze Game
Description: A series of mazes that increase difficultly by level. There are a total of three levels. 
WARNING: THERE IS A INVISIBLE LEVEL
How to Play: Use the up, down, left, and right buttons to guide the green dot to the aqua dot to advance to the next level.

*/

#include <MeggyJrSimple.h>    // Required code, line 1 of 2.

//declare variables for x coord of a single light

int xdot=0;
int ydot=0;
int level=1;

void setup()                    // run once, when the sketch starts
{

  MeggyJrSimpleSetup();      // Required code, line 2 of 2.

}  // End setup()

void loop()                     // run over and over again
{   

  ClearSlate();
  // check what level youre on and draw that level to the slate 
  if (level==1)
Drawlevel1();
 
 if (level==2)  //code for moving on to level 2
Drawlevel2();

if (level==3)  //code for making level 3
Drawlevel3();

if (level==4)
Drawlevel4(); //code for making level 4


  CheckButtonsPress();   //Check to see which buttons are down that weren't before.


  if (Button_Up)  //moving dot code
   {
     ydot = ydot + 1;
   if (ydot > 7)  //THIS MAKES THE DOT WRAP BUT ONLY FOR LEVEL 3
   {
     if (level==3)
   ydot = 0;
   else
   ydot = 7;
   }
   }


  if (Button_Down)    //THIS MAKES THE DOT WRAP BUT ONLY FOR LEVEL 3
  {
    ydot = ydot - 1;
    if (ydot < 0)
    {
      if(level==3)
   ydot = 7;
   else
   ydot = 0;
    }
  }


  if (Button_Right)
{  
   xdot = xdot + 1; //THIS MAKES THE DOT WRAP BUT ONLY FOR LEVEL 3
   if (xdot > 7)
   {
      if(level==3)
   xdot = 0;
   else
   xdot = 7;
   }
}

  if (Button_Left) 
{  
 xdot = xdot - 1;  //THIS MAKES THE DOT WRAP BUT ONLY FOR LEVEL 3
if (xdot < 0)
{
      if(level==3)
   xdot = 7;
   else
   xdot = 0;
}
}
   
 //check if wall collision if so move the player back to start
 //For level 1 and 3
if (ReadPx(xdot,ydot) == Violet)  //code for not going through the walls
  {
    xdot = 0;
    ydot = 0;
  }
  
  //For level 2
if (level == 2) 
{
 
  if (ReadPx(xdot,ydot) == 16)  //code for not going through the walls
  {
    xdot = 3;
    ydot = 0;
  }
  
}
  

 
 // code to check the if the goal is reached on level 1..if yes then move to level 2
if (xdot==7 && ydot== 7 && level==1)
{
Drawlevel2(); //draw level 2
level=2;//now level value is 2

xdot=3; //where dot beings
ydot=0;
}

 // code to check the if the goal is reached on level 2...if yes then move to level 3
if (xdot==2 && ydot== 7 && level==2)
{
  Drawlevel3(); //draw level 3
level=3;//now level value is 3
xdot=1; //where dot begins
ydot=0;
}

if (xdot==5 && ydot==7 && level==3)
{
Drawlevel4(); //draw level 4
level=4; //now level value is 4
xdot=0; //where dot begins
ydot=0;
}

DrawPx(xdot,ydot,Green); //the dot
 
DisplaySlate(); // Write the updated game buffer to the screen.
delay(150); // Wait 

 
}//end of main loop


 
