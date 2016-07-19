#include "FatigueDetection.h"

FatigueDetection::FatigueDetection()
{

}
bool FatigueDetection::DetectFatigue(const Pose& pose)
{
	fatigued = false;
	if (pose.pitch < 0.f)
	{
		fatigued = true;
	}
	return fatigued;
}