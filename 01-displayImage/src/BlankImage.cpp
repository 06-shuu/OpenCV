//Create a Blank Image and display

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	//image resolution (600 high 800 wide)
	//8 unsigned bits, 3 channels 
	// each pixels initialized to the value of (100, 250, 30) for Blue, Green and Red planes respectivel
	Mat image(600,800, CV_8UC3, Scalar(100,250,30));
	string windowName = "Window with Blank Image";
	namedWindow(windowName);
	imshow(windowName, image);

	waitKey(0);
	destroyWindow(windowName);

	return 0;

}