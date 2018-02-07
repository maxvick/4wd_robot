#include <stdint-gcc.h>
#ifndef MOTOR_H
#define MOTOR_H

#define UNDEF_PIN 255
#define HIGH 1
#define LOW 0

class Motor {

	private:
		uint8_t fwdPin;
		volatile uint8_t *fwdPort;
		uint8_t bckPin;
		volatile uint8_t *bckPort;

	public:
		void goFwd(void);
		void goBck(void);
		void stop(void);
		Motor(uint8_t forward_pin, volatile uint8_t *forward_port, uint8_t backard_pin, volatile uint8_t *backward_port);
		Motor();
};
#endif
