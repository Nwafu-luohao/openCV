#define _CRT_SECURE_NO_WARNINGS 1
#include <opencv2\opencv.hpp> //���� OpenCV 4.1 ͷ�ļ�
#include <iostream> 
using namespace std;
using namespace cv; //opencv �������ռ�
int main()
{
	Mat img; //����һ������ͼ�����
	img = imread("D:\logo.png"); //��ȡ·����ͼ��
	if (img.empty())
	{
		cout << "��ȷ��ͼ���ļ������Ƿ���ȷ" << endl;
		return -1;
	}
	imshow("test", img);
	waitKey(0);
	return 0;
}
