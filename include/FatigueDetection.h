#ifndef FATIGUE_DETECTION_H
#define FATIGUE_DETECTION_H
#include "FaceTracker.h"

class FatigueDetection
{
public:
	FatigueDetection();
	bool DetectFatigue(const Pose& pose);

private:
	bool fatigued = false;
};
#endif
