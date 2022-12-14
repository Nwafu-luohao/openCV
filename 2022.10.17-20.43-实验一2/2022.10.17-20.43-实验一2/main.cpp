#include <opencv2\opencv.hpp> //加载 OpenCV 4.1 头文件
#include <iostream>
using namespace std;
using namespace cv; //opencv 的命名空间

int w = 1000;

void MyLine(Mat img, Point start, Point end)
{
	int thickness = 2;
	int lineType = 8;
	line(img,
		start,
		end,
		Scalar(0, 0, 0),
		thickness,
		lineType);
}

void MyEllipse(Mat img, double angle)
{
	int thickness = 2;
	int lineType = 8;

	ellipse(img,
		Point(w / 2.0, w / 2.0),
		Size(w / 4.0, w / 16.0),
		angle,
		0,
		360,
		Scalar(255, 0, 0),
		thickness,
		lineType);
}

void MyFilledCircle(Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;

	circle(img,
		center,
		w / 32.0,
		Scalar(0, 0, 255),
		thickness,
		lineType);
}

void MyPolygon(Mat img)
{
	int lineType = 8;

	/** 创建一些点 */
	Point rook_points[1][20];
	rook_points[0][0] = Point(w / 4.0, 7 * w / 8.0);
	rook_points[0][1] = Point(3 * w / 4.0, 7 * w / 8.0);
	rook_points[0][2] = Point(3 * w / 4.0, 13 * w / 16.0);
	rook_points[0][3] = Point(11 * w / 16.0, 13 * w / 16.0);
	rook_points[0][4] = Point(19 * w / 32.0, 3 * w / 8.0);
	rook_points[0][5] = Point(3 * w / 4.0, 3 * w / 8.0);
	rook_points[0][6] = Point(3 * w / 4.0, w / 8.0);
	rook_points[0][7] = Point(26 * w / 40.0, w / 8.0);
	rook_points[0][8] = Point(26 * w / 40.0, w / 4.0);
	rook_points[0][9] = Point(22 * w / 40.0, w / 4.0);
	rook_points[0][10] = Point(22 * w / 40.0, w / 8.0);
	rook_points[0][11] = Point(18 * w / 40.0, w / 8.0);
	rook_points[0][12] = Point(18 * w / 40.0, w / 4.0);
	rook_points[0][13] = Point(14 * w / 40.0, w / 4.0);
	rook_points[0][14] = Point(14 * w / 40.0, w / 8.0);
	rook_points[0][15] = Point(w / 4.0, w / 8.0);
	rook_points[0][16] = Point(w / 4.0, 3 * w / 8.0);
	rook_points[0][17] = Point(13 * w / 32.0, 3 * w / 8.0);
	rook_points[0][18] = Point(5 * w / 16.0, 13 * w / 16.0);
	rook_points[0][19] = Point(w / 4.0, 13 * w / 16.0);

	const Point* ppt[1] = { rook_points[0] };
	int npt[] = { 20 };

	fillPoly(img,
		ppt,
		npt,
		1,
		Scalar(255, 255, 255),
		lineType);
}


int main()
{
	Point pt;
	pt.x = 10;
	pt.y = 8;

	/// 窗口名字
	char atom_window[] = "Drawing 1: Atom";
	char rook_window[] = "Drawing 2: Rook";

	/// 创建空全黑像素的空图像
	Mat atom_image = Mat::zeros(w, w, CV_8UC3);
	Mat rook_image = Mat::zeros(w, w, CV_8UC3);

	/// 1. 画一个简单的原子。

/// 1.a. 创建椭圆
	MyEllipse(atom_image, 90);
	MyEllipse(atom_image, 0);
	MyEllipse(atom_image, 45);
	MyEllipse(atom_image, -45);

	/// 1.b. 创建圆
	MyFilledCircle(atom_image, Point(w / 2.0, w / 2.0));

	/// 2. 画一个赌棍

/// 2.a. 创建一个凸多边形
	MyPolygon(rook_image);

	/// 2.b. 创建矩形
	rectangle(rook_image,
		Point(0, 7 * w / 8.0),
		Point(w, w),
		Scalar(0, 255, 255),
		-1,
		8);

	/// 2.c. 画几条直线
	MyLine(rook_image, Point(0, 15 * w / 16), Point(w, 15 * w / 16));
	MyLine(rook_image, Point(w / 4, 7 * w / 8), Point(w / 4, w));
	MyLine(rook_image, Point(w / 2, 7 * w / 8), Point(w / 2, w));
	MyLine(rook_image, Point(3 * w / 4, 7 * w / 8), Point(3 * w / 4, w));
	rectangle(rook_image,
		Point(0, 7 * w / 8.0),
		Point(w, w),
		Scalar(0, 255, 255),
		-1,
		8);
	imshow("test", rook_image);
	waitKey(0);
	return 0;
}
