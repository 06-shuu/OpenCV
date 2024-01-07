//Example 2-3. 

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char** argv) {

	string window_name = "Playing a Video";
	namedWindow(window_name, WINDOW_AUTOSIZE);
	VideoCapture cap;
	cap.open(string("res/videos/Moriarty.mp4"));

	Mat frame;
	for (;;) {
		cap >> frame; //read the vid frame bt frame
		if (frame.empty()) 
			break;
		imshow(window_name, frame);
		// wait 33 ms.4 If the user hits a key during that time, we will exit the read
		// loop.Otherwise, 33 ms will pass and we will executethe loop again
		if (waitKey(33) >= 0)
			break;
	}

	return 0;
}