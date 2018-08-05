#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QDebug>
using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*-----------------Initialization-------------------*/
    ui->setupUi(this);
    serial_port=new QSerialPort();
    is_SerialOn=false;
    is_SerialConnected=false;

    channel_index=0;            //index used to iterate each ADC Channel
    key=0;                      // the value of the moment when voltage sampling occurs
    lastPointKey=0;
    Xrange=20;                 //the range of X-Axis
    Used_ADC_CH=1;
    sampling_time=0.001;       //in ms

    //connect signal functions
    connect(serial_port,SIGNAL(readyRead()),this, SLOT(readVoltage()));

    //setup Serial graph
    //configure the settings of window
    setGeometry(400, 250, 600,450);
    //configure the plot
    setupSerialPlot(ui->serialPlot);
    //refresh window
    setWindowTitle("Serial data plot");
    statusBar()->clearMessage();

}

char MainWindow::getADCChannel(unsigned char ADC_value)
{

    switch(ADC_value)
    {
        case 255: return 0;
        case 254: return 1;
        case 253: return 2;
        default: return -1;
    }
    return -1;
}


/**
 * @brief readVoltage: it reads the sampled ADC data sent from Arduino
 *                      and add data to graph
 * @note: the serial data reception speed of readAll() is much faster than read()
 *
 * */
void MainWindow::readVoltage()
{
    char ADC_value=0;
    float voltage_value=0;
    int ADC_Channel=-1; //used as index of ADC
    QByteArray SerialBuffer;
    int index=0;

    //receive data when data is available
    if(serial_port->bytesAvailable()>0)
    {
        //read ADC value from serial port
       SerialBuffer= serial_port->readAll();
       //iterate the Array to obtain ADC value of different Channels
       while(index<SerialBuffer.length()-1){
        ADC_value=SerialBuffer.at(index);
        index++;
//        qDebug()<<"Received:"<<(unsigned char)ADC_value<<"Buffer:"<<SerialBuffer.length()<<endl;
       //get the ADC channel number
       if((ADC_Channel=getADCChannel(ADC_value))!=-1 && ADC_Channel<Used_ADC_CH){
            //read ADC value
            ADC_value=SerialBuffer.at(index);
            index++;
            voltage_value=((float)(ADC_value&0x00FF)*5/253);
            // calculate two new data points:
            key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
            if(key-lastPointKey>=sampling_time){ //Set sampling time to 10ms
            ui->serialPlot->graph(ADC_Channel)->addData(key,(double)voltage_value);
            qDebug()<<"Key:"<<key<<"Voltage: "<<voltage_value<<endl;
            lastPointKey = key;
            }
            qDebug()<<"Channel:"<<ADC_Channel<<"ADC:"<<(unsigned char)ADC_value<<" Voltage:"<<voltage_value<<" V."<<endl;
            }
       }
        //release buffer
        SerialBuffer.clear();
     }
    else{
        qDebug()<<"Bytes not available"<<endl;
    }
}

MainWindow::~MainWindow()
{
    delete serial_port;
    delete ui;
}

/**
 * @brief SetCurveColor: This function is to return the QColor object with different color
 *                          settings based on the given value
 * @color: this is the value to choose which QColor object should be returned
 * @return: it returns QColor object
 *
 **/
QColor MainWindow::SetCurveColor(unsigned char color)
{
    switch(color)
    {
        case 0:return QColor(255,0,0);
        case 1:return QColor(0,255,0);
        case 2:return QColor(0,0,255);
        case 3:return QColor(225,225,0);
        default:return QColor(0,0,0);
    }
return QColor(0,0,0);

}

/**
 * @brief setupSerialPlot: configure the graph settings of legend, labels,curve
 * @param *SerialPlot: the QCustomPlot object needed to be configured
 **/
void MainWindow::setupSerialPlot(QCustomPlot *SerialPlot)
{
    //create graph sheets
    for(channel_index=0;channel_index<Used_ADC_CH;channel_index++){
        SerialPlot->addGraph();
        SerialPlot->graph(channel_index)->setPen(QPen(SetCurveColor(channel_index)));

        //set graph name and legend name
        SerialPlot->graph(channel_index)->setName("ADC CH"+QString::number(channel_index));
        SerialPlot->graph(channel_index)->rescaleAxes(true);
    }
    //set legend
    SerialPlot->legend->setVisible(true);
    // configure coordinate settings
    SerialPlot->yAxis->setRange(-0.5,6);
    SerialPlot->yAxis->setLabel("Voltage (V)");
    SerialPlot->xAxis->setLabel("Time");

    //Initialize display style of the graph
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    SerialPlot->xAxis->setTicks(true);
    timeTicker->setTickCount(5);
    SerialPlot->xAxis->setTicker(timeTicker);
    SerialPlot->axisRect()->setupFullAxesBox();
    ui->serialPlot->xAxis->setRange(0, Xrange, Qt::AlignLeft);
    ui->serialPlot->replot();
    //setup signal connection
    connect(SerialPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), SerialPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(SerialPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), SerialPlot->yAxis2, SLOT(setRange(QCPRange)));
    connect(&timer,SIGNAL(timeout()),this,SLOT(updatePlotData()));


}

/**
 * @brief updatePlotData: refresh and update graph once the timer timeout.
 *                        time to timeout=1ms
 *
 * */
