#ifndef WAITDIALOG_H
#define WAITDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLayout>

class WaitDialog : public QDialog
{
	Q_OBJECT

public:
	WaitDialog(QWidget *parent);
	~WaitDialog();

private:
	QLabel* textLabel;
	QLabel* pictureLabel;
};

#endif // WAITDIALOG_H
