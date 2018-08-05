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
#include <QtWidgets/QFormLayout>
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
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *MaxVoltEdit;
    QLabel *label_2;
    QLineEdit *MinVoltEdit;
    QLabel *label_6;
    QSpinBox *ADCCHspinBox;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QSlider *TimePeriodSlider;
    QLabel *label_5;
    QSpinBox *TimeRangespinBox;
    QLabel *label_3;
    QLineEdit *SamplingTimeEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(669, 584);
        MainWindow->setMinimumSize(QSize(666, 543));
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

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        MaxVoltEdit = new QLineEdit(centralWidget);
        MaxVoltEdit->setObjectName(QStringLiteral("MaxVoltEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, MaxVoltEdit);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        MinVoltEdit = new QLineEdit(centralWidget);
        MinVoltEdit->setObjectName(QStringLiteral("MinVoltEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, MinVoltEdit);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_6);

        ADCCHspinBox = new QSpinBox(centralWidget);
        ADCCHspinBox->setObjectName(QStringLiteral("ADCCHspinBox"));
        ADCCHspinBox->setMinimum(1);
        ADCCHspinBox->setMaximum(3);

        formLayout->setWidget(3, QFormLayout::FieldRole, ADCCHspinBox);


        horizontalLayout->addLayout(formLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        TimePeriodSlider = new QSlider(centralWidget);
        TimePeriodSlider->setObjectName(QStringLiteral("TimePeriodSlider"));
        TimePeriodSlider->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, TimePeriodSlider);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_5);

        TimeRangespinBox = new QSpinBox(centralWidget);
        TimeRangespinBox->setObjectName(QStringLiteral("TimeRangespinBox"));
        TimeRangespinBox->setMinimum(1);
        TimeRangespinBox->setMaximum(100);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, TimeRangespinBox);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        SamplingTimeEdit = new QLineEdit(centralWidget);
        SamplingTimeEdit->setObjectName(QStringLiteral("SamplingTimeEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, SamplingTimeEdit);


        horizontalLayout->addLayout(formLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 669, 25));
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
        label->setText(QApplication::translate("MainWindow", "Max Voltage", 0));
        MaxVoltEdit->setInputMask(QString());
        MaxVoltEdit->setText(QString());
        MaxVoltEdit->setPlaceholderText(QApplication::translate("MainWindow", "V", 0));
        label_2->setText(QApplication::translate("MainWindow", "Min Voltage", 0));
        MinVoltEdit->setText(QString());
        MinVoltEdit->setPlaceholderText(QApplication::translate("MainWindow", "V", 0));
        label_6->setText(QApplication::translate("MainWindow", "ADC Channel:", 0));
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
