#ifndef ROBOT_H
#define ROBOT_H
#include "Motor.h"

enum Direction {FORWARDS, BACKWARDS, SLOW_LEFT, FAST_LEFT, SLOW_RIGHT, FAST_RIGHT, STOPPED};

class Robot {
	private:
		int direction;
		Motor frontL;
		Motor backL;
		Motor frontR;
		Motor backR;

	public:
		int getDirection(void);
		void setDirection(Direction, uint8_t duration);
		Robot(Motor *frL, Motor *frR, Motor *bkL, Motor *bkR);

};
#endif
