#include "Motor.h"
#include <avr/io.h>


Motor::Motor(uint8_t fwdPin, volatile uint8_t *fwdPort, uint8_t bckPin, volatile uint8_t *bckPort) {
	this->fwdPin = fwdPin;
	this->fwdPort = fwdPort;
	this->bckPin = bckPin;
	this->bckPort = bckPort;
}

Motor::Motor() {
	this->fwdPin = 0xFF;
	this->fwdPort = nullptr;
	this->bckPin = 0xFF;
	this->bckPort = nullptr;
}

void Motor::stop() {
	*(this->fwdPort) = *(this->fwdPort) & ~(1 << this->fwdPin); //turn the correct pin off
	*(this->bckPort) = *(this->bckPort) & ~(1 << this->bckPin); //turn the correct pin off
}

void Motor::goFwd() {
	*(this->fwdPort) = *(this->fwdPort) | (1 << this->fwdPin); //turn the correct pin on
	*(this->bckPort) = *(this->bckPort) & ~(1 << this->bckPin); //turn the correct pin off
}

void Motor::goBck() {
	*(this->bckPort) = *(this->bckPort) | (1 << this->bckPin); //turn the correct pin on
	*(this->fwdPort) = *(this->fwdPort) & ~(1 << this->fwdPin); //turn the correct pin off
}
