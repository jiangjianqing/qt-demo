#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

int main() {
	// 读入一张图片（游戏原画）    
	//用vs2015配置opencv3.1.0中，出现内存位置0x002bf4c0处的cv::Exception
	//网上搜了一个小时，大部分是要查内存，堆栈。最后才发现其实很简单，是imread的路径不对。
	//imread不支持相对路径，只支持绝对路径，并且不支持“\”路径分隔符，支持“\”, “/”或”//”分割符。 
	//相对路径需要将pic.jpg与Main.cpp放在同一个路径下
	Mat img = imread("pic.jpg");
	// 创建一个名为 "游戏原画"窗口    
	namedWindow("游戏原画");
	// 在窗口中显示游戏原画    
	imshow("游戏原画", img);
	// 等待6000 ms后窗口自动关闭    
	waitKey(6000);
}