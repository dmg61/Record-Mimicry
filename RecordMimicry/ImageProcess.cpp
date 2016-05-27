#include "ImageProcess.h"


ImageProcess::ImageProcess()
{
}


ImageProcess::~ImageProcess()
{
}

void ImageProcess::initialize(std::string detectorFilename /*= "shape_predictor_68_face_landmarks.dat"*/)
{
	detector_ = dlib::get_frontal_face_detector();
	dlib::deserialize(detectorFilename) >> sp_;
}

PointArray ImageProcess::getKeyPoints()
{
	return keyPoints_;
}

PointArray ImageProcess::getFaceKeyPoints()
{
	return faceKeyPoints_;
}

PointArray ImageProcess::getNormalizedPoint()
{
	cv::Point2f point;
	PointArray normalized;
	float x, y;

	if (faceKeyPoints_.size() == 0)
		return normalized;

	cv::Rect bRect = cv::boundingRect(faceKeyPoints_);

	for (int i = 0; i < faceKeyPoints_.size(); i++)
	{
		point = faceKeyPoints_[i] - (cv::Point2f)bRect.tl();

		x = (float)point.x / bRect.width;
		y = (float)point.y / bRect.height;

		x = (x < 0.0f) ? 0.0f : ((x > 1.0f) ? 1.0f : x);
		y = (y < 0.0f) ? 0.0f : ((y > 1.0f) ? 1.0f : y);

		normalized.push_back(cv::Point2f(x, y));
	}

	return normalized;
}

void ImageProcess::calibration(const PointMatrix& points, PointArray& calibrationPoints, PointArray& errorPoints /*= PointArray()*/)
{
	if (points.size() == 0)
		return;

	calibrationPoints.clear();
	calibrationPoints.resize(points[0].size(), cv::Point2f(0, 0));

	errorPoints.clear();
	errorPoints.resize(points[0].size(), cv::Point2f(0, 0));

	for (int i = 0; i < points[0].size(); ++i)
	{
		for (int j = 0; j < points.size(); ++j)
			calibrationPoints[i] += points[j][i];

		calibrationPoints[i] /= (float)points.size();
	}

	for (int i = 0; i < points[0].size(); ++i)
	{
		for (int j = 0; j < points.size(); ++j)
			errorPoints[i] += cv::Point2f(abs(calibrationPoints[i].x - points[j][i].x), 
										  abs(calibrationPoints[i].y - points[j][i].y));

		errorPoints[i] /= (float)points.size();
	}
}

cv::Mat ImageProcess::getFaceImg()
{
	return face_;
}

void ImageProcess::drawFaceKeyPoint(cv::Mat& inOutImg, const PointArray& facePoints, cv::Scalar& color /*= Scalar(0, 0, 255)*/)
{
	cv::Point2f indent = cv::Point2f(inOutImg.size().width * 0.06, inOutImg.size().height * 0.06);
	float scale = inOutImg.size().height * 0.86;

	for (int i = 0; i < facePoints.size(); ++i)
		cv::circle(inOutImg, facePoints[i] * scale + indent, 2, color, CV_FILLED);
}

void ImageProcess::drawKeyPoint(cv::Mat& inOutImg, const PointArray& points, cv::Scalar& color /*= cv::Scalar(0, 0, 255)*/)
{
	for (int i = 0; i < points.size(); ++i)
		cv::circle(inOutImg, points[i], 2, color, CV_FILLED);
}



bool ImageProcess::setProcessImg(const cv::Mat& img)
{
	dlib::full_object_detection shape;
	cv::Point2f vertices[4];
	std::map<float, cv::Point2f> sortPoint;
	cv::RotatedRect rRect;
	cv::Mat point3d(3, 1, CV_64FC1);
	float angle;

	keyPoints_.clear();
	faceKeyPoints_.clear();

	img.copyTo(image_);

	keyPoints();
	if (keyPoints_.size() == 0)
		return false;

	rRect = cv::minAreaRect(keyPoints_);
	rRect.points(vertices);

	for (int i = 0; i < 4; ++i)
	{
		angle = innerAngle(vertices[i], keyPoints_[27], keyPoints_[30]);

		sortPoint.insert(std::pair<float, cv::Point2f>(angle, vertices[i]));
	}

	{
		int i = 0;
		for (auto rec : sortPoint)
			vertices[i++] = rec.second;

		vertices[0] += cv::Point2f(0, -5);
		vertices[1] += cv::Point2f(0, -5);
	}

	float w = lengthLine(vertices[0], vertices[1]); // (pow(vertices[0].x - vertices[1].x, 2) + pow(vertices[0].y - vertices[1].y, 2));
	float h = lengthLine(vertices[0], vertices[3]); //sqrt(pow(vertices[0].x - vertices[3].x, 2) + pow(vertices[0].y - vertices[3].y, 2));

	cv::Mat faceTmp(h, w, image_.type());
	cv::Point2f dvertices[4] = { cv::Point2f(0, 0), cv::Point2f(w, 0),
								 cv::Point2f(w, h), cv::Point2f(0, h) };

	cv::Mat M = cv::getPerspectiveTransform(vertices, dvertices);
	cv::warpPerspective(image_, faceTmp, M, faceTmp.size());

	for (int i = 0; i < keyPoints_.size(); ++i)
	{
		point3d.at<double>(0, 0) = keyPoints_[i].x;
		point3d.at<double>(1, 0) = keyPoints_[i].y;
		point3d.at<double>(2, 0) = 1;

		point3d = M * point3d;

		faceKeyPoints_.push_back(cv::Point2f(point3d.at<double>(0, 0), point3d.at<double>(1, 0)));
	}

	faceTmp.copyTo(face_);

	return true;
}

cv::Mat ImageProcess::getProcessImg()
{
	return image_;
}

float ImageProcess::innerAngle(cv::Point2f& firstPoint, cv::Point2f& secondPoint, cv::Point2f& centerPoint) const
{
	cv::Point2f a = firstPoint - centerPoint;
	cv::Point2f b = secondPoint - centerPoint;

	float angle = atan2(a.y, a.x) - atan2(b.y, b.x) * 180 / CV_PI;

	return angle;
}

float ImageProcess::lengthLine(cv::Point2f& firstPoint, cv::Point2f& secondPoint) const
{
	return cv::norm(firstPoint - secondPoint);
}

PointArray ImageProcess::keyPoints()
{
	dlib::array2d<dlib::rgb_pixel> dlibImg;
	std::vector<dlib::rectangle> dets;
	dlib::full_object_detection shape;

	dlib::assign_image(dlibImg, dlib::cv_image<dlib::bgr_pixel>(image_));
	dets = detector_(dlibImg);

	if (dets.size() == 0)
		return keyPoints_;

	shape = sp_(dlibImg, dets[0]);

	keyPoints_.clear();
	for (int j = 0; j < shape.num_parts(); ++j)
		keyPoints_.push_back(cv::Point2f(shape.part(j).x(), shape.part(j).y()));

	return keyPoints_;
}

