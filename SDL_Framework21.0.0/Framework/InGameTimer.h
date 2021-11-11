#ifndef INGAMETIMER_H
#define INGAMETIMER_H

class InGameTimer
{
public:
	float finalTime, timer;

	InGameTimer(float finalTime_);
	~InGameTimer();
	void Update(float deltaTime, bool& returnValue);
};

#endif

