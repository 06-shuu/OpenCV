//A complete program to read in a color video and write out the log-polartransformed video

#include "opencv2/opencv.hpp"
#include <iostream>

int main() {
	std::string window1="Example 2-11", window2="Log Polar";
	cv::namedWindow(window1,cv::WINDOW_AUTOSIZE);
	cv::namedWindow(window2,cv::WINDOW_AUTOSIZE);


	return 0;
}