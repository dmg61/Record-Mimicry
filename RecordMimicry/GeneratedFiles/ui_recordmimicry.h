/********************************************************************************
** Form generated from reading UI file 'recordmimicry.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDMIMICRY_H
#define UI_RECORDMIMICRY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RecordMimicryClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *videoLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *startCalibrationButton;
    QPushButton *startRecordButton;
    QPushButton *stopRecordButton;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *outputFileEdit;
    QToolButton *outputFileButton;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *webcamButton;
    QRadioButton *writeVideoButton;
    QRadioButton *readVideoButton;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout;
    QCheckBox *faceKeyPointBox;
    QCheckBox *normalizedKeyPointBox;
    QCheckBox *calibrationKeyPointBox;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QLabel *normalizedPointsLabel;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RecordMimicryClass)
    {
        if (RecordMimicryClass->objectName().isEmpty())
            RecordMimicryClass->setObjectName(QStringLiteral("RecordMimicryClass"));
        RecordMimicryClass->resize(512, 372);
        centralWidget = new QWidget(RecordMimicryClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_5 = new QHBoxLayout(centralWidget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        videoLabel = new QLabel(groupBox_2);
        videoLabel->setObjectName(QStringLiteral("videoLabel"));

        horizontalLayout_2->addWidget(videoLabel);


        verticalLayout_2->addWidget(groupBox_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        startCalibrationButton = new QPushButton(centralWidget);
        startCalibrationButton->setObjectName(QStringLiteral("startCalibrationButton"));

        horizontalLayout_3->addWidget(startCalibrationButton);

        startRecordButton = new QPushButton(centralWidget);
        startRecordButton->setObjectName(QStringLiteral("startRecordButton"));
        startRecordButton->setEnabled(false);

        horizontalLayout_3->addWidget(startRecordButton);

        stopRecordButton = new QPushButton(centralWidget);
        stopRecordButton->setObjectName(QStringLiteral("stopRecordButton"));
        stopRecordButton->setEnabled(false);

        horizontalLayout_3->addWidget(stopRecordButton);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 53));
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        outputFileEdit = new QLineEdit(groupBox_4);
        outputFileEdit->setObjectName(QStringLiteral("outputFileEdit"));
        outputFileEdit->setReadOnly(true);

        horizontalLayout_4->addWidget(outputFileEdit);

        outputFileButton = new QToolButton(groupBox_4);
        outputFileButton->setObjectName(QStringLiteral("outputFileButton"));

        horizontalLayout_4->addWidget(outputFileButton);


        verticalLayout_3->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout_4 = new QVBoxLayout(groupBox_5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        webcamButton = new QRadioButton(groupBox_5);
        webcamButton->setObjectName(QStringLiteral("webcamButton"));
        webcamButton->setChecked(true);

        verticalLayout_4->addWidget(webcamButton);

        writeVideoButton = new QRadioButton(groupBox_5);
        writeVideoButton->setObjectName(QStringLiteral("writeVideoButton"));

        verticalLayout_4->addWidget(writeVideoButton);

        readVideoButton = new QRadioButton(groupBox_5);
        readVideoButton->setObjectName(QStringLiteral("readVideoButton"));

        verticalLayout_4->addWidget(readVideoButton);


        verticalLayout_3->addWidget(groupBox_5);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout = new QVBoxLayout(groupBox_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        faceKeyPointBox = new QCheckBox(groupBox_3);
        faceKeyPointBox->setObjectName(QStringLiteral("faceKeyPointBox"));

        verticalLayout->addWidget(faceKeyPointBox);

        normalizedKeyPointBox = new QCheckBox(groupBox_3);
        normalizedKeyPointBox->setObjectName(QStringLiteral("normalizedKeyPointBox"));
        normalizedKeyPointBox->setStyleSheet(QStringLiteral(";"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/RecordMimicry/test.png"), QSize(), QIcon::Normal, QIcon::Off);
        normalizedKeyPointBox->setIcon(icon);
        normalizedKeyPointBox->setIconSize(QSize(10, 10));
        normalizedKeyPointBox->setChecked(true);

        verticalLayout->addWidget(normalizedKeyPointBox);

        calibrationKeyPointBox = new QCheckBox(groupBox_3);
        calibrationKeyPointBox->setObjectName(QStringLiteral("calibrationKeyPointBox"));
        calibrationKeyPointBox->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/RecordMimicry/Vayu.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        calibrationKeyPointBox->setIcon(icon1);
        calibrationKeyPointBox->setIconSize(QSize(10, 10));
        calibrationKeyPointBox->setChecked(true);

        verticalLayout->addWidget(calibrationKeyPointBox);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        normalizedPointsLabel = new QLabel(groupBox);
        normalizedPointsLabel->setObjectName(QStringLiteral("normalizedPointsLabel"));

        horizontalLayout->addWidget(normalizedPointsLabel);


        verticalLayout_3->addWidget(groupBox);


        horizontalLayout_5->addLayout(verticalLayout_3);

        RecordMimicryClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RecordMimicryClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 512, 21));
        RecordMimicryClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(RecordMimicryClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        RecordMimicryClass->setStatusBar(statusBar);

        retranslateUi(RecordMimicryClass);

        QMetaObject::connectSlotsByName(RecordMimicryClass);
    } // setupUi

    void retranslateUi(QMainWindow *RecordMimicryClass)
    {
        RecordMimicryClass->setWindowTitle(QApplication::translate("RecordMimicryClass", "Record Mimicry", 0));
        groupBox_2->setTitle(QApplication::translate("RecordMimicryClass", "\320\230\321\201\321\205\320\276\320\264\320\275\320\276\320\265 \320\262\320\270\320\264\320\265\320\276", 0));
        videoLabel->setText(QApplication::translate("RecordMimicryClass", "TextLabel", 0));
        startCalibrationButton->setText(QApplication::translate("RecordMimicryClass", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260", 0));
        startRecordButton->setText(QApplication::translate("RecordMimicryClass", "\320\241\321\202\320\260\321\200\321\202", 0));
        stopRecordButton->setText(QApplication::translate("RecordMimicryClass", "\320\241\321\202\320\276\320\277", 0));
        groupBox_4->setTitle(QApplication::translate("RecordMimicryClass", "\320\222\321\213\321\205\320\276\320\264\320\275\320\276\320\271 \321\204\320\260\320\271\320\273", 0));
        label->setText(QApplication::translate("RecordMimicryClass", "\320\237\321\203\321\202\321\214", 0));
        outputFileButton->setText(QApplication::translate("RecordMimicryClass", "...", 0));
        groupBox_5->setTitle(QApplication::translate("RecordMimicryClass", "\320\240\320\265\320\266\320\270\320\274", 0));
        webcamButton->setText(QApplication::translate("RecordMimicryClass", "Web - \320\272\320\260\320\274\320\265\321\200\320\260", 0));
        writeVideoButton->setText(QApplication::translate("RecordMimicryClass", "\320\227\320\260\320\277\320\270\321\201\321\214 \320\262\320\270\320\264\320\265\320\276 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        readVideoButton->setText(QApplication::translate("RecordMimicryClass", "\320\247\321\202\320\265\320\275\320\270\320\265 \320\262\320\270\320\264\320\265\320\276 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        groupBox_3->setTitle(QApplication::translate("RecordMimicryClass", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\276\321\202\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\321\217", 0));
        faceKeyPointBox->setText(QApplication::translate("RecordMimicryClass", "\320\232\320\273\321\216\321\207\320\265\320\262\321\213\320\265 \321\202\320\276\321\207\320\272\320\270 \320\275\320\260 \320\273\320\270\321\206\320\265", 0));
        normalizedKeyPointBox->setText(QApplication::translate("RecordMimicryClass", "\320\235\320\276\321\200\320\274\320\260\320\273\320\270\320\267\320\276\320\262\320\260\320\275\320\275\321\213\320\265 \320\272\320\273\321\216\321\207\320\265\320\262\321\213\320\265 \321\202\320\276\321\207\320\272\320\270", 0));
        calibrationKeyPointBox->setText(QApplication::translate("RecordMimicryClass", "\320\236\321\202\320\272\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\265 \320\272\320\273\321\216\321\207\320\265\320\262\321\213\320\265 \321\202\320\276\321\207\320\272\320\270", 0));
        groupBox->setTitle(QApplication::translate("RecordMimicryClass", "\320\235\320\276\321\200\320\274\320\260\320\273\320\270\320\267\320\276\320\262\320\260\320\275\320\275\321\213\320\265 \320\272\320\273\321\216\321\207\320\265\320\262\321\213\320\265 \321\202\320\276\321\207\320\272\320\270", 0));
        normalizedPointsLabel->setText(QApplication::translate("RecordMimicryClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class RecordMimicryClass: public Ui_RecordMimicryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDMIMICRY_H
