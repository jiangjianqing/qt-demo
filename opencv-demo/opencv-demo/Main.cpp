#include <iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  

using namespace cv;

int main() {
	// ����һ��ͼƬ����Ϸԭ����    
	//��vs2015����opencv3.1.0�У������ڴ�λ��0x002bf4c0����cv::Exception
	//��������һ��Сʱ���󲿷���Ҫ���ڴ棬��ջ�����ŷ�����ʵ�ܼ򵥣���imread��·�����ԡ�
	//imread��֧�����·����ֻ֧�־���·�������Ҳ�֧�֡�\��·���ָ�����֧�֡�\��, ��/����//���ָ���� 
	//���·����Ҫ��pic.jpg��Main.cpp����ͬһ��·����
	Mat img = imread("pic.jpg");
	// ����һ����Ϊ "��Ϸԭ��"����    
	namedWindow("��Ϸԭ��");
	// �ڴ�������ʾ��Ϸԭ��    
	imshow("��Ϸԭ��", img);
	// �ȴ�6000 ms�󴰿��Զ��ر�    
	waitKey(6000);
}