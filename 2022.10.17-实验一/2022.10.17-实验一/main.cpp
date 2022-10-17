#include <opencv2\opencv.hpp> //加载 OpenCV 4.1 头文件
#include <iostream>
using namespace std;
using namespace cv; //opencv 的命名空间
int main()
{
	Mat img; //声明一个保存图像的类
	img = imread("E:\\picture\\sheep.png"); //读取路径下图像
	if (img.empty())
	{
		cout << "请确认图像文件名称是否正确" << endl;
		return -1;
	}
	imshow("test", img);
	waitKey(0);
	return 0;
}
