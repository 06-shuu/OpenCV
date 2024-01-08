#include "opencv2/opencv.hpp"

int main() {

	cv::Mat img1, img2;
	img1 = cv::imread("res/images/fruits.jpg");

	std::string window1 = "Before";
	std::string window2 = "After";

	cv::namedWindow(window1, cv::WINDOW_AUTOSIZE);
	cv::namedWindow(window2, cv::WINDOW_AUTOSIZE);

	//imshow takes 1. window name, 2.image to be displayed
	cv::imshow(window1, img1);
	//downsample img1 and save it in new img2
	cv::pyrDown(img1,img2);
	cv::imshow(window2, img2); 

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}