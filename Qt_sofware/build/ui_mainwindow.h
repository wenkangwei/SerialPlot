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
#include <QtWidgets/QFormLayout>
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
    QPushButton *SerialConnectButton;
    QPushButton *SerialRunButton;
    QPushButton *QuitButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *ADC_CH_groupBox;
    QCheckBox *checkBox_CH0;
    QCheckBox *checkBox_CH1;
    QCheckBox *checkBox_CH2;
    QFormLayout *formLayout;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *MaxVoltEdit;
    QLabel *label_2;
    QLineEdit *MinVoltEdit;
    QLabel *label_6;
    QSpinBox *ADCCHspinBox;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QSlider *TimePeriodSlider;
    QSpinBox *TimeRangespinBox;
    QLineEdit *SamplingTimeEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(931, 584);
        MainWindow->setMinimumSize(QSize(794, 584));
        MainWindow->setMaximumSize(QSize(1461, 703));
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

        verticalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        SerialConnectButton = new QPushButton(centralWidget);
        SerialConnectButton->setObjectName(QStringLiteral("SerialConnectButton"));

        verticalLayout_2->addWidget(SerialConnectButton);

        SerialRunButton = new QPushButton(centralWidget);
        SerialRunButton->setObjectName(QStringLiteral("SerialRunButton"));

        verticalLayout_2->addWidget(SerialRunButton);

        QuitButton = new QPushButton(centralWidget);
        QuitButton->setObjectName(QStringLiteral("QuitButton"));

        verticalLayout_2->addWidget(QuitButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        ADC_CH_groupBox = new QGroupBox(centralWidget);
        ADC_CH_groupBox->setObjectName(QStringLiteral("ADC_CH_groupBox"));
        ADC_CH_groupBox->setMinimumSize(QSize(101, 111));
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

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(291, 141));
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
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(7, 90, 93, 27));
        label_6->setMinimumSize(QSize(93, 27));
        ADCCHspinBox = new QSpinBox(groupBox);
        ADCCHspinBox->setObjectName(QStringLiteral("ADCCHspinBox"));
        ADCCHspinBox->setGeometry(QRect(110, 95, 174, 27));
        ADCCHspinBox->setMinimumSize(QSize(174, 27));
        ADCCHspinBox->setMaximumSize(QSize(174, 27));
        ADCCHspinBox->setMinimum(1);
        ADCCHspinBox->setMaximum(3);
        label->raise();
        MaxVoltEdit->raise();
        label_2->raise();
        MinVoltEdit->raise();
        label_6->raise();
        ADCCHspinBox->raise();
        serialPlot->raise();

        formLayout->setWidget(0, QFormLayout::FieldRole, groupBox);


        horizontalLayout->addLayout(formLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(271, 121));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 20, 86, 29));
        label_4->setMinimumSize(QSize(86, 29));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 50, 84, 27));
        label_5->setMinimumSize(QSize(84, 27));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 80, 98, 27));
        label_3->setMinimumSize(QSize(98, 27));
        TimePeriodSlider = new QSlider(groupBox_2);
        TimePeriodSlider->setObjectName(QStringLiteral("TimePeriodSlider"));
        TimePeriodSlider->setGeometry(QRect(100, 20, 169, 29));
        TimePeriodSlider->setMinimumSize(QSize(169, 29));
        TimePeriodSlider->setMaximumSize(QSize(169, 29));
        TimePeriodSlider->setOrientation(Qt::Horizontal);
        TimeRangespinBox = new QSpinBox(groupBox_2);
        TimeRangespinBox->setObjectName(QStringLiteral("TimeRangespinBox"));
        TimeRangespinBox->setGeometry(QRect(100, 50, 169, 27));
        TimeRangespinBox->setMinimumSize(QSize(169, 27));
        TimeRangespinBox->setMaximumSize(QSize(169, 27));
        TimeRangespinBox->setMinimum(1);
        TimeRangespinBox->setMaximum(100);
        SamplingTimeEdit = new QLineEdit(groupBox_2);
        SamplingTimeEdit->setObjectName(QStringLiteral("SamplingTimeEdit"));
        SamplingTimeEdit->setGeometry(QRect(100, 80, 169, 27));
        SamplingTimeEdit->setMinimumSize(QSize(169, 27));
        SamplingTimeEdit->setMaximumSize(QSize(169, 27));

        verticalLayout_4->addWidget(groupBox_2);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 931, 25));
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
        SerialConnectButton->setText(QApplication::translate("MainWindow", "Connect", 0));
        SerialRunButton->setText(QApplication::translate("MainWindow", "Run", 0));
        QuitButton->setText(QApplication::translate("MainWindow", "Quit", 0));
        ADC_CH_groupBox->setTitle(QApplication::translate("MainWindow", "ADC Channels", 0));
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
        label_6->setText(QApplication::translate("MainWindow", "ADC Channel:", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Sampling Settings", 0));
        label_4->setText(QApplication::translate("MainWindow", "Time period:", 0));
        label_5->setText(QApplication::translate("MainWindow", "Time range: ", 0));
        label_3->setText(QApplication::translate("MainWindow", "Sampling time", 0));
        SamplingTimeEdit->setText(QString());
        SamplingTimeEdit->setPlaceholderText(QApplication::translate("MainWindow", "ms", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
