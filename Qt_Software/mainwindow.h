#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QTimer>
#include <QtSerialPort>
#include <QSerialPortInfo>

#define ADC_Channel_Num 2
#define VoltageQueueNum ADC_Channel_Num
#define ADC0    0
#define ADC1    1
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupSerialPlot(QCustomPlot *SerialPlot); //the function to setup the plot setting
    int Xrange;
    unsigned char Used_ADC_CH;
    double sampling_time;
    unsigned char channel_index;  //ADC channel index
public slots:
    void readVoltage();

private slots:
    void updatePlotData();  //function to update and refresh data on the graph
    char getADCChannel(unsigned char ADC_value);

    QColor SetCurveColor(unsigned char color);

    void on_SerialRunButton_clicked();

    void on_QuitButton_clicked();

    void on_MaxVoltEdit_textEdited(const QString &arg1);

    void on_MinVoltEdit_textEdited(const QString &arg1);

    void on_TimePeriodSlider_valueChanged(int value);

    void on_TimeRangespinBox_valueChanged(int arg1);

    void on_SerialConnectButton_clicked();

    void on_ADCCHspinBox_valueChanged(int arg1);

    void on_SamplingTimeEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;   
    QTimer timer;
    QElapsedTimer time; //it has nanosecond precision
//    QTime time;
    double key;//current time
    double lastPointKey; //previous time
    QSerialPort *serial_port;
    bool is_SerialOn;
    bool is_SerialConnected;


};

#endif // MAINWINDOW_H
