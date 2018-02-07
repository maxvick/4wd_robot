#include "Motor.h"
#include <avr\io.h>


Motor::Motor(uint8_t fwdPin, volatile uint8_t fwdPort, uint8_t bckPin, volatile uint8_t bckPort) {
	this->fwdPin = fwdPin;
	this->fwdPort = fwdPort;
	this->bckPin = bckPin;
	this->bckPort = bckPort;
}

void Motor::stop() {
	*fwdPort = *fwdPort && !(1 << this->fwdPin); //turn the correct pin off
	*bckPort = *bckPort && !(1 << this->bckPin); //turn the correct pin off
}

void Motor::goFwd() {
	*fwdPort = *fwdPort || (1 << this->fwdPin); //turn the correct pin on
	*bckPort = *bckPort && !(1 << this->bckPin); //turn the correct pin off
}

void Motor::goBck() {
	*bckPort = *bckPort || (1 << this->bckPin); //turn the correct pin on
	*fwdPort = *fwdPort && !(1 << this->fwdPin); //turn the correct pin off
}