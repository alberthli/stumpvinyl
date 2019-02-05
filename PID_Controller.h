/* Albert Li, 2019
	Usage: Trust that the sampling rate of whatever is calling the controller matches the dt variable
*/

class PID_Controller {
public:
	PID_Controller(float kp, float ki, float kd, float samplingTime, float sp, float omin, float omax);
	virtual ~PID_Controller();

private:
	void computeOutput();
	void setSampleTime(float st);
	void setGains(float kp, float ki, float kd);
	void setInput(float input);
	void setSetpoint(float sp);
	float getOutput();

	bool initializeFlag;
	float Kp, Ki, Kd; // Gain
	float dt; // Desired sample interval in s
	float setpoint; // Set point of controller
	float outMix, outMax; // Actuator min/max values

	float intError; // Integrated error, integral gain applied
	float prevInput, currInput; // Inputs for derivative on measurement and initialization
	float currOutput; // Most recent output of the system
}
