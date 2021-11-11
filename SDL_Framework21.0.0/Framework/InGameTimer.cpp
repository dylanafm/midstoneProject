#include "InGameTimer.h"

InGameTimer::InGameTimer(float finalTime_)
{
	finalTime = finalTime_;
	timer = 0.0f;
}

InGameTimer::~InGameTimer()
{
}

void InGameTimer::Update(float deltaTime, bool &returnValue)
{
	timer += deltaTime;
	if (timer >= finalTime)
		returnValue = !returnValue;
}
