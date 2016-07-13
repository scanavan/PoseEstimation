cmake_minimum_required(VERSION 2.6)
PROJECT(HeadPoseEstimation)
SET(CMAKE_CONFIGURATION_TYPES Debug Release CACHE STRING "" FORCE)

SET(OPENCV_DIR "C:/OpenCV/build/")
SET(SOURCE_DIR "source")
SET(INCLUDE_DIR "include")

FILE(GLOB SOURCE_FILES ${SOURCE_DIR}/*.cpp)
FILE(GLOB HEADER_FILES ${INCLUDE_DIR}/*.h)

#modify according to your opencv installation
SET( OPENCV_INCLUDES C:/opencv/build/include ) 
SET( OPENCV_LIB C:/opencv/build/x64/vc14/lib ) 

#header filters
SOURCE_GROUP("Header Files" FILES ${HEADER_FILES})
#source filters
SOURCE_GROUP("Source Files" FILES ${SOURCE_FILES})

INCLUDE_DIRECTORIES(${OPENCV_DIR}/include ${INCLUDE_DIR})
LINK_DIRECTORIES(${OPENCV_DIR}/x64/vc12/lib/ )

ADD_EXECUTABLE( HeadPoseEstimation ${SOURCE_FILES} ${HEADER_FILES})

TARGET_LINK_LIBRARIES (HeadPoseEstimation opencv_world310.lib)




