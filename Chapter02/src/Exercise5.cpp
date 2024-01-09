//Modify the program of Exercise 4 with a trackbar slider control from
//Example 2 - 4 so that the user can dynamically vary the pyramid downsampling
//reduction level by factors of between 2 and 8. You may skip writing this to disk,
//but you should display the results.

#include "opencv2/opencv.hpp"
#include <iostream>

//global var
int downsamplingLevel = 2;
//func. prototype
void onTrackbarSlide(int factor, void *);

int main() {
	std::string window1 = "Downsampling";
	cv::namedWindow(window1, cv::WINDOW_AUTOSIZE);
	
	cv::VideoCapture cap("res/videos/Moriarty.mp4");

	cv::createTrackbar("Downsampling level", window1, &downsamplingLevel, 8, onTrackbarSlide); 

	cv::Mat frame, frame2;
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;
		
		//downsampling the video and display it and save it
		cv::pyrDown(frame, frame2);
		cv::imshow(window1, frame2);
	
		char c = cv::waitKey(10);
		if (c == 27)
			break;
	}//end of while loop

	cap.release();

	return 0;
}

void onTrackbarSlide(int factor, void *) {
	downsamplingLevel = factor; 
}