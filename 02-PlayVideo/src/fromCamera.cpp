//Capture and play video from camera/webcam
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main() {

	VideoCapture cap(0); //This line will initialize the VideoCapture object with the default camera and the default back-end.

	if (cap.isOpened() == false) {
		cout << "Cannot open the video camera" << endl;
		cin.get();
		return -1;
	}

	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Resolution of the video: " << dWidth << " x " << dHeight << endl;

	string window_name = "My Camera Feed";
	namedWindow(window_name);

	while (true) {
		Mat frame; 
		bool bSuccess = cap.read(frame);

		if (bSuccess == false) {
			cin.get(); //wait for any key press
			break;
		}

		imshow(window_name, frame);

		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}

	}//end of while loop

	return 0;
}