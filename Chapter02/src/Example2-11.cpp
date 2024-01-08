//A complete program to read in a color video and write out the log-polartransformed video

#include "opencv2/opencv.hpp"
#include <iostream>

int main() {
	std::string window1="Example 2-11", window2="Log Polar";
	cv::namedWindow(window1,cv::WINDOW_AUTOSIZE);
	cv::namedWindow(window2,cv::WINDOW_AUTOSIZE);

	cv::VideoCapture cap("res/videos/Moriarty.mp4");
	double fps = cap.get(cv::CAP_PROP_FPS);
	cv::Size size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH), 
		(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT));

	cv::VideoWriter writer;
	writer.open("res/saved/savedMoriarty.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);

	cv::Mat logpolar_frame, bgr_frame;
	while (true) {
		cap >> bgr_frame;
		if (bgr_frame.empty())
			break;
		cv::imshow(window1, bgr_frame);
		//==logPolar==
		cv::logPolar(bgr_frame, logpolar_frame,
			cv::Point2f(bgr_frame.cols / 2, bgr_frame.rows / 2), 40, cv::WARP_FILL_OUTLIERS);
		//1st input: Input color frame
		// 2: Output log-polar frame
		// 3: centerpoint for log-polar transformation (x,y)
		// 4: Magnitude (Scale parameter)
		// 5: Fill outliers with 'zero'
		//=============
		cv::imshow(window2, logpolar_frame);
		writer << logpolar_frame; //save the vid

		char c = cv::waitKey(10);
		if (c == 27) break;
	}//end of while loop

	cap.release();

	return 0;
}