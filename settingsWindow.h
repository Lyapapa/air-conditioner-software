#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "MainWindow.h"
#include "structs.h"


class SettingsWindow : public QWidget
{
    Q_OBJECT

public:
    SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();
private:
    QVBoxLayout* layout_base;
    QVBoxLayout* layout_theme;
    QVBoxLayout* layout_units;
    QVBoxLayout* layout_unitsTemp;
    QVBoxLayout* layout_unitsPressure;
    QVBoxLayout* layout_stepSettingTemp;
    QGroupBox* groupBox_ColorTheme;
    QGroupBox* groupBox_Units;
    QGroupBox* groupBox_UnitsTemp;
    QGroupBox* groupBox_UnitsPressure;
    QGroupBox* groupBox_StepSettingTemp;
    QDoubleValidator* stepValidator;
    QPushButton* pushButton_darkTheme;
    QPushButton* pushButton_lightTheme;
    QPushButton* pushButton_unitsTempC;
    QPushButton* pushButton_unitsTempF;
    QPushButton* pushButton_unitsTempK;
    QPushButton* pushButton_unitsPressureKPA;
    QPushButton* pushButton_unitsPressureMM;
    QPushButton* pushButton_aplyStep;
    QPushButton* pushButton_saveSettings;
    QLineEdit* edit_stepSettingTemp;
    void designwindow();
    void myConnections();

    QPalette darkPalette;


public slots:
    void slot_pushButton_unitsTempC_Clicked();
    void slot_pushButton_unitsTempK_Clicked();
    void slot_pushButton_unitsTempF_Clicked();
    void slot_pushbutton_unitPressureMM_Clicked();
    void slot_pushbutton_unitPressureKPA_Cliked();
    void slot_editStepSettingTemp();
    void slot_pushButtonDarkThemeClicked();
    void slot_pushButtonLightThemeClicked();
    void slot_pushButtonSaveSettingsClicked();
signals:
    void signal_sendTempUnit(unitTemp &temp);
    void signal_sendPressureUnit(unitPressure &pressure);
    void signal_sendStepSettingTemp(double &step);
    void signal_saveSettings();


};
#endif // SETTINGSWINDOW_H
