#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;

constexpr int WaitTime{10};
constexpr int QASCIICode{113};

int main(int argc, const char **argv)
{
    // VideoCapture class for playing video for which faces to be detected
    VideoCapture capture;
    Mat frame, image;

    capture.open(0);

    if (capture.isOpened())
    {
        // Capture frames from video and detect faces
        std::cout << "actual work" << std::endl;
        while (true)
        {
            capture >> frame;
            if (frame.empty())
            {
                break;
            }
            Mat frame1 = frame.clone();
            imshow("random name", frame);

            // Press q to exit from window
            if (waitKey(WaitTime) == QASCIICode) 
            {
                break;
            }
        }
    }
    else
    {
        std::cout << "Could not Open Camera";
    }
}