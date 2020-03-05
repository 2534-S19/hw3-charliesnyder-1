/*
 * GPIO.c
 *
 *  Created on: 3/4/2020
 *      Author: Charlie Snyder
 */

// For the code you place here, you may use your code that uses register references.
// However, I encourage you to start using the Driver Library as soon as possible.

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myGPIO.h"


#define LEFT_BUTTON BIT1
#define RIGHT_BUTTON BIT4

#define LAUNCH_RED_LED BIT0
#define LAUNCH_GREEN_LED BIT1
#define LAUNCH_BLUE_LED BIT2

#define TOP_BUTTON BIT1
#define BOTTOM_BUTTON BIT5

#define LEFT_LED BIT0

#define RED_LED BIT6
#define GREEN_LED BIT4
#define BLUE_LED BIT6

// TODO: Create a function to initialize the GPIO.
// Even though this assignment does not use all of the pushbuttons, you should write one function that does a complete GPIO init.
void initGPIO()
{
    // Launchpad S1

    // Launchpad S2

    // Boosterpack S1

    // Boosterpack S2

    // Launchpad LED1

    // Launchpad LED2 Red

    // Launchpad LED2 Green

    // Launchpad LED2 Blue

    // Boosterpack LED Red

    // Boosterpack LED Green

    // Boosterpack LED Blue


    // Turn off all LEDs at the start.


    //Initializing LEDs
        P2DIR |= LAUNCH_RED_LED;
        P2DIR |= LAUNCH_GREEN_LED;
        P2DIR |= LAUNCH_BLUE_LED;

        P1DIR |= LEFT_LED;

        P2DIR |= RED_LED;
        P2DIR |= GREEN_LED;
        P5DIR |= BLUE_LED;


        //Initializing Buttons
        P1DIR &= ~LEFT_BUTTON;
        P1DIR &= ~RIGHT_BUTTON;
        P5DIR &= ~TOP_BUTTON;
        P3DIR &= ~BOTTOM_BUTTON;


        P1REN |= LEFT_BUTTON;
        P1REN |= RIGHT_BUTTON;
        P5REN |= TOP_BUTTON;
        P3REN |= BOTTOM_BUTTON;


        P1OUT |= LEFT_BUTTON;
        P1OUT |= RIGHT_BUTTON;
        P5OUT |= TOP_BUTTON;
        P3OUT |= BOTTOM_BUTTON;
}






// TODO: Create a function to return the status of Launchpad Pushbutton S1
unsigned char checkStatus_LaunchpadS1()
{
    return((P1IN & LEFT_BUTTON) == 0);
}

// TODO: Create a function to return the status of Launchpad Pushbutton S2
unsigned char checkStatus_LaunchpadS2()
{
    return((P1IN & RIGHT_BUTTON) == 0);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S1
unsigned char checkStatus_BoosterpackS1()
{
    return((P5IN & TOP_BUTTON) == 0);
}

// TODO: Create a function to return the status of Boosterpack Pushbutton S2
unsigned char checkStatus_BoosterpackS2()
{
    return((P3IN & BOTTOM_BUTTON) == 0);
}













// TODO: Create a function to turn on Launchpad LED1.
void turnOn_LaunchpadLED1()
{
    P1OUT = P1OUT | LEFT_LED;
}

// TODO: Create a function to turn off Launchpad LED1.
void turnOff_LaunchpadLED1()
{
    P1OUT = P1OUT & ~LEFT_LED;
}







// TODO: Create a function to turn on the Red Launchpad LED2.
void turnOn_LaunchpadLED2Red()
{
    P2OUT = P2OUT | LAUNCH_RED_LED;
}

// TODO: Create a function to turn off the Red Launchpad LED2.
void turnOff_LaunchpadLED2Red()
{
    P2OUT = P2OUT & ~LAUNCH_RED_LED;
}







// TODO: Create a function to turn on the Green Launchpad LED2.
void turnOn_LaunchpadLED2Green()
{
    P2OUT = P2OUT | LAUNCH_GREEN_LED;
}

// TODO: Create a function to turn off the Green Launchpad LED2.
void turnOff_LaunchpadLED2Green()
{
    P2OUT = P2OUT & ~LAUNCH_GREEN_LED;
}






// TODO: Create a function to turn on the Blue Launchpad LED2.
void turnOn_LaunchpadLED2Blue()
{
    P2OUT = P2OUT | LAUNCH_BLUE_LED;
}

// TODO: Create a function to turn off the Blue Launchpad LED2.
void turnOff_LaunchpadLED2Blue()
{
    P2OUT = P2OUT & ~LAUNCH_BLUE_LED;
}





// TODO: Create a function to turn on the Red Boosterpack LED2.
void turnOn_BoosterpackLEDRed()
{
    P2OUT = P2OUT | RED_LED;
}

// TODO: Create a function to turn off the Red Boosterpack LED2.
void turnOff_BoosterpackLEDRed()
{
    P2OUT = P2OUT & ~RED_LED;
}






// TODO: Create a function to turn on the Green Boosterpack LED2.
void turnOn_BoosterpackLEDGreen()
{
    P2OUT = P2OUT | GREEN_LED;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDGreen()
{
    P2OUT = P2OUT & ~GREEN_LED;
}






// TODO: Create a function to turn on the Blue Boosterpack LED2.
void turnOn_BoosterpackLEDBlue()
{
    P5OUT = P5OUT | BLUE_LED;
}

// TODO: Create a function to turn off the Green Boosterpack LED2.
void turnOff_BoosterpackLEDBlue()
{
    P5OUT = P5OUT & ~BLUE_LED;
}
