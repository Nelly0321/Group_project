#include <opencv2/highgui.hpp>

#include <iostream>

using namespace cv;

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
                break;
            Mat frame1 = frame.clone();
            imshow("random name", frame);
            char c = (char)waitKey(10);

            // Press q to exit from window
            if (c == 27 || c == 'q' || c == 'Q')
                break;
        }
    }
    else
    {
        std::cout << "Could not Open Camera";
    }
}