#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "homework3.h"
#include "myGPIO.h"
#include "myTimer.h"



int main(void)
{
    // Count variables to control the LEDs.
    unsigned int count0 = 0;
    unsigned int count1 = 0;

    // TODO: Declare the variables that main uses to interact with your state machine.
    char buttonhistory = 0x00;


    // Stops the Watchdog timer.
    initBoard();


    // Initialize the GPIO.
    // YOU MUST WRITE THIS FUNCTION IN myGPIO.c
    initGPIO();



    // Initialize Timer0 to provide a one second count interval for updating LED2.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_0_BASE, TIMER0_PRESCALER, TIMER0_COUNT);


    // Initialize Timer1 to provide a one millisecond count interval for updating the button history.
    // YOU MUST WRITE THIS FUNCTION IN myTimer.c
    initTimer(TIMER32_1_BASE, TIMER1_PRESCALER, TIMER1_COUNT);




    while(1)
    {

        // Update the color of LED2 using count0 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeLaunchpadLED2(count0);



        // Update the color of the Boosterpack LED using count1 as the index.
        // YOU MUST WRITE THIS FUNCTION BELOW.
        changeBoosterpackLED(count1);

        // TODO: If Timer0 has expired, increment count0.
        // YOU MUST WRITE timer0expired IN myTimer.c
        if(timer0Expired())
            count0++;


        // TODO: If Timer1 has expired, update the button history from the pushbutton value.
        // YOU MUST WRITE timer1expired IN myTimer.c
        if(timer1Expired())
        {
            int sample = checkStatus_BoosterpackS1();
            buttonhistory = (buttonhistory << 1) | sample;
            //count1++;
        }




        // TODO: Call the button state machine function to check for a completed, debounced button press.
        // YOU MUST WRITE THIS FUNCTION BELOW.

        bool fsmB = fsmBoosterpackButtonS1(buttonhistory);
        if(fsmB == true){
            count1++;
        }


        // TODO: If a completed, debounced button press has occurred, increment count1.



    }
}

void initBoard()
{
    WDT_A_hold(WDT_A_BASE);
}



// TODO: Map the value of a count variable to a color for LED2.
// Since count is an unsigned integer, you can mask the value in some way.
void changeLaunchpadLED2(unsigned int count0)
{
    switch(count0 & 7){

                //Off 000
                case 0:
                    turnOff_LaunchpadLED2Blue();
                    turnOff_LaunchpadLED2Green();
                    turnOff_LaunchpadLED2Red();
                    break;

                //Red 001
                case 1:
                    turnOff_LaunchpadLED2Blue();
                    turnOff_LaunchpadLED2Green();
                    turnOn_LaunchpadLED2Red();
                    break;

                //Green 010
                case 2:
                    turnOff_LaunchpadLED2Blue();
                    turnOn_LaunchpadLED2Green();
                    turnOff_LaunchpadLED2Red();
                    break;

                //Yellow 011
                case 3:
                    turnOff_LaunchpadLED2Blue();
                    turnOn_LaunchpadLED2Green();
                    turnOn_LaunchpadLED2Red();
                    break;

                //Blue 100
                case 4:
                    turnOn_LaunchpadLED2Blue();
                    turnOff_LaunchpadLED2Green();
                    turnOff_LaunchpadLED2Red();
                    break;

                //Magenta 101
                case 5:
                    turnOn_LaunchpadLED2Blue();
                    turnOff_LaunchpadLED2Green();
                    turnOn_LaunchpadLED2Red();
                    break;

                //Cyan 110
                case 6:
                    turnOn_LaunchpadLED2Blue();
                    turnOn_LaunchpadLED2Green();
                    turnOff_LaunchpadLED2Red();
                    break;

                //White 111
                case 7:
                    turnOn_LaunchpadLED2Blue();
                    turnOn_LaunchpadLED2Green();
                    turnOn_LaunchpadLED2Red();
                    break;

            }
}




// TODO: Maybe the value of a count variable to a color for the Boosterpack LED
// This is essentially a copy of the previous function, using a different LED
void changeBoosterpackLED(unsigned int count1)
{
    switch(count1 & 7){

                //Off 000
                case 0:
                    turnOff_BoosterpackLEDBlue();
                    turnOff_BoosterpackLEDGreen();
                    turnOff_BoosterpackLEDRed();
                    break;

                //Red 001
                case 1:
                    turnOff_BoosterpackLEDBlue();
                    turnOff_BoosterpackLEDGreen();
                    turnOn_BoosterpackLEDRed();
                    break;

                //Green 010
                case 2:
                    turnOff_BoosterpackLEDBlue();
                    turnOn_BoosterpackLEDGreen();
                    turnOff_BoosterpackLEDRed();
                    break;

                //Yellow 011
                case 3:
                    turnOff_BoosterpackLEDBlue();
                    turnOn_BoosterpackLEDGreen();
                    turnOn_BoosterpackLEDRed();
                    break;

                //Blue 100
                case 4:
                    turnOn_BoosterpackLEDBlue();
                    turnOff_BoosterpackLEDGreen();
                    turnOff_BoosterpackLEDRed();
                    break;

                //Magenta 101
                case 5:
                    turnOn_BoosterpackLEDBlue();
                    turnOff_BoosterpackLEDGreen();
                    turnOn_BoosterpackLEDRed();
                    break;

                //Cyan 110
                case 6:
                    turnOn_BoosterpackLEDBlue();
                    turnOn_BoosterpackLEDGreen();
                    turnOff_BoosterpackLEDRed();
                    break;

                //White 111
                case 7:
                    turnOn_BoosterpackLEDBlue();
                    turnOn_BoosterpackLEDGreen();
                    turnOn_BoosterpackLEDRed();
                    break;

            }
}

// TODO: Create a button state machine.
// The button state machine should return true or false to indicate a completed, debounced button press.
bool fsmBoosterpackButtonS1(unsigned int buttonhistory)
{
    static enum {Press,PtoR,Release,RtoP} buttonstate;
    //static char buttonstate = 1;


    bool pressed = false;

    switch(buttonstate){

    case Press:
        if(buttonhistory == 0xFF){
            pressed = true;
            buttonstate = PtoR;
        }
        break;

    case PtoR:
        if(buttonhistory != 0x00)
            buttonstate = Press;
        if(buttonhistory == 0xFF)
            buttonstate = Release;
            break;

    case Release:
        if(buttonhistory == 0X00){
            pressed = false;
            buttonstate = RtoP;
        }
        break;

    case RtoP:
        if(buttonhistory !=0xFF)
        buttonstate = Release;
        if(buttonhistory == 0x00)
        buttonstate = Press;
        break;
    }
    return pressed;
}

/*0000 Off
 *0001 Red
 *0010 Green
 *0011 Yellow
 *0100 Blue
 *0101 Magenta
 *0110 Cyan
 *0111 White
 */
