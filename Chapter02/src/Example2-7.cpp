#include "opencv2/opencv.hpp"

int main() {
	cv::Mat img_rbg, img_grey, img_canny;
	img_rbg = cv::imread("res/images/fruits.jpg"); 

	std::string window1 = "Greyscale";
	std::string window2 = "After the Canny edge detector";
	//greyscale the image and save it into new image
	cv::cvtColor(img_rbg, img_grey,cv::COLOR_BGR2GRAY );
	cv::imshow(window1, img_grey);

	cv::Canny(img_grey, img_canny, 10, 100, 3, true);
	cv::imshow(window2, img_canny);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}