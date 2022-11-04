#include "uop_msb.h"
#include <chrono>
#include <cstdint>
using namespace uop_msb;
using namespace chrono;
using namespace uop_msb;
LCD_16X2_DISPLAY lcd;
#define WAIT_TIME_MS 1000 
// this is required to use the boards different parts

// this is how you comment

/*
this is how you make a longer comment
 */


wait_us(1000000);
// waits 1 second

DigitalOut greenLED(LED1);
// setting the variable "greenLED" to affect the boards "LED1"
DigitalOut led2(LED2);
DigitalOut led3(LED3);
//setting other leds to be used via the variables led2 and led3

BusOut lights(PC_2, PC_3, PC_6);
//BusOut lights, using multiple outputs at once

//PortOut lights(PortC, 0b0000000001001100);
//this would use the same lights as the Bus out
//the difference being, between the outputs of Busout there is the smallest delay, with Port out the switch is perfectly simultanious

LatchedLED ledDisp(LatchedLED::STRIP);
//for the led strips to output


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

        char c1;
        //setting the variable as a char, can instead be int for number inputs or other variable types
        printf("\n\nPress a key\n");
        //prompt
        c1 = getchar();
        //getting the input in
        printf("You entered character %c which has the ASCII code %d\n", c1, c1);
        //terminal input displayed
        DigitalIn sw1(D3);
        //allows you to get switch information from D3, under the variable sw1
        DigitalIn sw2(D4);
        //allows you to get switch information from D4, under the variable sw2
        DigitalIn ButtonA(PG_0); //Button A
        DigitalIn ButtonB(PG_1); //Button B
        
        AnalogIn pot(AN_POT_PIN);
        //sets a potentiometer input through the pot variable
        AnalogIn ldr(AN_LDR_PIN);
        //sets a LDR input through the ldr variable from the LDrs pin
        AnalogIn mic(MIC_AN_PIN);
        //set a microphone input into mic variable
        unsigned short potVal   = pot.read_u16();
        unsigned short lightVal = ldr.read_u16();
        unsigned short micVal   = mic.read_u16(); 
        //Read Analog to Digital Converter values (16 bit)

        
        BusIn switches(D3,D4);
        //same principle as bus out but for inputs, 


        Timer tmr;
    
            tmr.reset();
            tmr.start();
            while (tmr.elapsed_time() < 250ms);
            tmr.stop();
        //timer code

        //sleep();
        //stops the code till a hardware interupt, so an input
        //or a hardware timer
        InterruptIn btnA(BTN1_PIN);//sets up an interrupt into the code
        InterruptIn btnB(BTN2_PIN);
        Ticker tick;



        flushInputBuffer();
        //Clear out the serial port (keyboard)





        //---------------BASIC OUTPUTS----------------------

        DigitalOut greenLED(LED1);
        // setting the variable "greenLED" to affect the boards "LED1"
        DigitalOut led2(LED2);
        DigitalOut led3(LED3);
        //setting other leds to be used via the variables led2 and led3

        //Dual Digit 7-segment Display
        LatchedLED disp(LatchedLED::SEVEN_SEG);
        //Turn ON the 7-segment display
         disp.enable(true);
        //Update display
           disp = count;

        BusOut lights(PC_2, PC_3, PC_6);
        //BusOut lights, using multiple outputs at once

        //PortOut lights(PortC, 0b0000000001001100);
        //this would use the same lights as the Bus out
        //the difference being, between the outputs of Busout there is the smallest delay, with Port out the switch is perfectly simultanious

        int count = 0;
            while (count <= 7) 
            {
                printf("count = %d\n", count);
                lights = count;
                wait_us(1000000);

                count = count + 1;
            }
        //binary busout output
        //this counts up in binary across the three outputs it has

        /*
        lights = 0;

        while (true)
        {
            lights = 0b0000000000000100;
            wait_us(1000000);
            lights = 0b0000000000001000;
            wait_us(1000000);
            lights = 0b0000000001000000;
            wait_us(1000000);                
        }
        */
        //this is the same as the bus out, however using the port out function instead
        //this will switch between each light in succession instead.



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
        printf("You \n");
        //prints to the terminal


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


    //Test LED Bar Display
    ledDisp.enable(true);

    ledDisp.setGroup(LatchedLED::LEDGROUP::RED);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;

    ledDisp.setGroup(LatchedLED::LEDGROUP::GREEN);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }
    ledDisp = 0;
    
    ledDisp.setGroup(LatchedLED::LEDGROUP::BLUE);
    for (unsigned int n=0; n<8; n++) {
        ledDisp = 1 << n;
        wait_us(250000);
    }     
    ledDisp = 0;
    //for the led strips to go up, one lne at a time

    
        //-------------------------------variables --------------------------------------

        int count = 0;
        printf("count = %d\n", count);
        // Integer

        volatile int counte = 0;
        //It tells the compiler that the value of the variable may change at any time-without any action being taken by the code the compiler finds nearby

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

        //variables can overflow and go from the highest to the lowest value


        count++ ;
        //increments count by 1, used in loops a lot  

        //Size of a char is 1 bytes
        //Size of a short is 2 bytes
        //Size of a int is 4 bytes
        //Size of a long is 4 bytes
        //Size of a long long is 8 bytes
        //Size of a float is 4 bytes
        //Size of a double is 8 bytes


        // + - / * (% modulus) are all operators on variables
        //a&b = bitwise and (1011 & 1001 = 1001)
        //a|b = bitwise or (1011 | 1001 = 1011)
        //a^b = bitwise xor (1011 ^ 1001 = 0010)
        //a<<b = left shift (00110101 << 1 = 01101010)
        //a>>b = right shift (10110001 >> 1 = 01011000)
        // ~a = not a (~1011 = 0100)

        unsigned char ucbyte = 0b10100011;
        ucbyte ^= 0b01000000; //toggle pin 7 using Xor



        //-------------------------------Loop types--------------------------

        count++ ;
        //increments count by 1, used in loops a lot, -- works to increment down

        /*

        to preface this section, ive put the boolean operators here, which are used within the expressions for the loops

        // == equal
        // != not equal
        // < less than
        // <= less than or equal to
        // > greater than
        // >= greater than or equal to

        // && conditional and 
        // || conditional or
        // ! conditional not


        // expressions can have multiple conditionals

        //for example if (_____) && (_____) &&...
        //bodmas order for these is ! , &&, then ||, use extra brackets to sort order if nessisary

        */



        /*

        while(condition to meet)
        {
            execute bracketed code
        }

        //an example of a while loop, checks a condition is met and repeats until the condition is broken
        //it is very easy to make an infinite loop if there is no way of breaking the orginial condition, or no out clause

        */




        /*
        do {

        //code block
        
        }while (expression);

        //the do while loop executes once, and then repeats while the the expression is true 

        */



        /*
        
        int ___; // variable used in for loop

        for(initialisation statement, condition for entry, preform after every loop){
        
        //a common example for the expressions inside is (n=0; n<10; n++)
        // n starts at 0, the loop repeats if n is less than 10, and after each loop is incremented by one

        }
        */
        

        /*
        if(condition){

            //code block

        }

        //runs code through once, if the condition is met initially
        //commonly nested within other loops

        
        */




        /*
        if(condition){

            //code block

        }
        else
        {

            //code block

        }

        //runs the primary if statement as long as conditions are met, if not, runs through else clause, both are exclusive

        */



    
        /*
        if(condition){

            //code block

        }
        else if (condition 2)
        {

            //code block

        }
        else
        {

            //code block

        }

        //else if is used to give if else extra conditions, however only one block of code will be run
        
        */

        /*
        
        switch(expression)
        {

            declarations

        case 0:
        
            //code here

            break; 

        case 1:

            //code here

            break;

        case 2:

            //code here

            break;

        case 3

            //code here

            break;

        };

        //break used to make sure that it doesnt repeat and go through the other cases after.
        //used best in multiple choice scenarios
        //case refers to expressions value
        */

        //if, while, do and for can all be nested into other loops

        //break;
        //break; breaks the current loop and continues the code from after the code
        //continue;
        //contunue; will go to the end of the loop prematurely 





    }

    // Code here can only be run once the condition is false in the loop