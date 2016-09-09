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
		
		int simpleCounter = 0;

		int* IDPtr = faceTracker.GetIDs();

		//std::cout << *IDPtr << std::endl;
;

		for (;;) {
			IDPtr = faceTracker.GetIDs();
			if (simpleCounter % 15 == 0) {
				/*fatigueDetection.DetectFatigue(faceTracker.GetPose());
				fatigueDetection.DetectYawn(faceTracker.GetFaceFeatures());*/

				std::cout << '#' << simpleCounter / 15;
				
				int personNum = 0;
				for (personNum; personNum < 6; personNum++) {
					if (*(IDPtr + personNum) != -1) {
						std::cout << "\t" << *(IDPtr + personNum) << '\t';
					}
				}

				std::cout << std::endl;

				if (faceTracker.FaceFound()) {
					std::cout << faceTracker.GetFaceFeatures();
					std::cout << "Is Yawning? : " << fatigueDetection.DetectYawn(faceTracker.GetFaceFeatures()) << std::endl;

				}
				
				else {
					std::cout << "FACE NOT FOUND! >:(" << std::endl;
					personNum = 0;
					for (personNum; personNum < 6; personNum++) {
						IDPtr[personNum] = -1;
					}
				}
				std::cout << std::endl;
			}
			simpleCounter++;

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