#include "imageToMat.h"

cv::Mat ImageToMat(Image& img) // stanum enq struktura u darcnum Mat
{
    int type;
    if (img.channels == 1) 
    {
        type = CV_8UC1;
    } 
    else 
    {
        type = CV_8UC3;
    }
    cv::Mat mat(img.height,img.width,type,img.data);
    cv::cvtColor(mat, mat, cv::COLOR_BGR2RGB);
    return mat;
}

Image MatToImage(cv::Mat& mat) //stanum enq Mat darcnum enq Image
{
    Image img;
    img.width = mat.cols;
    img.height = mat.rows;
    img.depth = mat.depth();
    img.channels = mat.channels();

    // Allocate memory for image data
    img.data = new unsigned char[img.width * img.height * img.channels];

    // Copy image data
    int index = 0;
    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            const cv::Vec3b& color = mat.at<cv::Vec3b>(y, x);
            if (img.channels == 1) 
            {
                img.data[index] = color[2];
            } 
            else 
            {
                img.data[index] = color[2];
                img.data[index + 1] = color[1];
                img.data[index + 2] = color[0];
            }
            index += img.channels;
        }
    }
    return img;
}

