/* Albert Li, 2019

*/

#include "PID_Controller"

class Motor {
public:
	Motor();
	virtual ~Motor();

private:
	void command(float rpm);
	void computeRPM();
	float readTarget();

	PID_Controller PID;

	float currRPM;
	float rpmTarget;
}
