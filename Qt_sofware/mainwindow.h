#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include <QTimer>
#include <QtSerialPort>
#include <QSerialPortInfo>

#define ADC_Channel_Num 3
#define VoltageQueueNum ADC_Channel_Num
#define ADC0    0
#define ADC1    1
namespace Ui {
class MainWindow;
}


typedef struct ChannelState{
bool is_enabled;
int graph_index;

} CHState;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupSerialPlot(QCustomPlot *SerialPlot); //the function to setup the plot setting
    double Xrange;
    unsigned char Used_ADC_CH;
    double sampling_time;
    unsigned char channel_index;  //ADC channel index
public slots:
    void readVoltage();

private slots:
    void updatePlotData();  //function to update and refresh data on the graph
    char getADCChannel(unsigned char ADC_value);
    void PlotChannel_Controller(int channel_index, bool checked);
    QColor SetCurveColor(unsigned char color);

    void on_SerialRunButton_clicked();

    void on_QuitButton_clicked();

    void on_MaxVoltEdit_textEdited(const QString &arg1);

    void on_MinVoltEdit_textEdited(const QString &arg1);

    void on_TimeRangespinBox_valueChanged(int arg1);

    void on_SerialConnectButton_clicked();

    void on_SamplingTimeEdit_textChanged(const QString &arg1);

    void on_checkBox_CH0_clicked(bool checked);

    void on_checkBox_CH1_clicked(bool checked);

    void on_checkBox_CH2_clicked(bool checked);
	

    void on_VoltPositionSlider_valueChanged(int value);

    void on_TimePositionSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;   
    QTimer timer;
    QElapsedTimer time; //it has nanosecond precision
    //    QTime time;
    double key;//current time in s
    double lastPointKey; //previous time in s
    QSerialPort *serial_port;
    bool is_SerialOn;
    bool is_SerialConnected;
    CHState ADC_CH_state[ADC_Channel_Num];
    float maxVolt;
    float minVolt;
    float graph_pos;
};

#endif // MAINWINDOW_H
