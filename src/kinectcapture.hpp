#ifndef LUXKINECTDEV_HPP
#define LUXKINECTDEV_HPP

#ifndef OPENCV_HAS_OPENNI
#error OpenCV was compiled without OpenNI support
#else

#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <icapture.hpp>

class KinectCapture : public ICapture
{
public:
    KinectCapture(Resolutions res = LUX_RES_640x480); //true - right oriented coordinate system
    void readFrame();

    ~KinectCapture() { delete capture; }
    inline int getFrameCount () { return 0; }
    inline bool isConnected() { return capture->isOpened(); }
    inline bool setFrameNumber(int) { return false; }
private:
    cv::VideoCapture *capture;
};

#endif // OPENCV_HAS_OPENNI

#endif // KINECTCAPTURE_HPP
