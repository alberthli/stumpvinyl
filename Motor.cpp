/* Albert Li, 2019
	TODO - get a motor w/encoder to implement and test computeRPM()
*/

#include "Motor.h"

// Min/Max PWM inputs for Teensy
#define omin 0.0
#define omax 256.0

Motor::Motor(float kp, float ki, float kd, float samplingTime) {
	currRpm = 0;
	rpmTarget = 0;
	PID = PID_Controller(kp, ki, kd, samplingTime, rpmTarget, omin, omax);
}

Motor::~Motor() {

}

Motor::command(float rpm) {
	rpmTarget = rpm;
	PID.setSetpoint(rpm);
	PID.setInput(computeRPM());
	PID.computeOutput(); // output in PWM from 0 to 256
	// analogWrite([PIN], (int)PID.getOutput()); // Write output
}

Motor::computeRPM() {
	// Read speed from encoders
	// currRPM = [whatever is read];
}

Motor::readTarget() {
	return rpmTarget;
}
