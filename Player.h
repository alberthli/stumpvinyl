/* Albert Li, 2019
	
*/

#include "Motor.h"

// Standard vinyl rotation rates
// TODO: Use const float and replace the enum later
#define RPM_00_MODE 0 // Off
#define RPM_33_MODE 1
#define RPM_45_MODE 2
#define RPM_78_MODE 3

class Player {
public:
	Player();
	virtual ~Player();

private:
	Motor motor;
	bool ON_FLAG;
	enum RPM_Mode = {RPM_00_MODE, RPM_33_MODE, RPM_45_MODE, RPM_78_MODE};
	RPM_Mode rpmMode;
	float samplingTime;

	void start();
	void stop();
	void setRPM();
	float getRPM();
}
