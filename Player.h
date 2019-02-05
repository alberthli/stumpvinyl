#include "Motor.h"
#include <elapsedMillis.h>

class Player {
public:
	Player();
	virtual ~Player();

private:
	Motor M;
	bool ON_FLAG;
	
	void start();
	void stop();
}