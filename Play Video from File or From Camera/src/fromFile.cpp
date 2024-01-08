#include"opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
    
    VideoCapture cap("C:/Users/shusa/Downloads/Y2meta.app-“Catch me if you can, Mr Holmes” Yuukoku no Moriarty-(480p).mp4");

    if (cap.isOpened() == false) {
        cout << "Cannot open the video file" << endl;
        cin.get();
        return -1;
    }

    //Uncomment the following line if you want to start the video in the middle
    //cap.set(CAP_PROP_POS_MSEC, 300); 

    //fps=frame per second, to get the frames rate of the video
    double fps = cap.get(CAP_PROP_FPS);
    cout << "Frames per seconds: " << fps << endl;
    
    string windowName = "Catch me if you can";

    namedWindow(windowName);

    //
    while (true) {
        Mat frame; 
        bool bSuccess = cap.read(frame); //read a new frame from video 

        //to break the while loop at the end of the video
        if (bSuccess == false) {
            cout<< "Found the end of the video" << endl;
            break;
        }
        //show the frame in the created video
        imshow(windowName, frame);

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }//end of while loop

    return 0;
}