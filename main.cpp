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
	Motor FR = Motor(PORTD2, &PORTD, PORTD3, &PORTD);
	Motor BL = Motor(PORTD4, &PORTD, PORTD5, &PORTD);
	Motor BR = Motor(PORTD6, &PORTD, PORTD7, &PORTD);
	Robot myBot = Robot(&FL, &FR, &BL, &BR);
	myBot.setDirection(STOPPED, 0);
	myBot.setDirection(FORWARDS, 10);
	myBot.setDirection(FAST_LEFT, 10);
	myBot.setDirection(SLOW_LEFT, 10);
	myBot.setDirection(FAST_RIGHT, 10);
	myBot.setDirection(SLOW_RIGHT, 10);
	myBot.setDirection(STOPPED, 10);

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

