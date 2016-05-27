#include "recordmimicry.h"

RecordMimicry::RecordMimicry(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	codec = QTextCodec::codecForName("Windows-1251");

	calibration = false;
	faceKeyPointsOption = false;
	normalizedKeyPointsOption = false;
	calibrationKeyPointsOption = false;
	modeType = Webcam;

	calibrationPoints.resize(68, Point2f(0, 0));
	ip.initialize();

	captureTimer				= new QTimer(this);
	calibrationTimer			= new QTimer(this);
	calibrationInformationTimer = new QTimer(this);

	connect(captureTimer,				SIGNAL(timeout()), this, SLOT(captureProcess()));
	connect(calibrationTimer,			SIGNAL(timeout()), this, SLOT(calibrationProcess()));	
	connect(calibrationInformationTimer,SIGNAL(timeout()), this, SLOT(calibrationInformationProcess()));

	connect(ui.startRecordButton,	   SIGNAL(clicked()), this, SLOT(startRecord()));
	connect(ui.stopRecordButton,	   SIGNAL(clicked()), this, SLOT(stopRecord()));
	connect(ui.startCalibrationButton, SIGNAL(clicked()), this, SLOT(startCalibration()));
	connect(ui.outputFileButton,	   SIGNAL(clicked()), this, SLOT(outputFileDialog()));

	connect(ui.faceKeyPointBox,			SIGNAL(clicked()), this, SLOT(displayOptionsChanged()));
	connect(ui.normalizedKeyPointBox,	SIGNAL(clicked()), this, SLOT(displayOptionsChanged()));
	connect(ui.calibrationKeyPointBox,	SIGNAL(clicked()), this, SLOT(displayOptionsChanged()));

	connect(ui.webcamButton,		SIGNAL(clicked()), this, SLOT(modeChanged()));
	connect(ui.writeVideoButton,	SIGNAL(clicked()), this, SLOT(modeChanged()));
	connect(ui.readVideoButton,		SIGNAL(clicked()), this, SLOT(modeChanged()));
}

RecordMimicry::~RecordMimicry()
{
	captureTimer->stop();
	calibrationTimer->stop();
	calibrationInformationTimer->stop();

	delete captureTimer;
	delete calibrationTimer;
	delete calibrationInformationTimer;
}

void RecordMimicry::captureProcess()
{
	Mat img, face, resizeImg;
	PointArray facePoints;

	if (!cap.grab())
		return;

	cap >> img;

	if (modeType == VideoWrite)
		videoWriter.write(img);

	cv::resize(img , resizeImg, Size(320, 240));
	if (ip.setProcessImg(resizeImg))
	{
		/*	Point2f src[] = { facePoints[36], facePoints[39], facePoints[42], facePoints[45], facePoints[33] };
			Point2f dst[] = { calibrationPoints[36], calibrationPoints[39], calibrationPoints[42], calibrationPoints[45], calibrationPoints[33] };

			Point2f src[] = { facePoints[36], facePoints[42], facePoints[33], facePoints[30] };
			Point2f dst[] = { calibrationPoints[36], calibrationPoints[42], calibrationPoints[33], calibrationPoints[30] };

			Mat M = cv::getAffineTransform(src, dst);

			cv::Mat point3d(3, 1, CV_64FC1);
			for (int i = 0; i < facePoints.size(); ++i)
			{
			cv::resize(point3d, point3d, Size(3, 1));
			point3d.at<double>(0, 0) = facePoints[i].x;
			point3d.at<double>(1, 0) = facePoints[i].y;
			point3d.at<double>(2, 0) = 1;

			point3d = M * point3d;

			facePoints[i].x = point3d.at<double>(0, 0);
			facePoints[i].y = point3d.at<double>(1, 0);
			}
			*/
		Mat keyPointsImg(200, 200, CV_8UC3, Scalar(240, 240, 240));

		if (normalizedKeyPointsOption)
			ImageProcess::drawFaceKeyPoint(keyPointsImg, ip.getNormalizedPoint(), Scalar(0, 0, 255));

		if (calibrationKeyPointsOption)
			ImageProcess::drawFaceKeyPoint(keyPointsImg, calibrationPoints, Scalar(255, 0, 0));

		if (faceKeyPointsOption)
			ImageProcess::drawKeyPoint(img, ip.getKeyPoints() * 2, Scalar(0, 0, 255));

		ui.normalizedPointsLabel->setPixmap(matToQPixmap(keyPointsImg));

		calibrationMatrix.push_back(ip.getNormalizedPoint());
	}

	ui.videoLabel->setPixmap(matToQPixmap(img));
}

