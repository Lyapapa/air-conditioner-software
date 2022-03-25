#ifndef SENSORWINDOW_H
#define SENSORWINDOW_H


#include <QMainWindow>
#include<QWidget>
#include <QtWidgets>
#include <QApplication>
#include<QDoubleValidator>

#include "MainWindow.h"
#include "structs.h"



class SensorWindow : public QWidget
{
    Q_OBJECT

public:
    SensorWindow(QWidget *parent = nullptr);
    ~SensorWindow();
    void openSettingsXml();



private:
    MainWindow* myMainWindow;

    QLineEdit* Edit_temp;
    QLineEdit* Edit_humidity;
    QLineEdit* Edit_pressure;
    QGroupBox* gbx;
    QDoubleValidator* tempValidator;
    QDoubleValidator* humidityValidator;
    QDoubleValidator* pressureValidator;
    QLabel* Label_temp;
    QLabel* Label_humidity;
    QLabel* Label_pressure;
    QLabel* Label_tempUnit;
    QLabel* Label_humidityUnit;
    QLabel* Label_pressureUnit;
    QPushButton* PushButton_apply;

    QHBoxLayout* Layout_Sensor;
    QVBoxLayout* Layout_SensorTemp;
    QVBoxLayout* Layout_SensorHumidity;
    QVBoxLayout* Layout_SensorPressure;

    QVBoxLayout* Layout_Base;
    QHBoxLayout* Layout_main;
    QHBoxLayout* Layout_temp;
    QHBoxLayout* Layout_humidity;
    QHBoxLayout* Layout_pressure;
    void designWindow();
    void myConnections();

public slots:
    void slot_applyClicked();


signals:
    void signal_sensorInfo(setDataSensor &data);

};
#endif // SENSORWINDOW_H
