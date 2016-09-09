#include "FatigueDetection.h"
#include <time.h>

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

bool FatigueDetection::DetectYawn(const FaceFeature &faceFeature) {
	
	
	/*
	double secondsElapsed = 0;
	/*while (secondsElapsed < 2) {
		secondsElapsed = difftime(time(0), initialTime);
	} [asterisk]/
	if (faceFeature.mouthOpen) {
		/*time_t initialTime = time(0);
		while (secondsElapsed < 2) {
			if (!(faceFeature.mouthOpen)) {
				yawn = false;
				break;
			}
			secondsElapsed = difftime(time(0), initialTime);
			yawn = true;
		} [asterisk]/ */

	yawn = false;

	if (faceFeature.mouthOpen)
	{
		countFrames++;
		if (countFrames >= 3)
		{
			countFrames = 0;
			std::cout << "Yawning actually found, sir!!" << std::endl;
			yawn = true;
		}
		
	}
	else
	{
		//std::cout << "No Yawn?? " << countFrames << std::endl;
		countFrames = 0;
	}
	return yawn;
}