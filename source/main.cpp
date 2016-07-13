#include <iostream>
#include "FaceTracker.h"
#include "FaceTrackerException.h"

int main()
{
	try
	{
		FaceTracker faceTracker;
		faceTracker.Initialize();
		faceTracker.Run();
	}
	catch (FaceTrackerException& error)
	{
		std::cout << error.what() << std::endl;
	}
	return EXIT_SUCCESS;
}