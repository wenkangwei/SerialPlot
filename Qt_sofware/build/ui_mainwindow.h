/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QCustomPlot *serialPlot;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QPushButton *SerialConnectButton;
    QPushButton *SerialRunButton;
    QPushButton *QuitButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *ADC_CH_groupBox;
    QCheckBox *checkBox_CH0;
    QCheckBox *checkBox_CH1;
    QCheckBox *checkBox_CH2;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *MaxVoltEdit;
    QLabel *label_2;
    QLineEdit *MinVoltEdit;
    QLabel *label_4;
    QSlider *YPositionSlider;
    QLabel *label_6;
    QSlider *XPositionSlider;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_3;
    QSpinBox *TimeRangespinBox;
    QLineEdit *SamplingTimeEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1281, 627);
        MainWindow->setMinimumSize(QSize(794, 584));
        MainWindow->setMaximumSize(QSize(1281, 627));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(666, 428));
        centralWidget->setMaximumSize(QSize(1461, 643));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        serialPlot = new QCustomPlot(centralWidget);
        serialPlot->setObjectName(QStringLiteral("serialPlot"));
        serialPlot->setEnabled(true);
        sizePolicy.setHeightForWidth(serialPlot->sizePolicy().hasHeightForWidth());
        serialPlot->setSizePolicy(sizePolicy);
        serialPlot->setMinimumSize(QSize(651, 331));
        serialPlot->setMaximumSize(QSize(1421, 421));

        verticalLayout->addWidget(serialPlot);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(91, 111));
        groupBox_3->setMaximumSize(QSize(91, 111));
        SerialConnectButton = new QPushButton(groupBox_3);
        SerialConnectButton->setObjectName(QStringLiteral("SerialConnectButton"));
        SerialConnectButton->setGeometry(QRect(0, 20, 85, 27));
        SerialConnectButton->setMaximumSize(QSize(85, 16777215));
        SerialRunButton = new QPushButton(groupBox_3);
        SerialRunButton->setObjectName(QStringLiteral("SerialRunButton"));
        SerialRunButton->setGeometry(QRect(0, 50, 85, 27));
        SerialRunButton->setMaximumSize(QSize(85, 16777215));
        QuitButton = new QPushButton(groupBox_3);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));
        QuitButton->setGeometry(QRect(0, 80, 85, 27));
        QuitButton->setMaximumSize(QSize(85, 16777215));

        verticalLayout_2->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ADC_CH_groupBox = new QGroupBox(centralWidget);
        ADC_CH_groupBox->setObjectName(QStringLiteral("ADC_CH_groupBox"));
        ADC_CH_groupBox->setMinimumSize(QSize(101, 111));
        ADC_CH_groupBox->setMaximumSize(QSize(101, 161));
        checkBox_CH0 = new QCheckBox(ADC_CH_groupBox);
        checkBox_CH0->setObjectName(QStringLiteral("checkBox_CH0"));
        checkBox_CH0->setGeometry(QRect(0, 20, 97, 22));
        checkBox_CH1 = new QCheckBox(ADC_CH_groupBox);
        checkBox_CH1->setObjectName(QStringLiteral("checkBox_CH1"));
        checkBox_CH1->setGeometry(QRect(0, 50, 97, 22));
        checkBox_CH2 = new QCheckBox(ADC_CH_groupBox);
        checkBox_CH2->setObjectName(QStringLiteral("checkBox_CH2"));
        checkBox_CH2->setGeometry(QRect(0, 80, 97, 22));

        verticalLayout_3->addWidget(ADC_CH_groupBox);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(291, 161));
        groupBox->setMaximumSize(QSize(16777215, 161));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 30, 85, 27));
        label->setMinimumSize(QSize(85, 27));
        MaxVoltEdit = new QLineEdit(groupBox);
        MaxVoltEdit->setObjectName(QStringLiteral("MaxVoltEdit"));
        MaxVoltEdit->setGeometry(QRect(110, 30, 174, 27));
        MaxVoltEdit->setMinimumSize(QSize(174, 27));
        MaxVoltEdit->setMaximumSize(QSize(174, 27));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(8, 60, 82, 27));
        label_2->setMinimumSize(QSize(82, 27));
        MinVoltEdit = new QLineEdit(groupBox);
        MinVoltEdit->setObjectName(QStringLiteral("MinVoltEdit"));
        MinVoltEdit->setGeometry(QRect(110, 60, 174, 27));
        MinVoltEdit->setMinimumSize(QSize(174, 27));
        MinVoltEdit->setMaximumSize(QSize(174, 27));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 90, 86, 29));
        label_4->setMinimumSize(QSize(86, 29));
        YPositionSlider = new QSlider(groupBox);
        YPositionSlider->setObjectName(QStringLiteral("YPositionSlider"));
        YPositionSlider->setGeometry(QRect(110, 90, 169, 29));
        YPositionSlider->setMinimumSize(QSize(169, 29));
        YPositionSlider->setMinimum(-100);
        YPositionSlider->setMaximum(100);
        YPositionSlider->setValue(0);
        YPositionSlider->setSliderPosition(0);
        YPositionSlider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 120, 86, 29));
        label_6->setMinimumSize(QSize(86, 29));
        XPositionSlider = new QSlider(groupBox);
        XPositionSlider->setObjectName(QStringLiteral("XPositionSlider"));
        XPositionSlider->setGeometry(QRect(110, 120, 171, 29));
        XPositionSlider->setMinimumSize(QSize(171, 29));
        XPositionSlider->setMaximum(100);
        XPositionSlider->setValue(100);
        XPositionSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(271, 121));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 30, 84, 27));
        label_5->setMinimumSize(QSize(84, 27));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 60, 98, 27));
        label_3->setMinimumSize(QSize(98, 27));
        TimeRangespinBox = new QSpinBox(groupBox_2);
        TimeRangespinBox->setObjectName(QStringLiteral("TimeRangespinBox"));
        TimeRangespinBox->setGeometry(QRect(100, 30, 169, 27));
        TimeRangespinBox->setMinimumSize(QSize(169, 27));
        TimeRangespinBox->setMaximumSize(QSize(169, 27));
        TimeRangespinBox->setMinimum(1);
        TimeRangespinBox->setMaximum(60000);
        SamplingTimeEdit = new QLineEdit(groupBox_2);
        SamplingTimeEdit->setObjectName(QStringLiteral("SamplingTimeEdit"));
        SamplingTimeEdit->setGeometry(QRect(100, 60, 169, 27));
        SamplingTimeEdit->setMinimumSize(QSize(169, 27));
        SamplingTimeEdit->setMaximumSize(QSize(169, 27));

        verticalLayout_4->addWidget(groupBox_2);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1281, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Start", 0));
        SerialConnectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        SerialRunButton->setText(QApplication::translate("MainWindow", "Run", 0));
        QuitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        ADC_CH_groupBox->setTitle(QApplication::translate("MainWindow", "Channels", 0));
        checkBox_CH0->setText(QApplication::translate("MainWindow", "CH0", 0));
        checkBox_CH1->setText(QApplication::translate("MainWindow", "CH1", 0));
        checkBox_CH2->setText(QApplication::translate("MainWindow", "CH2", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Dsiplay Settings", 0));
        label->setText(QApplication::translate("MainWindow", "Max Voltage", 0));
        MaxVoltEdit->setInputMask(QString());
        MaxVoltEdit->setText(QString());
        MaxVoltEdit->setPlaceholderText(QApplication::translate("MainWindow", "V", 0));
        label_2->setText(QApplication::translate("MainWindow", "Min Voltage", 0));
        MinVoltEdit->setText(QString());
        MinVoltEdit->setPlaceholderText(QApplication::translate("MainWindow", "V", 0));
        label_4->setText(QApplication::translate("MainWindow", "Move YPos", 0));
        label_6->setText(QApplication::translate("MainWindow", "Move XPos", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Sampling Settings", 0));
        label_5->setText(QApplication::translate("MainWindow", "Interval(ms):", 0));
        label_3->setText(QApplication::translate("MainWindow", "Sample speed", 0));
        SamplingTimeEdit->setText(QString());
        SamplingTimeEdit->setPlaceholderText(QApplication::translate("MainWindow", "sampling in ms", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
