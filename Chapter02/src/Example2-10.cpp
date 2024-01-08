//Input from a Camera

#include "opencv2/opencv.hpp"

int main() {

	std::string window_name = "Example2_10";
	cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
	
	cv::VideoCapture cap(0); //from camera
	//cv::VideoCapture cap("res/videos/Moriarty.mp4"); //from file

	if (!cap.isOpened()) {
		std::cerr << "Could not open capture" << std::endl;
		return -1;
	}

	cv::Mat frame;
	for (;;) {
		cap >> frame; //read the vid frame bt frame
		if (frame.empty())
			break;
		cv::imshow(window_name, frame);
		if (cv::waitKey(33) >= 0)
			break;
	}
	
	return 0; 
}