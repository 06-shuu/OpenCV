//Load Image from file and display

#include <opencv2/opencv.hpp> // include all other neccessary header files in OpenCV library
#include <iostream>
using namespace cv; //to avoid appending cv:: before each opencv function,class, or data structure
using namespace std;

int main() {
	//read image from file (imread=image read) it can be(jpeg, jpg, bmp, png, tiff and tif)
	Mat image = imread("images/emoji.jpg"); //read image and return it as Mat object

	if (image.empty()) {
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	string windowName = "The Emoji"; //name of the Window
	namedWindow(windowName); //Create the window
	imshow(windowName, image); //imshow = image show
	
	waitKey(0);//wait for any key press
	destroyWindow(windowName); //then distroy the image

	return 0;
}