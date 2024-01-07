//Example 2-4. add a slider trackbar and  allow the user to single-step the video by pressing the S key and
//to go into run mode by pressing the R key

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <fstream>
using namespace std;
using namespace cv;

//Global Variables (global vars starts with "g_" )
int g_slider_position = 0;
int g_run = 1, g_dontset = 0; // start out in single-step mode
VideoCapture g_cap;

//Functions Prototypes
void onTrackbarSlide(int pos, void *); 


int main(int argc, char** argv) {

	string window_name = "Example 2-4";
	namedWindow(window_name, WINDOW_AUTOSIZE);
	g_cap.open("res/videos/GokuRose.mp4");
	int frames = (int)g_cap.get(CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(CAP_PROP_FRAME_WIDTH); 
	int tmph = (int)g_cap.get(CAP_PROP_FRAME_HEIGHT);
	cout << "Video has: " << frames << " frams of dimensions ( "
		<< tmpw << " x " << tmph << " )." << endl; 

	createTrackbar("Position", window_name, &g_slider_position, frames, onTrackbarSlide);

	Mat frame; 
	for (;;) {
		if (g_run != 0) {
			g_cap >> frame;
			if (frame.empty())
				break;  
			int current_pos = (int)g_cap.get(CAP_PROP_POS_FRAMES);
			g_dontset = 1;
			setTrackbarPos("Position", window_name,current_pos);
			imshow(window_name, frame);

			g_run -= 1;
		}

		char key = (char)waitKey(10); 
		if (key == 's') {
			g_run = 1;
			cout << "Single step, run = " << g_run << endl; 
		}
		if (key == 'r') {
			g_run = -1;
			cout << "Run mode, run = " << g_run << endl;
		}
		if (key == 27) //27 ascii for esc
			break;
		
	}
	return 0;
}

//Callback Functions
void onTrackbarSlide(int pos, void *) {
	g_cap.set(CAP_PROP_POS_FRAMES, pos);
	if (!g_dontset)
		g_run = 1; 
	g_dontset = 0;
}