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


        //---------------BASIC INPUTS




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
        //this could also be achieved with greenLED = !greenLED;
        buzz.rest();
        // pauses the buzzer
        lcd.cls();
        // Clear the LCD screen

        wait_us(1000000);
        // wait 1 second


        //-------------------------------variables --------------------------------------

        int count = 0;
        printf("count = %d\n", count);
        // Integer

        count = count + 1;
        printf("New value of count = %d\n", count);
        // Add one to count

        char character;
        character = 'A';
        printf("The character %c has the ASCII code %d\n", character, character);
        // Char, stores a single character such as ‘a’, ‘Z’, ‘@’ etc. including number, symbol or special character. It takes 1 byte (8-bits) to store each character

        short shortCount = 32766;
        printf("The value of shortCount is %hd\n", shortCount);
        shortCount = shortCount + 1;
        printf("add 1 and shortCount is %hd\n", shortCount);
        // Short, limits user to store small integer values from -32768 to 32767

        long long NN = 0x12345678ABCD0001LL; //Literal in HEX
        printf("A very large number %lld\n", NN);
        printf("A very large number in hex %llX\n", NN);
        //long long, holds very long numbers, It allows user to stores very large number (something like 9 Million Trillion)

        unsigned short p = 1; //16 bit
        printf("unsigned int p = %u\n", p);
        p = p - 2;
        printf("Subtract 2. Now unsigned int p = %u\n", p);
        //unsigned When user intends to store only positive values in the given data type (int and char)

        signed int myNegativeIntegerValue = -544
        //signed It is default modifier of int and char data type if no modifier is specified. It says that user can store negative and positive values

        float pi_float = 3.1415926536;
        printf("The value of pi is approximately %f\n", pi_float);
        //float It stores real numbers with precision upto 6 decimal places. It takes 4 bytes of memory and is also known as floating point number

        double pi_double = 3.1415926536l;
        printf("The value of pi is approximately %lf\n", pi_double);
        //It stores real numbers with precision upto 15 decimal places. It takes 8 bytes of memory


        //Size of a char is 1 bytes
        //Size of a short is 2 bytes
        //Size of a int is 4 bytes
        //Size of a long is 4 bytes
        //Size of a long long is 8 bytes
        //Size of a float is 4 bytes
        //Size of a double is 8 bytes




    }

    // Code here can only be run once the condition is false in the loop
