//Ex3: Use the capture and store code in Example 2-11 together with the PyrDown()
//code of Example 2 - 6 to create a program that reads from a camera and stores
//downsampled color images to disk.

//Ex4:Modify the code in Exercise 3 and combine it with the window display code in
// Example 2 - 2 to display the frames as they are processed.

#include "opencv2/opencv.hpp"
#include <iostream>

int main() {
	std::string window1 = "Window 1", window2 = "Window 2";
	cv::namedWindow(window1, cv::WINDOW_AUTOSIZE);
	//cv::namedWindow(window2, cv::WINDOW_AUTOSIZE);

	cv::VideoCapture cap("res/videos/Moriarty.mp4");
	double fps = cap.get(cv::CAP_PROP_FPS);
	cv::Size size((int)cap.get(cv::CAP_PROP_FRAME_WIDTH),
		(int)cap.get(cv::CAP_PROP_FRAME_HEIGHT));

	cv::VideoWriter writer;
	writer.open("res/saved/savedMoriarty.avi", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);

	//cv::Mat logpolar_frame, bgr_frame;

	cv::Mat frame, frame2; 
	while (true) {
		cap >> frame;
		if (frame.empty())
			break;
		//display the ooriginal video
		cv::imshow(window1, frame);

		//downsampling the video and display it and save it
		cv::pyrDown(frame, frame2);
		cv::imshow(window2, frame2);
		writer << frame2;  

		char c = cv::waitKey(10);
		if (c == 27)
			break;		
	}//end of while loop

	cap.release();

	return 0;
}