#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
//using namespace std;

int main()
{
    //cv::Mat img = cv::imread("res/coolcat.jpg"); //open the image 
    //namedWindow("First OpenCV Application", WINDOW_AUTOSIZE); //create a window
    //cv::imshow("First OpenCV Application", img); //display the image in the window
    //cv::moveWindow("First OpenCV Application", 0, 45); //window location
    //cv::waitKey(0); //by pressing any key the application will be terminated 
    //cv::destroyAllWindows();
    //return 0;

    std::string image_path1 = "images/coolcat.jpg";
    std::string image_path2 = "images/coolcat.jpg";

    cv::Mat image1 = cv::imread(image_path1, cv::IMREAD_COLOR);
    cv::Mat image2 = cv::imread(image_path2, cv::IMREAD_COLOR);

    if (image1.empty() || image2.empty()) {
        std::cout << "Couldn't read the image" << std::endl; 
        return 1; 
    }

    cv::rotate(image2, image2, cv::ROTATE_90_COUNTERCLOCKWISE);
    cv::resize(image2, image2, cv::Size(500,500));

    //greyscale the image

    for (int i = 0; i < image2.rows; i++) { //i for th erows
        for (int j = 0; j < image2.cols; j++) {
            cv::Vec3b bgrPixel = image2.at<cv::Vec3b>(i, j);
            //Greyscale = R+B+G/3 
            //OpenCV library functions usually read images in BGR format
            unsigned char greyScale = (bgrPixel[2]+ bgrPixel[1]+ bgrPixel[0]) / 3;
            image2.at<cv::Vec3b>(i, j) = { greyScale, greyScale, greyScale };
            cv::Vec3b greyPixel = image2.at<cv::Vec3b>(i, j);
        }
    }

    cv::imshow("First", image1);
    cv::imshow("Second", image2);
    cv::waitKey(0); //by pressing any key the application will be terminated 
    cv::destroyAllWindows();

}