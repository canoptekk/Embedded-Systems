#include "uop_msb.h"
using namespace uop_msb;
LCD_16X2_DISPLAY lcd;
// this is required to use the boards different parts

// this is how you comment

wait_us(1000000);
// waits 1 second

DigitalOut greenLED(LED1);
// setting the variable "greenLED" to affect the boards "LED1"

int main()
// The main function - all executable C / C++ applications have a main function. This is our entry point in the software
{

    while (buttons.BlueButton == 0);
    {
        // ALL this repeating code is contained in a  “while loop”
        //this makes it wait for the blue button to be pressed before repeating
        // if this was changed to "true", the loop stays active till the condition is met, in this case once true is untrue, so this will repeat forever

        // CODE STATEMENTS GO HERE

        //---------------BASIC OUTPUTS----------------------

        greenLED = 1;
        // assigning a value of 1 or "on" to greenLED
        buzz.playTone("C");
        // makes the buzzer play a C tone
        printf("Hello World\n");
        // Write to serial terminal on host PC
        lcd.printf("Hello World");
        lcd.locate(1, 0);   //Row 1, Col 0
        lcd.printf("ELEC143");
        //writes to LCD screen

        wait_us(1000000);
        // wait 1 second



        greenLED = 0;
        // assinging a value of 0 or "off" to greenLED
        buzz.rest();
        // pauses the buzzer
        lcd.cls();
        // Clear the LCD screen

        wait_us(1000000);
        // wait 1 second
    }

    // Code here can only be run once the condition is false in the loop
