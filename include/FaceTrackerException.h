#ifndef FACE_TRACKER_EXCEPTION_H
#define FACE_TRACKER_EXCEPTION_H
#include <stdexcept>

class FaceTrackerException : public std::runtime_error
{
public:
	FaceTrackerException(const char* exception) :
		FaceTrackerException(std::string(exception))
	{

	}
	FaceTrackerException(std::string& exception) :
		  message(exception)
		, std::runtime_error(exception)
	{

	}
	const char* what() const throw()
	{
		return message.c_str();
	}
protected:
	std::string message;
};
#endif
