//Example 5-1. Complete program to alpha-blend the ROI starting at (0,0) in src2 with the ROI starting at(x, y) in src1
//note: roi = region of interest
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

int main(int argc, char** argv) {

	cv::Mat src1 = cv::imread("res/images/fruits.jpg",1);
	cv::Mat src2 = cv::imread("res/images/eren.jpg",1);
	
	int from_w = src1.size().width;
	int from_h = src1.size().height;
	int to_w = src2.size().width;
	int to_h = src2.size().height;

	if (!src1.empty() && !src2.empty()) {
		
		int x = 10;
		int y = 50;

		if ((x < 0) || (y < 0) || (x > to_w - 1) || (y > to_h - 1) || (x + from_w > to_w - 1) || (y + from_h > to_h)) {
			std::cout << "\nError, at (x,y) (" << x << ", " << y << "), your input image [w,h] [" << from_w << ", "
				<< from_h << "] doesn't fit within the blend to image [w,h] [" << to_w << ", " << to_h << "]\n" << std::endl;
			return -1;
		}
		
		double alpha = 0.7;
		double beta = 0.3;


		cv::Mat roi1(src1, cv::Rect(0, 0, from_w - 1, from_h - 1)); //Just take the whole thing
		cv::Mat roi2(src2, cv::Rect(x, y, from_w - 1, from_h - 1));

		cv::addWeighted(roi1, alpha, roi2, beta, 0.0, roi2);

		cv::namedWindow("Alpha Blend",1);
		cv::imshow("Alpha Blend", src2);



		cv::waitKey(0);
	}

	return 0;
}