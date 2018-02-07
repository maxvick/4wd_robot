/*
 * 4wd_robot_mc.cpp
 *
 * Created: 24/01/2018 9:27:57 PM
 * Author : Max
 */ 

#include <avr/io.h>
#include "Motor.h"
#include "Robot.h"

int main(void)
{
    //initialise the output port
	DDRD = 0xFF; //enable all of port D as output pins
	//have master enable pins as well - only enable once all init finished?

	//initialise the Robot object & it's motors
	Motor FL = Motor(PORTD0, &PORTD, PORTD1, &PORTD);
	Motor FR = Motor(PORTD2, (uint8_t *)PORTD, PORTD3, (uint8_t *)PORTD);
	Motor BL = Motor(PORTD4, (uint8_t *)PORTD, PORTD5, (uint8_t *)PORTD);
	Motor BR = Motor(PORTD6, (uint8_t *)PORTD, PORTD7, (uint8_t *)PORTD);
	Robot myBot = Robot(&FL, &FR, &BL, &BR);
	myBot.setDirection(STOPPED, 0);

	//initialise the TWI & interrupt vector

	//initialise the timer & interrupt vector
	
	/* Replace with your application code */
    while (1) 
    {
		//listen for commands on I2C
		
    }
}

void forwards(int duration) {


}

