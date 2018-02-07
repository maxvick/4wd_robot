﻿#include "Robot.h"

Robot::Robot(Motor *frontL, Motor *frontR, Motor *backL, Motor *backR ) {
	this->frontL = *frontL;
	this->frontR = *frontR;
	this->backL = *backL;
	this->backR = *backR;
}

int Robot::getDirection(void) {
	return this->direction;
}

void Robot::setDirection(Direction whichWay, int duration) {
	switch(whichWay) {
		case FORWARDS:
		this->frontL.goFwd();
		this->frontR.goFwd();
		this->backL.goFwd();
		this->backR.goFwd();

		case BACKWARDS:
		this->frontL.goBck();
		this->frontR.goBck();
		this->backL.goBck();
		this->backR.goBck();

		case SLOW_LEFT:
		this->frontL.goFwd();
		this->frontR.stop();
		this->backL.goFwd();
		this->backR.stop();

		case FAST_LEFT:
		this->frontL.goFwd();
		this->frontR.goBck();
		this->backL.goFwd();
		this->backR.goBck();

		case SLOW_RIGHT:
		this->frontR.goFwd();
		this->frontL.stop();
		this->backR.goFwd();
		this->backL.stop();

		case FAST_RIGHT:
		this->frontR.goFwd();
		this->frontL.goBck();
		this->backR.goFwd();
		this->backL.goBck();

		case STOPPED:
		this->frontR.stop();
		this->frontL.stop();
		this->backR.stop();
		this->backL.stop();
	}

	//set the timer?

	//check the duration value -> if duration == 0 then do not set the interrupt timer
}
