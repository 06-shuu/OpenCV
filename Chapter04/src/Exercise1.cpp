//1. Create a 500 × 500 single channel uchar image with every pixel equal to zero.
//a.Create an ASCII numeric typewriter where you can type numbers into your
//computer and have the number show up in a 20 - pixel - high by 10 - pixel - wide
//block.As you type, the numbers will display from left to right until you hit the
//end of the image.Then just stop.
//b.Allow for carriage return and backspace.
//c.Allow for arrow keys to edit each number.
//d.Create a key that will convert the resulting image into a color image, each
//number taking on a different color

#include "opencv2/opencv.hpp"
#include <iostream>

int main() {
	
	std::string windowname = "Example1";
	//cv::namedWindow(windowname);
	cv::Mat image(500, 500, CV_8UC1, cv::Scalar(0));

	int currentRow = 0;
	int currentCol = 0;
	bool colorMode = false;


	//cv::imshow(windowname,image);

    while (true) {
        // Wait for a key press
        int key = cv::waitKey(0);

        // Check for the ESC key to exit the loop
        if (key == 27) {
            break;
        }

        // Handle key events
        switch (key) {
        case '\b':  // Backspace
            if (currentCol > 0) {
                currentCol -= 10;  // Move back by 10 pixels
            }
            else if (currentRow > 0) {
                currentRow--;      // Move up one row
                currentCol = image.cols - 10;  // Move to the end of the previous row
            }
            break;

        case '\r':  // Carriage return
            currentRow += 20;  // Move to the next row
            currentCol = 0;    // Move to the beginning of the row
            break;

        case 224:   // Arrow key pressed (for arrow keys, two key codes are returned)
            key = cv::waitKey(0);  // Get the actual key code

            switch (key) {
            case 72:  // Up arrow
                currentRow -= 10;
                break;
            case 80:  // Down arrow
                currentRow += 10;
                break;
            case 75:  // Left arrow
                currentCol -= 10;
                break;
            case 77:  // Right arrow
                currentCol += 10;
                break;
            }
            break;

        case 'c':  // Toggle color mode
            colorMode = !colorMode;
            break;

        default:
            // Draw the typed number on the image
            if (colorMode) {
                // Generate a random color for each number
                cv::Scalar color(rand() % 256, rand() % 256, rand() % 256);
                putText(image, std::to_string(key), cv::Point(currentCol, currentRow), cv::FONT_HERSHEY_SIMPLEX, 0.4, color, 1, cv::LINE_AA);
            }
            else {
                putText(image, std::to_string(key), cv::Point(currentCol, currentRow), cv::FONT_HERSHEY_SIMPLEX, 0.4, 255, 1, cv::LINE_AA);
            }

            // Move to the next position
            currentCol += 10;
            if (currentCol >= image.cols) {
                currentRow += 20;
                currentCol = 0;
            }
            break;
        }

        
        imshow(windowname, image);
    }

	return 0;
}