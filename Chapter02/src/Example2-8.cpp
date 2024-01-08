#include "opencv2/opencv.hpp"

int main() {
	cv::Mat img_rgb, img_grey, img_canny, img_pyr, img_pyr2;
	img_rgb = cv::imread("res/images/fruits.jpg");

	std::string window1 = "Greyscale";
	std::string window2 = "After the Canny edge detector";
	//greyscale the image and save it into new image
	cv::cvtColor(img_rgb, img_grey, cv::COLOR_BGR2GRAY);
	cv::imshow(window1, img_grey);

	cv::pyrDown(img_grey, img_pyr);
	cv::pyrDown(img_pyr, img_pyr2); 
	cv::Canny(img_pyr2, img_canny, 10, 100, 3, true);
	cv::imshow(window2, img_canny);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}