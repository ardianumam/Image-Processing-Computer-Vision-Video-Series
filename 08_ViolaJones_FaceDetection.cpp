// 08_ViolaJones_FaceDetection.cpp : 
//Defines the entry point for the console application.
//

#include "stdafx.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	//read image to imageInput Mat OpenCV
	Mat imageInput;
	imageInput = imread("faces.jpg", CV_LOAD_IMAGE_COLOR);
	//imageInput = imread("russian_license-plate.jpg", CV_LOAD_IMAGE_COLOR);
	
	// Load Face cascade (.xml file)
	CascadeClassifier face_cascade;
	face_cascade.load("C:/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");
	//face_cascade.load("C:/opencv/sources/data/haarcascades/haarcascade_russian_plate_number.xml"); 

	// Detect faces
	std::vector<Rect> faceBasis;
	face_cascade.detectMultiScale(imageInput, faceBasis, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	
	// Draw circles on the detected faces
	for (int i = 0; i < faceBasis.size(); i++)
	{
		Point center(faceBasis[i].x + faceBasis[i].width*0.5, faceBasis[i].y + faceBasis[i].height*0.5);
		ellipse(imageInput, center, Size(faceBasis[i].width*0.5, faceBasis[i].height*0.5), 0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);//red (bgr)
	}
	//show detected image
	imshow("Detected Face", imageInput);
	waitKey(0);
	return 0;
}
