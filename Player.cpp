/* Albert Li, 2019

*/

#include "Player.h"
#include <elapsedMillis.h>

// TODO: Characterize motor gains after we have a motor picked out
#define MOTOR_KP 1
#define MOTOR_KI 1
#define MOTOR_KD 1

elapsedMillis loopTime;

Player::Player() {
	ON_FLAG = false;
	rpmMode = RPM_00_MODE;
	samplingTime = 0.01; // 100 Hz default
	motor = Motor(MOTOR_KP, MOTOR_KI, MOTOR_KD, samplingTime);
}

Player::~Player() {

}

Player::start(RPM_Mode rpmm) {
	// TODO: Make this an interrupt function
	ON_FLAG = true;
}

Player::stop() {
	// TODO: Make this an interrupt function. Can probably do one function for start/stop that does edge detection on one pin to toggle start/stop.
	ON_FLAG = false;
}

Player::setRPM(RPM_Mode rpmm) {
	// TODO: Make this an interrupt function
	if(rpmm == (RPM_00_MODE || RPM_33_MODE || RPM_45_MODE || RPM_78_MODE)) {
		rpmMode = rpmm;
	}
}

Player::getRPM(RPM_Mode rpmm) {
	switch(rpmm) {
		case 0: return 0.0;
		case 1: return 33.33;
		case 2: return 45.0;
		case 3: return 78.0;
	}
}

int main() {
	try {
		while(true) {
			if(loopTime >= samplingTime) {
				if(ON_FLAG) {
					motor.command(getRPM(rpmMode));
				} else {
					motor.command(0)
				}

				loopTime = 0;
			}
		}

	} catch (int e) {
		stop();
		// TODO: more robust exception handling. Probably need a delay at least, but most of all need to determine sources of error.
		start();
	}
}
