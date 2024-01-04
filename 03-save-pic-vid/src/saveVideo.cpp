//Save a video to a file

#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	VideoCapture cap("res/videos/IsaacFoster.mp4");
	//VideoCapture cap(0); //if we want to save video from the camera


	if (cap.isOpened() == false) {
		cout << "Cannot open the video camera" << endl;
		cin.get();
		return -1;
	}

	//cast the frame into int 
	int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH)); //get the width of frames of the video
	int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT)); //get the height of frames of the video


	Size frame_size(frame_width, frame_height);
	int frames_per_second = 10;

	//create and initialize the videoWriter object
	VideoWriter oVideoWriter("res/saved/ZackVid.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), frames_per_second, frame_size, true);

	if (oVideoWriter.isOpened() == false) {
		cout << "cannot save video to file" << endl; 
		cin.get();
		return -1;
	}

	string window_name = "Capture Zack";
	namedWindow(window_name);

	while (true) {
		Mat frame;
		bool isSuccess = cap.read(frame);

		if (isSuccess == false) {
			//cout << "Video Camera is disconnected" << endl; 
			cin.get();
			break;
		}

		//here we can make changes to the image then save it

		oVideoWriter.write(frame);
		imshow(window_name, frame);

		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by the user. Stopping the video" << endl;
			break;
		}

	}//end of while loop
	return 0;
}