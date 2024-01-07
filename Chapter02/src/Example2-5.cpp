// Example 2-5. Loading and then smoothing an image before it is displayed on the screen

#include "opencv2/opencv.hpp"
#include <iostream>

//prototype
void example2_5(const cv::Mat& image);

int main() {

	cv::Mat image = cv::imread("res/images/coolcat.jpg");

	example2_5(image);
	return 0;
}

//call back func
void example2_5(const cv::Mat& image) {
	
	std::string window1name = "Original Image";
	std::string window2name = "Image After Smoothing";

	cv::namedWindow(window1name, cv::WINDOW_AUTOSIZE);
	cv::namedWindow(window2name, cv::WINDOW_AUTOSIZE);

	cv::imshow(window1name, image); 

	// Create an image to hold the smoothed output
	cv::Mat outputImage;
	//
	cv::GaussianBlur(image, outputImage, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(outputImage, outputImage, cv::Size(5, 5), 3, 3);
	
	cv::imshow(window2name, outputImage);

	cv::waitKey(0);
}
