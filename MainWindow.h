#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QWidget>
#include <QtWidgets>
#include <QApplication>
#include <QTimer>
#include <QtXml>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QXmlStreamAttribute>
#include <QFile>
#include "structs.h"
#include"settingsWindow.h"


class MainWindow : public QWidget//QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QLabel* label_SetTemp;
    QLabel* label_SettedTemp;
    QLabel* label_SetValueTemp;
    QLabel* label_SetValueTempUnit;
    QLabel* label_MeasuredHumidity;
    QLabel* label_MeasuredValueHumidity;
    QLabel* label_MeasuredValueHumidityUnit;
    QLabel* label_MeasuredTemp;
    QLabel* label_MeasuredValueTemp;
    QLabel* label_MeasuredValueTempUnit;
    QLabel* label_MeasuredPressure;
    QLabel* label_MeasuredValuePressure;
    QLabel* label_MeasuredValuePressureUnit;
    QLabel* label_SetAirflow;

    QGroupBox* groupbox_topLeft;
    QGroupBox* groupbox_topRight;
    QGroupBox* groupbox_midLeft;
    QGroupBox* groupbox_midCenter;
    QGroupBox* groupbox_midRight;
    QGroupBox* groupbox_downLeft;
    QGroupBox* groupbox_downRight;

    QPushButton* pushbutton_SetTempUp;
    QPushButton* pushbutton_SetTempDown;
    QPushButton* pushbutton_SetAirflowUp;
    QPushButton* pushbutton_SetAirflowMid;
    QPushButton* pushbutton_SetAirflowDown;
    QPushButton* pushbutton_SetOnOff;
    QPushButton* pushbutton_Settings;
    QPushButton* pushbutton_Faq;
    QTimer* MyTimer;

private:
    void designWindow();
    void myConnections();



public:
    /*!
     * \brief currentunittemp - температура-25     */
    unitTemp currentunittemp=CURRENT_UNIT_TEMP_C;
    unitPressure currentunitpressure=CURRENT_UNIT_PRESSURE_KPA;
    airflowDirection currentAirflowDirection=CURRENT_DIRECTION_MID;
    double stepSettingTemp=1.0;

    void openSettingsXml();



public slots:
    void slot_receiveSensorInfo(setDataSensor &data);
    void slot_timerTikTak();
    void slot_onOffClicked();
    void slot_settingsClicked();
    void slot_receivedUnitTempFromSettings(unitTemp&);
    void slot_receivedUnitPressureFromSettings(unitPressure&);
    void slot_pushButtonPlusClicked();
    void slot_pushButtonMinusClicked();
    void slot_pushButtonFaqClicked();
    void slot_receivedStepSettingTemp(double&);
    void slot_airFlowUpClicked();
    void slot_airflowMidClicked();
    void slot_airflowDownClicked();
    void slot_saveSettingsXml();


};
#endif // MAINWINDOW_H
