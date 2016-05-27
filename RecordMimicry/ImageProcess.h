#ifndef IMAGEPROCESS_H
#define IMAGEPROCESS_H

#include <string.h>
#include <vector>
#include <stdio.h>
#include <conio.h>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp> // OpenCV 2.4.10
//#include <opencv2/ml.hpp> // >= OpenCV 3.0.0

#define USE_SSE_INSTRUCTIONS
#include <dlib/image_processing/frontal_face_detector.h>
#include <dlib/image_processing/render_face_detections.h>
#include <dlib/image_processing.h>
#include <dlib/image_io.h>
#include <dlib/opencv.h>

typedef std::vector<cv::Point2f> PointArray;
typedef std::vector<PointArray> PointMatrix;

class ImageProcess
{
public:

	enum 
	{
		COUNT_FACE_POINT = 48,
		COUNT_KEY_POINTS = 68 
	};

	ImageProcess();
	~ImageProcess();

	void initialize(std::string detectorFilename = "shape_predictor_68_face_landmarks.dat");
	PointArray getKeyPoints();
	PointArray getFaceKeyPoints();
	PointArray getNormalizedPoint();
	void calibration(const PointMatrix& points, PointArray& calibrationPoints, PointArray& errorPoints = PointArray());
	cv::Mat getFaceImg();

	bool setProcessImg(const cv::Mat& img);
	cv::Mat getProcessImg();

	static void drawFaceKeyPoint(cv::Mat& inOutImg, const PointArray& points, cv::Scalar& color = cv::Scalar(0, 0, 255));
	static void drawKeyPoint	(cv::Mat& inOutImg, const PointArray& points, cv::Scalar& color = cv::Scalar(0, 0, 255));

private:
	float innerAngle(cv::Point2f& firstPoint, cv::Point2f& secondPoint, cv::Point2f& centerPoint) const;
	float lengthLine(cv::Point2f& firstPoint, cv::Point2f& secondPoint) const;
	PointArray keyPoints();

private:
	dlib::shape_predictor sp_;
	dlib::frontal_face_detector detector_;

	cv::Mat image_;
	cv::Mat face_;
	PointArray keyPoints_;
	PointArray faceKeyPoints_;
};

static PointArray operator*(const PointArray& points, int n)
{
	PointArray result = points;

	for (int i = 0; i < points.size(); ++i)
		result[i] = points[i] * 2;

	return result;
}

#endif // IMAGEPROCESS_H