void RecordMimicry::calibrationProcess()
{
	Mat img, resizeImg;

	if (!cap.grab())
		return;

	cap >> img;
	if (img.empty())
		return;

	cv::resize(img, resizeImg, Size(320, 240));
	if (ip.setProcessImg(resizeImg))
	{
		if (calibration)
		{
			calibrationMatrix.push_back(ip.getNormalizedPoint());

			Mat pointsImg(200, 200, CV_8UC3, Scalar(240, 240, 240));

			for (int i = 0; i < calibrationMatrix.size(); ++i)
				ImageProcess::drawFaceKeyPoint(pointsImg, calibrationMatrix[i], Scalar(255, 0, 0));

			ui.normalizedPointsLabel->setPixmap(matToQPixmap(pointsImg));
		}
		
		ImageProcess::drawKeyPoint(img, ip.getKeyPoints() * 2);
	}
	else if (calibration)
	{
		cap.release();
		calibration = false;
		calibrationInformationTimer->stop();
		calibrationTimer->stop();

		calibrationMatrix.clear();

		ui.stopRecordButton->setEnabled(false);
		ui.startRecordButton->setEnabled(false);
		ui.startCalibrationButton->setEnabled(true);

		ui.normalizedPointsLabel->setPixmap(QPixmap());

		QMessageBox::critical(this, tc("Ошибка"), tc("Калибрация не удалась!\nНе следует двигать головой в процессе калибрации!"));
		ui.statusBar->showMessage(tc("Калибрация не удалась"));

		return;
	}

	ui.videoLabel->setPixmap(matToQPixmap(img));	
}

void RecordMimicry::calibrationInformationProcess()
{
	static int countIteration = 0;

	if (calibration)
	{
		ui.statusBar->showMessage(tc("Калибрация закончится через ") + QString::number(5 - countIteration) + tc(" сек."));

		if (countIteration == 5)
		{
			cap.release();
			calibration = false;
			countIteration = 0;

			ui.statusBar->showMessage(tc("Калибрация завершена"));

			calibrationInformationTimer->stop();
			calibrationTimer->stop();

			ip.calibration(calibrationMatrix, calibrationPoints, errorPoints);

			ui.stopRecordButton->setEnabled(false);
			ui.startRecordButton->setEnabled(true);
			ui.startCalibrationButton->setEnabled(true);

			Mat pointsImg(200, 200, CV_8UC3, Scalar(240, 240, 240));

			ImageProcess::drawFaceKeyPoint(pointsImg, calibrationPoints, Scalar(255, 0, 0));

			ui.normalizedPointsLabel->setPixmap(matToQPixmap(pointsImg));

			calibrationMatrix.clear();
		}
	}
	else
	{
		ui.statusBar->showMessage(tc("Калибрация начнется через ") + QString::number(5 - countIteration) + tc(" сек."));

		if (countIteration == 5)
		{
			calibration = true;
			countIteration = 0;
		}
	}

	countIteration++;
}

QPixmap RecordMimicry::matToQPixmap(const cv::Mat& img)
{
	cv::Mat rgbImg;

	cvtColor(img, rgbImg, CV_BGR2RGB);

	QImage qImg = QImage((uchar*)rgbImg.data, rgbImg.cols, rgbImg.rows, rgbImg.step, QImage::Format_RGB888);

	return QPixmap::fromImage(qImg);
}

