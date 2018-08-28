#include <TM1637Display.h>

const int CLK = 3; //Set the CLK pin connection to the display
const int DIO = 2; //Set the DIO pin connection to the display


int NumStep = 0;  //Variable to interate

TM1637Display display(CLK, DIO);  //set up the 4-Digit Display.

void setup()
{
  display.setBrightness(0x0a);  //set the diplay to maximum brightness
}


void loop()
{
  for(NumStep = 0; NumStep < 9999; NumStep++)  //Interrate NumStep
  {
    display.showNumberDec(NumStep); //Display the Variable value;
    delay(500);  //A half second delay between steps.
  }
}