void MainWindow::updatePlotData()
{
    // calculate frames per second:
    static double lastFpsKey;
    static int frameCount;

    key=time.elapsed()/1000.0;   //in s
    ui->serialPlot->xAxis->setLabel("Time:"+ QTime::currentTime().toString("h:m:s"));
    //replot data set each 1ms
    if (key-lastPointKey > 0.001)
    {
        // update graph data
        if(key>=Xrange)
            ui->serialPlot->xAxis->setRange(key, Xrange, Qt::AlignRight);
        //refresh graph each 1ms
        ui->serialPlot->replot();
        //refresh graph
        lastPointKey=key;
     }

    //FPS calculation
    ++frameCount;
    if (key-lastFpsKey > 2) // average fps over 2 seconds
    {
      ui->statusBar->showMessage(
            QString("%1 FPS, Total Data points: %2")
            .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
            .arg(ui->serialPlot->graph(0)->data()->size())
            , 0);
      lastFpsKey = key;
      frameCount = 0;
    }

}



void MainWindow::on_SerialRunButton_clicked()
{
    //if Serial is connected
 if(is_SerialConnected){
        if(!is_SerialOn){// if Serial isn't running and "Run " is clicked
           is_SerialOn=true;
           ui->SerialRunButton->setText("Stop");
           timer.start(0);
           //update graph to the last graph
           if(time.elapsed()/1000.0>=Xrange)
                ui->serialPlot->xAxis->setRange(time.elapsed()/1000.0, Xrange, Qt::AlignRight);
           ui->serialPlot->replot();
        }
        else{//if "Stop" is clicked when serial connection is on
            is_SerialOn=false;
            ui->SerialRunButton->setText("Run");
            timer.stop();

        }
   }

}

void MainWindow::on_SerialConnectButton_clicked()
{
    //reset run button
    is_SerialOn=false;
    ui->SerialRunButton->setText("Run");

    if(serial_port->isOpen())
    {
        //stop serial port
        is_SerialConnected=false;
        ui->SerialConnectButton->setText("Connect");
        //stop plot data
        timer.stop();
        serial_port->close();
        //clean data
        for(channel_index=0;channel_index<Used_ADC_CH;channel_index++){
            ui->serialPlot->graph(channel_index)->data()->clear();
        }
        qDebug()<<"voltage queue cleaned"<<endl;
    }
    else{

        /*----------------Reconnect  serial port-----------------------*/
        QSerialPortInfo info("ttyACM0");
        //output serial device info
        qDebug()<<"Serial number: "<< info.serialNumber();
        qDebug()<< "Name: "<< info.portName();
        qDebug()<< "Manufacturer: "<< info.manufacturer();
        qDebug()<< "Busy: "<< info.isBusy();
        //initialize Serial module
        serial_port->setPortName("ttyACM0");
        serial_port->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
        serial_port->setDataBits(QSerialPort::Data8);
        serial_port->setStopBits(QSerialPort::OneStop);
        serial_port->setFlowControl(QSerialPort::NoFlowControl);
        serial_port->setParity(QSerialPort::NoParity);
       if( serial_port->open(QSerialPort::ReadWrite)){
           //re-open serial port
           ui->SerialConnectButton->setText("Disconnect");
           qDebug().noquote()<<"Com opened successfully"<<endl;
           if(serial_port->isWritable())
           {
             qDebug().noquote()<<"Com is writable now"<<endl;
           }
           if(serial_port->isReadable())
           {
               //read data here
               qDebug().noquote()<<"Com is readable now"<<endl;
            }
             is_SerialConnected=true;
           //reset key of voltage data and real-time clock
           key=lastPointKey=0;
           time.restart();
           //Clean data
           for(channel_index=0;channel_index<ui->serialPlot->graphCount();channel_index++){
               ui->serialPlot->graph(channel_index)->data()->clear();
           }
           //Clean graph
           ui->serialPlot->xAxis->setRange(time.elapsed()/1000.0, Xrange, Qt::AlignLeft);
           ui->serialPlot->replot();
       }
       else{
           qDebug()<<"COM connection fail "<<endl;
       }
    }
}


void MainWindow::on_QuitButton_clicked()
{
    close();
}

void MainWindow::on_MaxVoltEdit_textEdited(const QString &arg1)
{
    ui->serialPlot->yAxis->setRangeUpper(arg1.toDouble());
}

void MainWindow::on_MinVoltEdit_textEdited(const QString &arg1)
{
    ui->serialPlot->yAxis->setRangeLower(arg1.toDouble());

}

void MainWindow::on_TimePeriodSlider_valueChanged(int value)
{
ui->serialPlot->xAxis->setNumberPrecision(value);
}

void MainWindow::on_TimeRangespinBox_valueChanged(int arg1)
{
    if(arg1>0) Xrange=arg1;
}


void MainWindow::on_ADCCHspinBox_valueChanged(int arg1)
{

    if(arg1>Used_ADC_CH){
        //add new graphs
        for(channel_index=Used_ADC_CH;channel_index<arg1;channel_index++){
            ui->serialPlot->addGraph();
            ui->serialPlot->graph(channel_index)->setPen(QPen(SetCurveColor(channel_index)));
            //set graph name and legend name
            ui->serialPlot->graph(channel_index)->setName("ADC CH"+QString::number(channel_index));
            ui->serialPlot->graph(channel_index)->rescaleAxes(true);

        }
    }
    else if(arg1<Used_ADC_CH){
        //delete graphs
        for(channel_index=Used_ADC_CH-1;channel_index>arg1-1;channel_index--){
            ui->serialPlot->graph(channel_index)->data()->clear();//clear graph data
            ui->serialPlot->removeGraph(channel_index);           //remove graph
        }
    }
    Used_ADC_CH=(unsigned char)arg1;
    ui->serialPlot->replot();
}

/**
 * @brief 
 * 
 * */
void MainWindow::on_SamplingTimeEdit_textChanged(const QString &arg1)
{
    sampling_time=(arg1.toDouble())/1000.0; //convert ms to s
}
