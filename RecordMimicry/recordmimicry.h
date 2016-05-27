#ifndef RECORDMIMICRY_H
#define RECORDMIMICRY_H

#include <QtWidgets/QMainWindow>
#include "ui_recordmimicry.h"
#include "QTimer"
#include "QMessageBox"
#include "QProgressDialog"
#include <QString>
#include <QTextCodec>
#include <QFileDialog>
#include "ImageProcess.h"
#include "waitdialog.h"
#include "CsvWriter.h"

using namespace std;
using namespace cv;

#define tc(str) codec->toUnicode(str)

enum ModeType
{
	Webcam,
	VideoRead,
	VideoWrite
};

class RecordMimicry : public QMainWindow
{
	Q_OBJECT

public:
	RecordMimicry(QWidget *parent = 0);
	~RecordMimicry();

private:
	Ui::RecordMimicryClass ui;
	QString outputFilename;
	QString videoFilename;
	bool faceKeyPointsOption;
	bool normalizedKeyPointsOption;
	bool calibrationKeyPointsOption;
	ModeType modeType;
	QTimer* captureTimer;
	QTimer* calibrationTimer;
	QTimer* calibrationInformationTimer;
	VideoCapture cap;
	VideoWriter videoWriter;
	CsvWriter csvWriter;
	ImageProcess ip;
	PointArray calibrationPoints;
	PointArray errorPoints;
	WaitDialog* pwd;
	QTextCodec* codec;

	PointMatrix calibrationMatrix;
	bool calibration;

private:
	QPixmap matToQPixmap(const cv::Mat& img);

private slots:
	void startRecord();
	void stopRecord();
	void startCalibration();
	void modeChanged();
	void outputFileDialog();
	void displayOptionsChanged();

	void captureProcess();
	void calibrationProcess();
	void calibrationInformationProcess();
};

#endif // RECORDMIMICRY_H
