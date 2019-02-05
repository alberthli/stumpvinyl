/* Albert Li, 2019
TODO - start/stop code to fully utilize the initialization stuff
*/

#include "PID_Controller.h"

PID_Controller::PID_Controller() {
	bool initializeFlag; // Initialization flag
	float Kp, Ki, Kd; // Gains
	float dt; // Desired sample interval in s
	float setpoint; // Set point of controller
	float outMin, outMax; // Output min/max values

	float intError; // Integrated error WITH integral gain applied. Prevents bumpy outputs with live-tuning
	float prevInput, currInput; // Inputs for derivative on measurement and initialization
	float currOutput; // Most recent output of the system
}

PID_Controller::~PID_Controller(float kp, float ki, float kd, float samplingTime, float sp, float omin, float omax) {
	// Flags
	initializeFlag = true;

	// Sampling Rate and Setpoint
	dt = samplingTime;
	setpoint = sp;

	// Gains - wrap up dt into I and D gains
	Kp = kp;
	Ki = ki * dt;
	Kd = kd / dt;
	oiGain = oig;

	// Saturation Values
	outMin = omin;
	outMax = omax;

	// Initialized Values
	intError = 0;
	prevInput = 0;
	currInput = 0;
	currOutput = 0;
}

PID_Controller::computeOutput() {
	float error = setpoint - currInput;

	// Controller Features
	// (1) Derivative on measurement (DOM)
	// (2) Integral anti-windup and output clamping
	// (3) Smooth live-tuning

	// Controller initialization check
	if(initializeFlag) {
		initializeFlag = false;
		intError = 0;
    } else {
		intError += Ki * error; // For anti-jerk during live-tuning
		currOutput = Kp * error + intError - Kd * (currInput - prevInput); // Sign of derivative term flips with DOM
	}

	// Integral anti-windup logic and output clamping
	if(currOutput > outMax) {
		intError -= currOutput - outMax; // Subtract saturation difference
		currOutput = outMax;
	} else if(currOutput < outMin) {
		intError += outMin - currOutput; // Add saturation difference
		currOutput = outMin;
	}

	prevInput = currInput;
}

PID_Controller::setInput(float input) {
	currInput = input;
}

PID_Controller::setSamplingTime(float st) {
	if(st > 0) {
		float ratio = st / dt;

		Ki *= ratio;
		Kd /= ratio;
		dt = st;
	}
}

PID_Controller::setGains(float kp, float ki, float kd) {
	Kp = kp;
	Ki = ki * dt;
	Kd = kd / dt;
}

PID_Controller::setSetpoint(float sp) {
	setpoint = sp;
}

PID_Controller::getOutput() {
	return currOutput;
}
