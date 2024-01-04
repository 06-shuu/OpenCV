//save an image to file
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {

	Mat image = imread("res/images/coolcat.jpg");
	if (image.empty()) {
		cout << "could not open or find the image" << endl; 
		cin.get();
		return -1;
	}

	//here we can make changes to the image then save it
	rotate(image, image, ROTATE_90_COUNTERCLOCKWISE);
	resize(image, image, Size(250, 250));

	bool isSuccess = imwrite("res/saved/MyImage.jpg", image);
	if (isSuccess == false) {
		cout << "Failed to save the image" << endl;
		cin.get();
		return -1;
	}

	cout << "Image is successfully saved to a file" << endl; 

	string window_name = "The Saved Image";
	namedWindow(window_name);
	imshow(window_name, image);

	waitKey(0);
	destroyWindow(window_name);

	return 0;
}