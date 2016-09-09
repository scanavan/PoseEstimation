#ifndef FACE_TRACKER_H
#define FACE_TRACKER_H
#include <Windows.h>
#include <Kinect.h>
#include <Kinect.Face.h>
#include <opencv2/opencv.hpp>
#include <string>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Pose
{
	float roll;
	float pitch;
	float yaw;
	Pose() : roll(0.f), pitch(0.f), yaw(0.f) {}
	Pose(float r, float p, float y) : roll(r), pitch(p), yaw(y) {}
	friend std::ostream& operator<<(std::ostream& os, const Pose& pose)
	{
		if (pose.roll != 0.f && pose.pitch != 0.f && pose.yaw != 0.f)
		{
			os << "(" << pose.roll << ", " << pose.pitch << ", " << pose.yaw << ")" << std::endl;
		}
		return os;
	}
};
struct FaceFeature
{
	bool happy;
	bool engaged;
	bool wearingGlasses;
	bool leftEyeClosed;
	bool rightEyeClosed;
	bool mouthOpen;
	bool mouthMoved;
	bool lookingAway;
	friend std::ostream& operator<<(std::ostream& os, const FaceFeature& feature)
	{
		os << "Happy: " << feature.happy << std::endl
			<< "Engaged: " << feature.engaged << std::endl
			<< "WearingGlasses: " << feature.wearingGlasses << std::endl
			<< "Left Eye Closed: " << feature.leftEyeClosed << std::endl
			<< "Right Eye Closed: " << feature.rightEyeClosed << std::endl
			<< "Mouth Open: " << feature.mouthOpen << std::endl
			<< "Mouth Moved: " << feature.mouthMoved << std::endl
			<< "Looking Away: " << feature.lookingAway << std::endl;
		return os;
	}
};
class FaceTracker
{
public:
	FaceTracker(std::string name = "Face Tracker");
	//init data
	void Initialize();
	//spawn thread
	void Start(bool detach = false);
	//return pose data
	Pose GetPose() const;
	//get all of the face features from the Kinect (happy, etc.)
	FaceFeature GetFaceFeatures() const;
	//if face is found
	bool FaceFound();
	int* GetIDs();

private:
	HRESULT hResult;

	//Kinect camera functionality
	IKinectSensor* sensor;
	IColorFrameSource* colorSource;
	IBodyFrameSource* bodySource;
	IColorFrameReader* colorReader;
	IBodyFrameReader* bodyReader;
	IFrameDescription* description;
	ICoordinateMapper* coordinateMapper;
	IFaceFrameReader* faceReader[BODY_COUNT];
	IFaceFrameSource* faceSource[BODY_COUNT];
	//features we are using with Kinect
	DWORD features;

	//image sizes
	int width = 0;
	int height = 0;
	unsigned bufferSize;

	//opencv buffers to hold data
	cv::Mat bufferMat;
	cv::Mat faceMat;
	//title of window
	std::string windowName;
	//colors for face tracking
	cv::Vec3b faceColors[BODY_COUNT];

	std::string faceProperties[FaceProperty::FaceProperty_Count];
	DetectionResult facePropertyList[FaceProperty::FaceProperty_Count];
	template<class Interface>
	inline void SafeRelease(Interface *& interfaceToRelease)
	{
		if (interfaceToRelease != NULL)
		{
			interfaceToRelease->Release();
			interfaceToRelease = NULL;
		}
	}
	//normal operation
	void Run();
	//pose estimation
	void ExtractFaceRotationInDegrees(const Vector4* pQuaternion);
	void ExtractFaceProperties();
	Pose pose;

	FaceFeature faceFeature;
};
#endif