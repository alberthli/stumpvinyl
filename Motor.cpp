/* Albert Li, 2019
TODO - get a motor w/motor to implement and test the computeRPM function
TODO - get a teensy so we can start matching pins
*/

#include "Motor.h"

#define omin 0
#define omax 256

Motor::Motor(float kp, float ki, float kd, float samplingTime) {
	currRpm = 0;
	rpmMode = RPM_00_MODE;
	PID = PID_Controller(kp, ki, kd, samplingTime, rpmMode, omin, omax);
}

Motor::~Motor() {

}

Motor::command() {
	PID.setInput(computeRPM());
	PID.computeOutput();
	// analogWrite([PIN], (int)PID.getOutput()); // Write output 
}

Motor::computeRPM() {
	// Read speed from encoders
	// currRPM = [whatever is read];
}

Motor::changeRPM(RPM_Mode rpm) {
	rpmMode = rpm;
	PID.setSetpoint(rpmMode);
}

Motor::readTarget() {
	return rpmMode;
}
