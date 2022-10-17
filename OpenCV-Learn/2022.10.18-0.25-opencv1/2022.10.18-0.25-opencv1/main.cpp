#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("E:\\picture\\wheat.png");
	if (src.empty()) {
		return -1;
	}
	imshow("input", src);
	waitKey(0);
	destroyAllWindows();

	return 0;
}