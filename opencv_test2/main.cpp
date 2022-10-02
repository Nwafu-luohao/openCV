#define _CRT_SECURE_NO_WARNINGS 1

#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("D:\logo.png");
	imshow("input", src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}