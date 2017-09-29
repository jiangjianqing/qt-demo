#include <iostream>
//#include <opencv2\opencv.hpp>
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

int main(int argc, char *argv[])
 {
	
    cv::Mat frame;
    cv::VideoCapture camera(0);

    while(1)
    {
        camera >> frame; 
        cv::imshow("camera", frame);

		if (cv::waitKey(30) == 27) {//°´escÍË³ö
			break;
		};
    }
	

    return 0;
}