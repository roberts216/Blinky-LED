/***********************************************************************
* main.c
* 
* Copyright 2020
* 
* TwoMoons Software Development Studios
*   Tom Roberts
*   02/19/20
* 	Blinky v1.0.0
* 
* This program is used to demonstrated blinking various LEDs
* connected to a Raspberry Pi and breadboard.
* 
* Utilizes the WiringPi GPIO library to provide a hardare interface.
* 
***********************************************************************/


#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

// Note: WiringPi ports are NOT the same as Raspberry Pi GPIO assignments.
//  See WiringPi documentation for assignments.
#define		RGBRED		0
#define		RGBBLUE		2
#define		RGBGREEN	3
#define		LEDGREEN	25
#define		LEDRED		27
#define		DELAY		100
#define		OFF			0
#define		ON			1

void blinkLed(int ledType, int state);

int main(void)
{
	int x;
	int red;
	int green;
	int blue;

	// Configure the GPIO pins with connected LEDs.	
	if( wiringPiSetup() == 1)
		exit(1);
		
	pinMode(LEDGREEN, OUTPUT);
	pinMode(LEDRED, OUTPUT);
	pinMode(RGBRED, OUTPUT);
	pinMode(RGBGREEN, OUTPUT);
	pinMode(RGBBLUE, OUTPUT);
	
	//Clear current LED states.
	blinkLed(LEDRED, OFF);
	blinkLed(LEDGREEN, OFF);
	blinkLed(RGBRED, OFF);
	blinkLed(RGBGREEN, OFF);
	blinkLed(RGBBLUE, OFF);
	
	
	while(1)
	{
		printf("Blink red LED! \n");
		blinkLed(LEDRED, ON);
		blinkLed(LEDRED, OFF);

		printf("Blink green LED! \n");
		blinkLed(LEDGREEN, ON);
		blinkLed(LEDGREEN, OFF);
	
		// Loop thru the 7 states to blink the RGB LED.
		for(x=0;x<=7;x++)
		{
			red = x & 4;		// Bitwise compare bit 2.
			red = red>>2;
			green = x & 2;		// Bitwise compare bit 1.
			green= green>>1;
			blue = x & 1;		// Bitwise compare bit 0.
			
			// Blink RGB LED with current state.
			printf("Blink RGB LED! \n");
			printf("red = %d, green = %d, blue = %d\n", red, green, blue);
			blinkLed(RGBRED, red);
			blinkLed(RGBGREEN, green);
			blinkLed(RGBBLUE, blue);
		}	
		
		// Clear the RGB LED.
		blinkLed(RGBRED, OFF);
		blinkLed(RGBGREEN, OFF);
		blinkLed(RGBBLUE, OFF);
			
	}
	
	return 0;
}

// Function to blink a connected LED.
void blinkLed(int ledType, int state)
{
	digitalWrite(ledType, state);
	delay(DELAY);	

	return;
}
