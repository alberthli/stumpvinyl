/* Albert Li, 2019

*/

#include "PID_Controller"

// Standard vinyl rotation rates
#define RPM_00_MODE 0.00 // Off
#define RPM_33_MODE 33.33
#define RPM_45_MODE 45.00
#define RPM_78_MODE 78.00

class Motor {
public:
	Motor();
	virtual ~Motor();

private:
	void command();
	void computeRPM();
	void changeRPM(RPM_Mode rpm);
	RPM_Mode readTarget();

	PID_Controller PID;

	float currRPM;
	enum RPM_Mode = {RPM_00_MODE, RPM_33_MODE, RPM_45_MODE, RPM_78_MODE};
	RPM_MODE rpmMode;
}
