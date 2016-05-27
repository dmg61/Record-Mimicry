#include "waitdialog.h"

WaitDialog::WaitDialog(QWidget *parent)
	: QDialog(parent)
{
	textLabel    = new QLabel("Please wait ...");
	pictureLabel = new QLabel("Azazaza");

	QHBoxLayout* mainLayout = new QHBoxLayout;
	mainLayout->addWidget(textLabel);
	mainLayout->addWidget(pictureLabel);
	setLayout(mainLayout);

	setWindowTitle("Please wait ...");
	//setFixedHeight(sizeHint().height());
}

WaitDialog::~WaitDialog()
{
	delete textLabel;
	delete pictureLabel;
}
