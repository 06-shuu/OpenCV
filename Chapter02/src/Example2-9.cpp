//read and write pixel values from

#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main() {
	Mat img_rgb, img_gry, img_cny, img_pyr, img_pyr2;
	img_rgb = cv::imread("res/images/fruits.jpg");

	string window1 = "Greyscale";
	string window2 = "After the Canny edge detector";
	//greyscale the image and save it into new image
	cvtColor(img_rgb, img_gry, COLOR_BGR2GRAY);
	
	pyrDown(img_gry, img_pyr);
	pyrDown(img_pyr, img_pyr2);
	Canny(img_pyr2, img_cny, 10, 100, 3, true);

	//=====================start of example 2-9=====================

	//Accesses the color pixel at coordinates (16, 32) in the original image 
	//and stores the intensity values in a Vec3b object.
	int x = 16, y = 32;
	Vec3b intensity = img_rgb.at<Vec3b>(x, y);
	//Vec3b intensity = img_rgb.at<Vec3b>(x, y)[0];

	//Extracts the blue, green, and red channel values.
	uchar blue, green, red;
	blue = intensity[0];
	green = intensity[1];
	red = intensity[2];

	cout << "At (x,y) = (" << x << ", " << y << "): (blue, green, red) = ( " <<
		(unsigned int)green  << ", " << (unsigned int)blue  << ", "
		<< (unsigned int)red  << " )" << endl;
	cout << "Grey pixel there is: " << (unsigned int)img_gry.at<uchar>(x, y) << endl; 

	x /= 4; y /= 4;
	cout << "Pyramid2 pixel there is:" << (unsigned int)img_pyr2.at<uchar>(y, x) << endl; 
	img_cny.at<uchar>(x, y) = 128;
	//=====================end of example 2-9=====================


	imshow(window1, img_gry);
	imshow(window2, img_cny);

	cv::waitKey(0);
	cv::destroyAllWindows();

	return 0;
}