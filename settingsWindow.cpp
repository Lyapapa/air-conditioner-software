#include"settingsWindow.h"

/*!
 * \brief SettingsWindow::SettingsWindow
 * класс отвечающий за окно настройки приложения и работы с ним
 * \param parent
 */
SettingsWindow::SettingsWindow(QWidget *parent)
    : QWidget(parent)
{
    designwindow();
    myConnections();
}
SettingsWindow::~SettingsWindow()
{
}
/*!
 * \brief SettingsWindow::myConnections
 * метод содержащий все соединения
 */
void SettingsWindow::myConnections()
{
    MainWindow* myMainWindow=new MainWindow();

    QObject::connect(pushButton_unitsTempC, &QPushButton::clicked, this, &SettingsWindow::slot_pushButton_unitsTempC_Clicked);
    QObject::connect(pushButton_unitsTempK, &QPushButton::clicked, this, &SettingsWindow::slot_pushButton_unitsTempK_Clicked);
    QObject::connect(pushButton_unitsTempF, &QPushButton::clicked, this, &SettingsWindow::slot_pushButton_unitsTempF_Clicked);
    QObject::connect(pushButton_unitsPressureKPA, &QPushButton::clicked, this, &SettingsWindow::slot_pushbutton_unitPressureKPA_Cliked);
    QObject::connect(pushButton_unitsPressureMM, &QPushButton::clicked, this, &SettingsWindow::slot_pushbutton_unitPressureMM_Clicked);
    QObject::connect(pushButton_aplyStep, &QPushButton::clicked, this, &SettingsWindow::slot_editStepSettingTemp);
    QObject::connect(this, &SettingsWindow::signal_sendStepSettingTemp, myMainWindow, &MainWindow::slot_receivedStepSettingTemp);
    QObject::connect(pushButton_darkTheme, &QPushButton::clicked, this, &SettingsWindow::slot_pushButtonDarkThemeClicked);
    QObject::connect(pushButton_lightTheme, &QPushButton::clicked, this, &SettingsWindow::slot_pushButtonLightThemeClicked);
    QObject::connect(pushButton_saveSettings, &QPushButton::clicked, this, &SettingsWindow::slot_pushButtonSaveSettingsClicked);
}
/*!
 * \brief SettingsWindow::designwindow
 * метод отвечающий за окно настройки иформирование виджетов окна
 */
void SettingsWindow::designwindow()
{
    layout_base=new QVBoxLayout;
    layout_theme=new QVBoxLayout;
    layout_units=new QVBoxLayout;
    layout_unitsTemp=new QVBoxLayout;
    layout_unitsPressure=new QVBoxLayout;
    layout_stepSettingTemp=new QVBoxLayout;

    groupBox_ColorTheme = new QGroupBox("Цветовая тема");
    groupBox_Units = new QGroupBox("Единицы измерения");
    groupBox_UnitsTemp = new QGroupBox("Единицы измерения температуры");
    groupBox_UnitsPressure = new QGroupBox("Единицы измерения давления");
    groupBox_StepSettingTemp=new QGroupBox("Шаг установки температуры");

    pushButton_darkTheme=new QPushButton("Темная тема");
    pushButton_lightTheme=new QPushButton("Светлая тема");
    pushButton_unitsTempC=new QPushButton("°С");
    pushButton_unitsTempF=new QPushButton("°F");
    pushButton_unitsTempK=new QPushButton("°K");
    pushButton_unitsPressureKPA=new QPushButton("кПа");
    pushButton_unitsPressureMM=new QPushButton("мм.рт.ст.");
    pushButton_aplyStep=new QPushButton("Применить");
    pushButton_saveSettings=new QPushButton("Сохранить");


    stepValidator=new QDoubleValidator(0.0, 100, 2);

    edit_stepSettingTemp=new QLineEdit();
    edit_stepSettingTemp->setValidator(stepValidator);

    layout_base->addWidget(groupBox_ColorTheme);
     groupBox_ColorTheme->setLayout(layout_theme);
         layout_theme->addWidget(pushButton_lightTheme);
         layout_theme->addWidget(pushButton_darkTheme);
    layout_base->addWidget(groupBox_StepSettingTemp);
     groupBox_StepSettingTemp->setLayout(layout_stepSettingTemp);
         layout_stepSettingTemp->addWidget(edit_stepSettingTemp);
         layout_stepSettingTemp->addWidget(pushButton_aplyStep);
    layout_base->addWidget(groupBox_Units);
     groupBox_Units->setLayout(layout_units);
         layout_units->addWidget(groupBox_UnitsTemp);
             groupBox_UnitsTemp->setLayout(layout_unitsTemp);
                 layout_unitsTemp->addWidget(pushButton_unitsTempC);
                 layout_unitsTemp->addWidget(pushButton_unitsTempF);
                 layout_unitsTemp->addWidget(pushButton_unitsTempK);
         layout_units->addWidget(groupBox_UnitsPressure);
             groupBox_UnitsPressure->setLayout(layout_unitsPressure);
                 layout_unitsPressure->addWidget(pushButton_unitsPressureKPA);
                 layout_unitsPressure->addWidget(pushButton_unitsPressureMM);
     layout_base->addWidget(pushButton_saveSettings);

     setLayout(layout_base);
}
/*!
 * \brief SettingsWindow::slot_pushButton_unitsTempC_Clicked
 * Слот обработки нажатия кнопки установки градусов цельсия как единицы измерения температуры
 */
