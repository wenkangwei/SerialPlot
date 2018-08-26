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
    is_SerialOn=false;          //Running state of serial plot
    is_SerialConnected=false;   //connection state
    channel_index=0;            //index used to iterate each ADC Channel
    key=0;                      // the value of the moment when voltage sampling occurs
    lastPointKey=0;
    Xrange=20.0;                //the range of X-Axis in graph
    sampling_time=0.001;        //in ms

    maxVolt=5.0;                //set maxVolt displayed on graph to 5V, minVolt to 0V
    minVolt=0;
    //initialize states of ADC channels and add graph
    for(int i=0; i < ADC_Channel_Num;i++){
	ADC_CH_state[i].is_enabled= false;
	ADC_CH_state[i].graph_index = -1;
    }

    //connect signal functions
    connect(serial_port,SIGNAL(readyRead()),this, SLOT(readVoltage()));

    //configure the settings of window
    setGeometry(400, 250, 600,450);
    //configure the plot
    setupSerialPlot(ui->serialPlot);
    std::cout<<"Graph num: "<<ui->serialPlot->graphCount()<<endl;

    //refresh window
    setWindowTitle("Serial data plot");
    statusBar()->clearMessage();

}


/**
 *@brief: getADCChannel:
 *  	obtain the ADC channel number from the Arduino data
 **/
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

       //get the ADC channel number
       if((ADC_Channel=getADCChannel(ADC_value))>-1 && ADC_Channel< ADC_Channel_Num){
            //read ADC data if the channel is enabled
           if(ADC_CH_state[ADC_Channel].is_enabled == true){
            //read ADC value
            ADC_value=SerialBuffer.at(index);
            index++;
            voltage_value=((float)(ADC_value&0x00FF)*5/253);


            // calculate two new data points:
            key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
            if(key-lastPointKey>=sampling_time){ //Set sampling time to 10ms
            ui->serialPlot->graph(ADC_CH_state[ADC_Channel].graph_index)->addData(key,(double)voltage_value);
            qDebug()<<"Key:"<<key<<"Voltage: "<<voltage_value<<endl;
            lastPointKey = key;
            }
            qDebug()<<"Channel:"<<ADC_Channel<<"ADC:"<<(unsigned char)ADC_value<<" Voltage:"<<voltage_value<<" V."<<endl;
            }
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
    int graph_index =-1;
    //setup all graph for given ADC channels
    for(int channel_index=0; channel_index< ADC_Channel_Num;channel_index++){
            if(ADC_CH_state[channel_index].graph_index == -1){
                //if graph is not created, create graph
                ui->serialPlot->addGraph();
                ADC_CH_state[channel_index].graph_index = ui->serialPlot->graphCount() -1;
            }
            graph_index =ADC_CH_state[channel_index].graph_index;
            ui->serialPlot->graph(graph_index)->setPen(QPen(SetCurveColor(channel_index)));
            //set graph name and legend name
            ui->serialPlot->graph(graph_index)->setName("ADC CH"+QString::number(channel_index));
            ui->serialPlot->graph(graph_index)->rescaleAxes(true);


	}
    //set legend
    SerialPlot->legend->setVisible(true);
    // configure coordinate settings
    SerialPlot->yAxis->setRange(0,5);
    SerialPlot->yAxis->setLabel("Voltage (V)");
    SerialPlot->xAxis->setLabel("Time(min:s:ms)");

    //Initialize display style of the graph
    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s:%z");
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
    static double lastFpsKey;
    static int frameCount;
    static double cleanData_timer = time.elapsed()/1000.0;
    key=time.elapsed()/1000.0;   //in s
    ui->serialPlot->xAxis->setLabel("Time(h:m:s:ms):"+ QTime::currentTime().toString("h:m:s:z"));
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
    // calculate frames per second:
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

    //clean data each 1 minute
    if(time.elapsed()/1000.0 - cleanData_timer >=60.0){
        double sorted_key = ui->serialPlot->xAxis->range().lower;
        //clean the data before the lower boundary along time axis
        for(int channel_index=0;channel_index<ADC_Channel_Num; channel_index++){
        ui->serialPlot->graph(ADC_CH_state[channel_index].graph_index)->data()->removeBefore(sorted_key);
        }
        cleanData_timer = time.elapsed()/1000.0;
    }
}

/**
 * @brief on_SerialRunButton_clicked:
 * 	Action when 'Run' button is clicked
 */

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