void RecordMimicry::startRecord()
{
	/*if (outputFilename.isEmpty())
	{
		QMessageBox::critical(this, tc("Ошибка"), tc("Файл для параметров анимации не задан"));
		return;
	}*/

	if (modeType == VideoWrite ||
		modeType == Webcam)
	{
		if (modeType == VideoWrite)
		{
			if (videoFilename.isEmpty())
			{
				QMessageBox::critical(this, tc("Ошибка"), tc("Файл для чтения не задан"));
				return;
			}

			QFile createVideoFile(videoFilename);
			createVideoFile.open(QIODevice::Truncate);
			createVideoFile.close();

			videoWriter.open(videoFilename.toLocal8Bit().constData(), CV_FOURCC('D','I','V','X'), 24, Size(640, 480), true);
			if (!videoWriter.isOpened())
			{
				QMessageBox::critical(this, "Error", "Cannot open video");
				return;
			}
		}

		cap.open(0);
		if (!cap.isOpened())
		{
			QMessageBox::critical(this, "Error", "Cannot open camera");
			return;
		}
	}
	else if (modeType == VideoRead)
	{
		if (videoFilename.isEmpty())
		{
			QMessageBox::critical(this, tc("Ошибка"), tc("Файл для чтения не задан"));
			return;
		}

		cap.open(videoFilename.toLocal8Bit().constData());
		if (!cap.isOpened())
		{
			QMessageBox::critical(this, "Error", "Cannot open video file");
			return;
		}
	}
	
	calibrationMatrix.clear();
	captureTimer->start(25);

	ui.stopRecordButton->setEnabled(true);
	ui.startRecordButton->setEnabled(false);
	ui.startCalibrationButton->setEnabled(false);

	ui.statusBar->showMessage(tc("Запись началась"));
}

void RecordMimicry::stopRecord()
{
	captureTimer->stop();
	cap.release();

	ui.stopRecordButton->setEnabled(false);
	ui.startRecordButton->setEnabled(true);
	ui.startCalibrationButton->setEnabled(true);

	ui.statusBar->showMessage(tc("Запись закончилась"));

	calibrationMatrix.insert(calibrationMatrix.begin(), calibrationPoints);
	csvWriter.open("smile_contempt.csv");
	csvWriter.writePoint<float>(calibrationMatrix);
	csvWriter.release();

	csvWriter.open("error.csv");
	csvWriter.writePoint<float>(errorPoints);
	csvWriter.release();
}

void RecordMimicry::startCalibration()
{
	cap.open(0);
	if (!cap.isOpened())
	{
		QMessageBox::critical(this, "Error", "Cannot open camera");
		return;
	}

	calibration = false;

	QMessageBox::information(this, tc("Калибрация"), tc("Сядьте перед камерой на расстоянии 35 сантиметров, примите нейтральное положение лица, "\
														"во время калибрации не двигайте головой, по истечению 5 секунд калибрация автоматически будет завершена."\
														"\n\nПосле нажатия кнопки «Ок», калибрация автоматически начнется через 5 секунд."));

	calibrationTimer->start(25);
	calibrationInformationTimer->start(1000);

	ui.stopRecordButton->setEnabled(false);
	ui.startRecordButton->setEnabled(false);
	ui.startCalibrationButton->setEnabled(false);

	calibrationMatrix.clear();
}

void RecordMimicry::modeChanged()
{
	if (ui.webcamButton->isChecked())
		modeType = Webcam;
	else if (ui.writeVideoButton->isChecked())
	{
		modeType = VideoWrite;

		videoFilename = QFileDialog::getSaveFileName(this, tc("Выберите файл для сохранения"), "", "AVI video file (*.avi)");
	}
	else if (ui.readVideoButton->isChecked())
	{
		modeType = VideoRead;

		videoFilename = QFileDialog::getOpenFileName(this, tc("Выберите файл для чтения"), "", "AVI video file (*.avi)");
	}
}

void RecordMimicry::outputFileDialog()
{
	QString filename = QFileDialog::getSaveFileName(this, tc("Выберите файл для сохранения параметров анимации"), "", "CSV file (*.csv)");

	if (!filename.isEmpty())
	{
		outputFilename = filename;
		ui.outputFileEdit->setText(outputFilename);
	}
}

void RecordMimicry::displayOptionsChanged()
{
	faceKeyPointsOption			= ui.faceKeyPointBox->isChecked();
	normalizedKeyPointsOption	= ui.normalizedKeyPointBox->isChecked();
	calibrationKeyPointsOption	= ui.calibrationKeyPointBox->isChecked();
}