void SettingsWindow::slot_pushButton_unitsTempC_Clicked()
{
    unitTemp temp=CURRENT_UNIT_TEMP_C;
    emit signal_sendTempUnit(temp);
}
/*!
 * \brief SettingsWindow::slot_pushButton_unitsTempK_Clicked
 * Слот обработки нажатия кнопки установки градусов кельвина как единицы измерения температуры
 */
void SettingsWindow::slot_pushButton_unitsTempK_Clicked()
{
    unitTemp temp=CURRENT_UNIT_TEMP_K;
    emit signal_sendTempUnit(temp);
}
/*!
 * \brief SettingsWindow::slot_pushButton_unitsTempF_Clicked
 * Слот обработки нажатия кнопки установки градусов фаренгейта как единицы измерения температуры
 */
void SettingsWindow::slot_pushButton_unitsTempF_Clicked()
{
    unitTemp temp=CURRENT_UNIT_TEMP_F;
    emit signal_sendTempUnit(temp);
}
/*!
 * \brief SettingsWindow::slot_pushbutton_unitPressureMM_Clicked
 * Слот обработки нажатия кнопки установки мм.рт.ст. как единицы измерения давления
 */
void SettingsWindow::slot_pushbutton_unitPressureMM_Clicked()
{
    unitPressure pressure=CURRENT_UNIT_PRESSURE_MM;
    emit signal_sendPressureUnit(pressure);
}
/*!
 * \brief SettingsWindow::slot_pushbutton_unitPressureKPA_Cliked
 * Слот обработки нажатия кнопки установки килопаскали как единицы измерения давления
 */
void SettingsWindow::slot_pushbutton_unitPressureKPA_Cliked()
{
    unitPressure pressure=CURRENT_UNIT_PRESSURE_KPA;
    emit signal_sendPressureUnit(pressure);
}

void SettingsWindow::slot_editStepSettingTemp()
{
    double settedStepFromSettings=edit_stepSettingTemp->text().replace(",",".").toDouble();
    emit signal_sendStepSettingTemp(settedStepFromSettings);
}
/*!
 * \brief SettingsWindow::slot_pushButtonDarkThemeClicked
 * слот обработки выбора темной темы приложения
 */
void SettingsWindow::slot_pushButtonDarkThemeClicked()
{
    qApp->setStyle(QStyleFactory::create("Fusion"));

       QPalette darkPalette;
       darkPalette.setColor(QPalette::Window, QColor(53,53,53));
       darkPalette.setColor(QPalette::WindowText, Qt::white);
       darkPalette.setColor(QPalette::Base, QColor(25,25,25));
       darkPalette.setColor(QPalette::AlternateBase, QColor(53,53,53));
       darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
       darkPalette.setColor(QPalette::ToolTipText, Qt::white);
       darkPalette.setColor(QPalette::Text, Qt::white);
       darkPalette.setColor(QPalette::Button, QColor(53,53,53));
       darkPalette.setColor(QPalette::ButtonText, Qt::white);
       darkPalette.setColor(QPalette::BrightText, Qt::red);
       darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));

       darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
       darkPalette.setColor(QPalette::HighlightedText, Qt::black);

       qApp->setPalette(darkPalette);

       qApp->setStyleSheet("QToolTip { color: #ffffff; background-color: #2a82da; border: 1px solid white; }");
}
/*!
 * \brief SettingsWindow::slot_pushButtonLightThemeClicked
 * Слот  выбора светлой темы приложения
 */
void SettingsWindow::slot_pushButtonLightThemeClicked()
{
        qApp->setPalette(style()->standardPalette());
        qApp->setStyle(QStyleFactory::create("Fusion"));
}
void SettingsWindow::slot_pushButtonSaveSettingsClicked()
{
    emit signal_saveSettings();
}
