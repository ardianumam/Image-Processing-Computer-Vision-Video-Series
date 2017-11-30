// 1ImageRepresentation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <vector>


using namespace cv;
using namespace std;

int main()
{
	/* make grayscale image */
	/*
	Mat imageGrayscale = Mat::zeros(100, 300, CV_8UC1);
	for (int x = 0; x < imageGrayscale.rows; x++)
	{
		for (int y = 0; y < imageGrayscale.cols; y++)
		{
			imageGrayscale.at<uchar>(x, y) = 0;//assigning grayscale pixel value
		}
	}
	namedWindow("Grayscale image", WINDOW_AUTOSIZE);// Create a window for display
	imshow("Grayscale image", imageGrayscale);// Show grayscale image
	*/

	/* make rgb image */
	/*
	Mat imageBGR = Mat::zeros(100, 300, CV_8UC3);
	for (int x = 0; x < imageBGR.rows; x++)
	{
		for (int y = 0; y < imageBGR.cols; y++)
		{
			imageBGR.at<Vec3b>(x, y).val[0] = 255;//blue channel
			imageBGR.at<Vec3b>(x, y).val[1] = 0;//green channel
			imageBGR.at<Vec3b>(x, y).val[2] = 255;//red channel
		}
	}
	namedWindow("BGR image", WINDOW_AUTOSIZE);// Create a window for display
	imshow("BGR image", imageBGR);// Show BGR image
	*/

	/* convert BGR to HSV */
	/*
	Mat ImageHsv;
	cvtColor(imageBGR, ImageHsv, CV_BGR2HSV);
	cvtColor(ImageHsv, ImageHsv, CV_HSV2BGR);
	namedWindow("HSV image", WINDOW_AUTOSIZE);// Create a window for display
	imshow("HSV image", ImageHsv);// Show HSV image
	vector<Mat> channels;
	split(ImageHsv, channels);
	
	imshow("h channel", channels[0]);
	imshow("s channel", channels[1]);
	imshow("v channel", channels[2]);
	*/

	/* read image as grascale or color image */
	
	Mat lena;
	//lena = imread("lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);// Read as grayscale
	lena = imread("lena.jpg", CV_LOAD_IMAGE_COLOR);// Read as color

	if (!lena.data)// Check for invalid input
	{
		cout << "Could not open or find the image" << std::endl;
	}
	namedWindow("lena", WINDOW_AUTOSIZE);// Create a window for display
	imshow("lena", lena);// Show our image inside it
	
	waitKey(0);// Wait for a keystroke in the window
	return 0;
}
