#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;

int main()
{
    cv::Mat img = cv::imread("res/emoji.jpg"); //open the image 
    namedWindow("First OpenCV Application", WINDOW_AUTOSIZE); //create a window
    cv::imshow("First OpenCV Application", img); //display the image in the window
    cv::moveWindow("First OpenCV Application", 0, 45); //window location
    cv::waitKey(0); //by pressing any key the application will be terminated 
    cv::destroyAllWindows();
    return 0;
}