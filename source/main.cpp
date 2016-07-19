#include <iostream>
#include "FaceTracker.h"
#include "FaceTrackerException.h"
#include "FatigueDetection.h"

int main()
{
	try
	{
		FaceTracker faceTracker;
		faceTracker.Initialize();
		faceTracker.Start(true);
		FatigueDetection fatigueDetection;
		for (;;)
		{
			if (faceTracker.FaceFound())
			{
				std::cout << fatigueDetection.DetectFatigue(faceTracker.GetPose()) << std::endl;
			}
			if (cv::waitKey(33) == 'a')
			{
				break;
			}
		}
	}
	catch (FaceTrackerException& error)
	{
		std::cout << error.what() << std::endl;
	}
	return EXIT_SUCCESS;
}