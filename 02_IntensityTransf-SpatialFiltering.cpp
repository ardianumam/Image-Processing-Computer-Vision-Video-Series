// 2_IntensityTransf-SpatialFiltering.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	//read image
	Mat image1 = imread("image1.jpg", 0);
	//namedWindow("original image", WINDOW_AUTOSIZE);
	//imshow("original image", image1);

	//manual binary treshold
	/*
	for (int x = 0; x < image1.rows; x++)
	{
		for (int y = 0; y < image1.cols; y++)
		{
			int a = ((int)image1.at<uchar>(x, y));
			if (a < 125)
			{
				image1.at<uchar>(x, y) = 0;
			}
			else
			{
				image1.at<uchar>(x, y) = 255;
			}
		}
	}
	imshow("binary tresholded", image1);
	*/

	//binary using OpenCV API
	//threshold(image1, image1, 125, 255, THRESH_BINARY);
	//imshow("image 1", image1);

	//piece-wise linear transformation
	/*
	int hor1 = 100, hor2 = 140, ver1 = 40, ver2 = 210;
	for (int i = 0; i < image1.rows; i++)
	{
		for (int j = 0; j < image1.cols; j++)
		{
			int x = ((int)image1.at<uchar>(i, j));
			if (x >= 0 && x < hor1)
			{
				int x1=0, y1=0, x2=hor1, y2=ver1;
				image1.at<uchar>(i, j) = (((x - x1)*(y2 - y1) / (x2 - x1)) + y1);
			}
			else if ((x >= hor1 && x < hor2))
			{
				int x1 = hor1, y1 = ver1, x2 = hor2, y2 = ver2;
				image1.at<uchar>(i, j) = (((x - x1)*(y2 - y1) / (x2 - x1)) + y1);
			}
			else if ((x >= hor2 && x < 255))
			{
				int x1 = hor2, y1 = ver2, x2 = 255, y2 = 255;
				image1.at<uchar>(i, j) = (((x - x1)*(y2 - y1) / (x2 - x1)) + y1);
			}
		}
	}
	imshow("piece-wise linear transformation", image1);
	*/
	//Histogram equalization
	//equalizeHist(image1, image1);
	//imshow("Histogram equalized image", image1);


	//averaging filter
	/*
	int kernel_size = 3;
	Mat kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);
	Mat image2 = imread("image2.jpg", 0);
	imshow("original image", image2);
	int depth = -1, delta = 0;
	Point anchor = Point(-1, -1);
	/// Apply filter
	for (int a = 1; a<=20; a++)
	{
		filter2D(image2, image2, depth, kernel, anchor, delta, BORDER_DEFAULT);
		if (a == 5) { imshow("5x smoothed image", image2); }
		if (a == 10) { imshow("10x smoothed image", image2); }
		if (a == 15) { imshow("15x smoothed image", image2); }
		if (a == 20) { imshow("20x smoothed image", image2); }
	}
	*/

	//sharpening
	/*
	Mat image3 = imread("image3.jpg",0);
	Mat laplacian; Mat sharpenedImage;
	int kernel_size = 3;
	int depth = -1;
	Point anchor = Point(-1, -1);
	int delta = 0;
	Mat kernel = Mat::zeros(kernel_size, kernel_size, CV_32F);
	kernel.at<float>(0, 1) = -1; kernel.at<float>(1, 0) = -1; kernel.at<float>(1, 2) = -1; kernel.at<float>(2, 1) = -1;
	kernel.at<float>(1, 1) = 4;
	filter2D(image3, laplacian, depth, kernel, anchor, delta, BORDER_DEFAULT);
	sharpenedImage = image3 + 2*(laplacian);
	imshow("image 3", image3);
	imshow("laplacian of image 3", laplacian);
	imshow("sharpened image", sharpenedImage);
	*/

	//unsharping mask
	/*
	Mat ori = imread("image3.jpg", 0);
	Mat smoothed; Mat unsharpedMask; Mat unsharped;
	int kernel_size = 7;
	Mat kernel = Mat::ones(kernel_size, kernel_size, CV_32F) / (float)(kernel_size*kernel_size);
	int depth = -1, delta = 0;
	Point anchor = Point(-1, -1);
	/// Apply filter
	for (int a = 1; a <= 20; a++)
	{
		filter2D(ori, smoothed, depth, kernel, anchor, delta, BORDER_DEFAULT);
	}
	int k = 1.3;
	unsharpedMask = k*(ori - smoothed);
	unsharped = ori + unsharpedMask;
	imshow("ori", ori);
	imshow("mask", unsharpedMask);
	imshow("unsharped", unsharped);
	*/

	//sobel
	
	Mat ori = imread("image4.jpg", 0);
	Mat resultSobel;
	int kernel_size = 3;
	int depth = -1;
	Point anchor = Point(-1, -1);
	int delta = 0;
	Mat kernel = Mat::zeros(kernel_size, kernel_size, CV_32F);
	kernel.at<float>(0, 0) = -1; kernel.at<float>(0, 1) = -2; kernel.at<float>(0, 2) = -1;
	kernel.at<float>(2, 0) = 1; kernel.at<float>(2, 1) = 2; kernel.at<float>(2, 2) = 1;
	filter2D(ori, resultSobel, depth, kernel, anchor, delta, BORDER_DEFAULT);
	imshow("ori", ori);
	imshow("resultSobel vertikal saja", resultSobel);
	

	waitKey(0);
    return 0;
}

