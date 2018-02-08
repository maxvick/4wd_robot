/*
 * 4wd_robot_mc.cpp
 *
 * Created: 24/01/2018 9:27:57 PM
 * Author : Max
 */ 

#include <avr/io.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include "Motor.h"
#include "Robot.h"

int main(void)
{
    //initialise the output port
	DDRD = 0xFF; //enable all of port D as output pins

	//Enable the Two Wire Interface module on PortE	
	power_twi_enable();

	//enable timer 0
	power_timer0_enable();
	TCCR0B |= ((1 << CS02) | (1 << CS00)); //scale by 1024
	TCNT0 = 0x01; //set the counter to maximum time
	TIMSK0 |= (1 << TOIE0); //enable the interrupt mask

	//enable the global interrupt mask
	sei();

	
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

	//initialise the timer & interrupt vector
	
	/* Replace with your application code */
	int test = 0;
    while (1) 
    {
		//listen for commands on I2C
		test++;
    }
}

void forwards(int duration) {


}


//Timer 0 overflow handler
ISR(TIMER0_OVF_vect) {
	int test = 5;
	test += 66;
	TIMSK0 &= ~(1 << TOIE0); // diable the mask
}