/**
 *@brief on_SerialConnectButton_clicked:
 * 	Action for (re)connecting the Arduino Serial port
 **/
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
           for(channel_index=0;channel_index<ui->serialPlot->graphCount();channel_index++){
               if(ADC_CH_state[channel_index].graph_index!= -1){
		    int graph_index = ADC_CH_state[channel_index].graph_index;
                    ui->serialPlot->graph(graph_index)->data()->clear();
		}
	}
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
           for(channel_index=0;channel_index<ADC_Channel_Num;channel_index++){
               if(ADC_CH_state[channel_index].graph_index!= -1){
		    int graph_index = ADC_CH_state[channel_index].graph_index;
                    ui->serialPlot->graph(graph_index)->data()->clear();
		}
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

/**
 *@brief on_QuitButton_clicked:
 *	action to close the program
 **/
void MainWindow::on_QuitButton_clicked()
{
    close();
}

/**
 * @brief on_MaxVoltEdit_textEdited
 * 	Action to set the maximum voltage scale in the graph
 **/
void MainWindow::on_MaxVoltEdit_textEdited(const QString &arg1)
{
    maxVolt =arg1.toFloat();
    //update range of y axis
    ui->serialPlot->yAxis->setRangeUpper(maxVolt);
    //update the position along y axis
    graph_pos = (maxVolt+minVolt)/2.0;
}

/**
 * @brief on_MinVoltEdit_textEdited
 * 	Action to set the minimum voltage scale in the graph
 **/
void MainWindow::on_MinVoltEdit_textEdited(const QString &arg1)
{
    minVolt = arg1.toFloat();
    //update range of y axis
    ui->serialPlot->yAxis->setRangeLower(minVolt);
    //update the position along y axis
    graph_pos = (maxVolt+minVolt)/2.0;
}




/**
 *@brief on_TimeRangespinBox_valueChanged
 * Action to change the range of x axis
 **/
void MainWindow::on_TimeRangespinBox_valueChanged(int arg1)
{
    if(arg1>0) Xrange=(double)arg1/1000.0;//convert ms to s
    ui->serialPlot->xAxis->setRange(key, Xrange, Qt::AlignRight);
    ui->serialPlot->replot();
}



/**
 *@brief PlotChannel_Controller
 *	It changes the states of the given ADC channel
 * @param channel_index:the number of the ADC channel needed controlling
 * @param checked:	the checked box state of the corresponding channel
 *
 **/
void MainWindow::PlotChannel_Controller(int channel_index, bool checked){
    int graph_index  =ADC_CH_state[channel_index].graph_index;
	if(checked == true){
        //update state and enable graph
	    ADC_CH_state[channel_index].is_enabled = true;
         ui->serialPlot->graph(graph_index)->setVisible(true);
	}
	else{
        if(graph_index!=-1){
            //disable graph
            ui->serialPlot->graph(graph_index)->setVisible(false);
        }
        else{
            qDebug()<<"No graph needed clearing "<<endl;
        }
	    //update state
	    ADC_CH_state[channel_index].is_enabled= false;
	
	}
	ui->serialPlot->replot();
}



/**
 * @brief on_SamplingTimeEdit_textChanged
 *       ACtion to change the sampling time 
 * 
 * */
void MainWindow::on_SamplingTimeEdit_textChanged(const QString &arg1)
{
    sampling_time=(arg1.toDouble())/1000.0; //convert ms to s
}



/**
 *@brief on_checkBox_CH0_clicked
 *   update the states of the ADC channel 0
 **/
void MainWindow::on_checkBox_CH0_clicked(bool checked)
{

	std::cout<<"CH0 state:"<<checked<<endl;
	if(ADC_Channel_Num>0){
        	PlotChannel_Controller(0, checked);
	}
}


/**
 *@brief on_checkBox_CH0_clicked
 *   update the states of the ADC channel 1
 **/
void MainWindow::on_checkBox_CH1_clicked(bool checked)
{

	std::cout<<"CH1 state:"<<checked<<endl;
	if(ADC_Channel_Num>1)
        PlotChannel_Controller(1, checked);

}

/**
 *@brief on_checkBox_CH0_clicked
 *   update the states of the ADC channel 2
 **/
void MainWindow::on_checkBox_CH2_clicked(bool checked)
{

	std::cout<<"CH2 state:"<<checked<<endl;
	if(ADC_Channel_Num > 2)
        PlotChannel_Controller(2,checked);
}





/**
 *@brief on_YPositionSlider_valueChanged
 * 	Action to move the position of the graph
 **/
void MainWindow::on_YPositionSlider_valueChanged(int value)
{
    float maxScale=(float) ui->YPositionSlider->maximum();
    //reset and update position of the graph
    ui->serialPlot->yAxis->setRange(minVolt,maxVolt);
    ui->serialPlot->yAxis->moveRange((double)((float)value/maxScale)*(maxVolt -minVolt));
    ui->serialPlot->replot();
}

/**
 *@brief on_XPositionSlider_valueChanged
 * 	Action to move the graph along x axis, which allows users to revisit
 *  the previous waveform
 **/
void MainWindow::on_XPositionSlider_valueChanged(int value)
{
    //find the first data point in the data queue
    double front_key= ui->serialPlot->graph(0)->data()->begin()->key;
     //calculate the key for display
     double rear_key = key;
     //update and refresh graph
     double new_position=((float)value/(float)ui->XPositionSlider->maximum())*(rear_key - front_key) + front_key;
     ui->serialPlot->xAxis->setRange(new_position,Xrange,Qt::AlignLeft);
     ui->serialPlot->replot();
}
