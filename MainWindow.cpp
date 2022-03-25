#include "MainWindow.h"

/*!
 * \brief MainWindow::MainWindow
 * Основное окно приложения. В конструкторе класса устанавливается таймер, запускается метод созданияокна приложения, подключение коннекторов и открытия XML файла с настройками
 * \param parent
 */
MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    //таймер для имитации изменения температуры
    MyTimer=new QTimer;
    MyTimer->setInterval(500);

    designWindow();
    myConnections();
    openSettingsXml();
}

MainWindow::~MainWindow()
{

}
/*!
 * \brief MainWindow::myConnections
 * Метод со всеми коннекторами.
 */
void MainWindow::myConnections()
{
    QObject::connect(MyTimer,&QTimer::timeout, this, &MainWindow:: slot_timerTikTak);
    QObject::connect(pushbutton_SetOnOff,&QPushButton::clicked,this,&MainWindow::slot_onOffClicked);
    QObject::connect(pushbutton_SetTempUp, &QPushButton::clicked,this, &MainWindow::slot_pushButtonPlusClicked);
    QObject::connect(pushbutton_SetTempDown, &QPushButton::clicked, this, &MainWindow::slot_pushButtonMinusClicked);
    QObject::connect(pushbutton_Settings, &QPushButton::clicked, this, &MainWindow::slot_settingsClicked);
    QObject::connect(pushbutton_Faq,&QPushButton::clicked, this, &MainWindow::slot_pushButtonFaqClicked);
    QObject::connect(pushbutton_SetAirflowUp, &QPushButton::clicked, this, &MainWindow::slot_airFlowUpClicked);
    QObject::connect(pushbutton_SetAirflowMid, &QPushButton::clicked, this, &MainWindow::slot_airflowMidClicked);
    QObject::connect(pushbutton_SetAirflowDown, &QPushButton::clicked, this, &MainWindow::slot_airflowDownClicked);



}
/*!
 * \brief MainWindow::designWindow
 * Метод формирования основного окна приложения с созданием виджетов и расположением их на форме
 */
void MainWindow::designWindow()
{
    pushbutton_SetTempUp=new QPushButton;
    pushbutton_SetTempUp->setMaximumHeight(128);
    pushbutton_SetTempUp->setMaximumWidth(256);
    pushbutton_SetTempUp->setIcon(QIcon(":/icons/up.png") );
    pushbutton_SetTempUp->setIconSize(QSize(100,100));

    pushbutton_SetTempDown=new QPushButton;
    pushbutton_SetTempDown->setMaximumHeight(128);
    pushbutton_SetTempDown->setMaximumWidth(256);
    pushbutton_SetTempDown->setIcon(QIcon(":/icons/down.png"));
    pushbutton_SetTempDown->setIconSize(QSize(100,100));

    pushbutton_SetAirflowUp=new QPushButton;
    pushbutton_SetAirflowUp->setStyleSheet("background-color: red; ");
    pushbutton_SetAirflowUp->setMaximumHeight(128);
    pushbutton_SetAirflowUp->setMaximumWidth(171);
    pushbutton_SetAirflowUp->setIcon(QIcon(":/icons/airflow5.png"));
    pushbutton_SetAirflowUp->setIconSize(QSize(50,50));

    pushbutton_SetAirflowMid=new QPushButton;
    pushbutton_SetAirflowMid->setStyleSheet("background-color: green; ");
    pushbutton_SetAirflowMid->setMaximumHeight(128);
    pushbutton_SetAirflowMid->setMaximumWidth(171);
    pushbutton_SetAirflowMid->setIcon(QIcon(":/icons/airglowmid2.png"));
    pushbutton_SetAirflowMid->setIconSize(QSize(100,100));

    pushbutton_SetAirflowDown=new QPushButton;
    pushbutton_SetAirflowDown->setStyleSheet("background-color: red; ");
    pushbutton_SetAirflowDown->setMaximumHeight(128);
    pushbutton_SetAirflowDown->setMaximumWidth(171);
    pushbutton_SetAirflowDown->setIcon(QIcon(":/icons/airflow3.png"));
    pushbutton_SetAirflowDown->setIconSize(QSize(50,50));

    pushbutton_SetOnOff=new QPushButton;//("On/Off");
    pushbutton_SetOnOff->setStyleSheet("background-color: red; ");
    pushbutton_SetOnOff->setMaximumHeight(128);
    pushbutton_SetOnOff->setMaximumWidth(128);  //171
    pushbutton_SetOnOff->setIcon(QIcon(":/icons/onOff (2).png"));
    pushbutton_SetOnOff->setIconSize(QSize(100,100));

    pushbutton_Settings=new QPushButton;
    pushbutton_Settings->setMaximumHeight(128);
    pushbutton_Settings->setMaximumWidth(128);
    pushbutton_Settings->setIcon(QIcon(":/icons/settings.png"));
    pushbutton_Settings->setIconSize(QSize(100,100));

    pushbutton_Faq=new QPushButton;//("FAQ");
    pushbutton_Faq->setMaximumHeight(128);
    pushbutton_Faq->setMaximumWidth(128);
    pushbutton_Faq->setIcon(QIcon(":/icons/faq1.png"));
    pushbutton_Faq->setIconSize(QSize(100,100));

    label_SetTemp=new QLabel("Установка температуры"); //заголовок модуля установки температуры
    label_SetTemp->setMaximumHeight(128);
    label_SetTemp->setMaximumWidth(512);
    label_SetTemp->setAlignment(Qt::AlignCenter);
    label_SetTemp->setStyleSheet(QString("font-size: %1px").arg(20));

    label_SettedTemp=new QLabel("Установленная температура");//заголовок модуля отображения установленного значения
    label_SettedTemp->setMaximumHeight(128);
    label_SettedTemp->setMaximumWidth(512);
    label_SettedTemp->setAlignment(Qt::AlignCenter);
    label_SettedTemp->setStyleSheet(QString("font-size: %1px").arg(20));

    label_SetValueTemp=new QLabel("20"); //установленное значение на кондиционере
    label_SetValueTemp->setMaximumHeight(128);
    label_SetValueTemp->setMaximumWidth(256);
    label_SetValueTemp->setAlignment(Qt::AlignRight);
    label_SetValueTemp->setStyleSheet(QString("font-size: %1px").arg(20));

    label_SetValueTempUnit=new QLabel("°C");//единицы измерения установленного значения температуры на кон-ре
    label_SetValueTempUnit->setMaximumHeight(128);
    label_SetValueTempUnit->setMaximumWidth(256);
    label_SetValueTempUnit->setAlignment(Qt::AlignLeft);
    label_SetValueTempUnit->setStyleSheet(QString("font-size: %1px").arg(20));


    label_MeasuredHumidity=new QLabel("Измеренная влажность");
    label_MeasuredHumidity->setMaximumHeight(128);
    label_MeasuredHumidity->setMaximumWidth(342);
    label_MeasuredHumidity->setAlignment(Qt::AlignCenter);
    label_MeasuredHumidity->setStyleSheet(QString("font-size: %1px").arg(20));

    label_MeasuredValueHumidity=new QLabel("30");//измеренно значение влажности
    label_MeasuredValueHumidity->setMaximumHeight(128);
    label_MeasuredValueHumidity->setMaximumWidth(171);
    label_MeasuredValueHumidity->setAlignment(Qt::AlignRight);
    label_MeasuredValueHumidity->setStyleSheet(QString("font-size: %1px").arg(20));

    label_MeasuredValueHumidityUnit=new QLabel("%");//ед изм изм-го знач влажности
    label_MeasuredValueHumidityUnit->setMaximumHeight(128);
    label_MeasuredValueHumidityUnit->setMaximumWidth(171);
    label_MeasuredValueHumidityUnit->setAlignment(Qt::AlignLeft);
    label_MeasuredValueHumidityUnit->setStyleSheet(QString("font-size: %1px").arg(20));


    label_MeasuredTemp=new QLabel("Измеренная температура");
    label_MeasuredTemp->setMaximumHeight(128);
    label_MeasuredTemp->setMaximumWidth(342);
    label_MeasuredTemp->setAlignment(Qt::AlignCenter);
    label_MeasuredTemp->setStyleSheet(QString("font-size: %1px").arg(20));

    label_MeasuredValueTemp=new QLabel("22");//измеренно значение температуры
    label_MeasuredValueTemp->setMaximumHeight(128);
    label_MeasuredValueTemp->setMaximumWidth(171);
    label_MeasuredValueTemp->setAlignment(Qt::AlignRight);
    label_MeasuredValueTemp->setStyleSheet(QString("font-size: %1px").arg(20));

    label_MeasuredValueTempUnit=new QLabel("°C");//ед изм изм-го знач температуры
    label_MeasuredValueTempUnit->setMaximumHeight(128);
    label_MeasuredValueTempUnit->setMaximumWidth(171);
    label_MeasuredValueTempUnit->setAlignment(Qt::AlignLeft);
    label_MeasuredValueTempUnit->setStyleSheet(QString("font-size: %1px").arg(20));



    label_MeasuredPressure=new QLabel("Измеренное атмосферное давление");
    label_MeasuredPressure->setMaximumHeight(128);
    label_MeasuredPressure->setMaximumWidth(342);
    label_MeasuredPressure->setAlignment(Qt::AlignCenter);
    label_MeasuredPressure->setStyleSheet(QString("font-size: %1px").arg(20));

    label_MeasuredValuePressure=new QLabel("103");//измеренно значение давления
    label_MeasuredValuePressure->setMaximumHeight(128);
    label_MeasuredValuePressure->setMaximumWidth(171);
    label_MeasuredValuePressure->setAlignment(Qt::AlignRight);
    label_MeasuredValuePressure->setStyleSheet(QString("font-size: %1px").arg(20));

    label_MeasuredValuePressureUnit=new QLabel("кПа");//ед изм изм-го знач давления
    label_MeasuredValuePressureUnit->setMaximumHeight(128);
    label_MeasuredValuePressureUnit->setMaximumWidth(171);
    label_MeasuredValuePressureUnit->setAlignment(Qt::AlignLeft);
    label_MeasuredValuePressureUnit->setStyleSheet(QString("font-size: %1px").arg(20));

    label_SetAirflow=new QLabel("Направление обдува");
    label_SetAirflow->setMaximumHeight(128);
    label_SetAirflow->setMaximumWidth(513);
    label_SetAirflow->setAlignment(Qt::AlignCenter);
    label_SetAirflow->setStyleSheet(QString("font-size: %1px").arg(20));

    groupbox_topLeft=new QGroupBox;
    groupbox_topRight=new QGroupBox;
    groupbox_midLeft=new QGroupBox;
    groupbox_midCenter=new QGroupBox;
    groupbox_midRight=new QGroupBox;
    groupbox_downLeft=new QGroupBox;
    groupbox_downRight=new QGroupBox;

    QBoxLayout* baseLayout= new QBoxLayout(QBoxLayout::TopToBottom);
    baseLayout->setContentsMargins(5,5,5,5);
    baseLayout->setSpacing(15);
        QBoxLayout* firstLvlLayoutTop=new QBoxLayout(QBoxLayout::LeftToRight);                                  //помещаем поле установки температуры и поле отображения установленной
        firstLvlLayoutTop->setContentsMargins(5,5,5,5);
        firstLvlLayoutTop->setSpacing(15);
            QBoxLayout* secondLvlLayoutTopLeft=new QBoxLayout(QBoxLayout::TopToBottom);                         //помещаем лэй с кнопками и лэйбл
            secondLvlLayoutTopLeft->setContentsMargins(5,5,5,5);
            secondLvlLayoutTopLeft->setSpacing(15);
                QBoxLayout* thirdLvlLayoutTopLeftDown=new QBoxLayout(QBoxLayout::LeftToRight);                  //левый верхний угол окна, сюда идутдве кнопки
                thirdLvlLayoutTopLeftDown->setContentsMargins(5,5,5,5);
                thirdLvlLayoutTopLeftDown->setSpacing(15);
            QBoxLayout* secondLvlLayoutTopRight=new QBoxLayout(QBoxLayout::TopToBottom);                        //сюда вверх лейбл а вний лэй с двумя лейблами
            secondLvlLayoutTopRight->setContentsMargins(5,5,5,5);
            secondLvlLayoutTopRight->setSpacing(15);
                QBoxLayout* thirdLvlLayoutTopRightDown=new QBoxLayout(QBoxLayout::LeftToRight);                 //правй верхний угол нижняя часть. сюда два лейбла отображения установленный градусов и ед изм
                thirdLvlLayoutTopRightDown->setContentsMargins(5,5,5,5);
                thirdLvlLayoutTopRightDown->setSpacing(15);
        QBoxLayout* firstLvlLayoutMid=new QBoxLayout(QBoxLayout::LeftToRight);                                  // средняя часть окна. тут отображение измеренного
        firstLvlLayoutMid->setContentsMargins(5,5,5,5);
        firstLvlLayoutMid->setSpacing(15);
                QBoxLayout* secondLvlLayoutMidLeft=new QBoxLayout(QBoxLayout::TopToBottom);                         //сюда вверх лейбл а вний лэй с двумя лейблами
                secondLvlLayoutMidLeft->setContentsMargins(5,5,5,5);
                secondLvlLayoutMidLeft->setSpacing(15);
                    QBoxLayout* thirdLvlLayoutMidLeftDown=new QBoxLayout(QBoxLayout::LeftToRight);                  //левая средняя часть. тут два лейбла. один значение влажности, второй - %.
                    thirdLvlLayoutMidLeftDown->setContentsMargins(5,5,5,5);
                    thirdLvlLayoutMidLeftDown->setSpacing(15);
                QBoxLayout* secondLvlLayoutMidMid=new QBoxLayout(QBoxLayout::TopToBottom);                          //сюда вверх лейбл а вний лэй с двумя лейблами
                secondLvlLayoutMidMid->setContentsMargins(5,5,5,5);
                secondLvlLayoutMidMid->setSpacing(15);
                    QBoxLayout* thirdLvlLayoutMidMidDown=new QBoxLayout(QBoxLayout::LeftToRight);                   //самый центр. тут два лейбла. один значение температур, второй - ед изм.
                    thirdLvlLayoutMidMidDown->setContentsMargins(5,5,5,5);
                    thirdLvlLayoutMidMidDown->setSpacing(15);
                QBoxLayout* secondLvlLayoutMidRight=new QBoxLayout(QBoxLayout::TopToBottom);                        //сюда вверх лейбл а вний лэй с двумя лейблами
                secondLvlLayoutMidRight->setContentsMargins(5,5,5,5);
                secondLvlLayoutMidRight->setSpacing(15);
                    QBoxLayout* thirdLvlLayoutMidRightDown=new QBoxLayout(QBoxLayout::LeftToRight);                 //правая средняя часть. тут два лейбла. один значение давления, второй - ед изм.
                    thirdLvlLayoutMidRightDown->setContentsMargins(5,5,5,5);
                    thirdLvlLayoutMidRightDown->setSpacing(15);
        QBoxLayout* firstLvlLayoutDown=new QBoxLayout(QBoxLayout::LeftToRight);
        firstLvlLayoutDown->setContentsMargins(5,5,5,5);
        firstLvlLayoutDown->setSpacing(15);
                QBoxLayout* secondLvlLayoutDownLeft=new QBoxLayout(QBoxLayout::TopToBottom);                        //сюда текст вверх а вниз лэй с треия кнопками
                secondLvlLayoutDownLeft->setContentsMargins(5,5,5,5);
                secondLvlLayoutDownLeft->setSpacing(15);
                    QBoxLayout* thirdLvlLayoutDownLeftDown=new QBoxLayout(QBoxLayout::LeftToRight);                 //сюда 3 кнопки с подсветкой режимов направления воздуха
                    thirdLvlLayoutDownLeftDown->setContentsMargins(5,5,5,5);
                    thirdLvlLayoutDownLeftDown->setSpacing(15);
                QBoxLayout* secondLvlLayoutDownRight=new QBoxLayout(QBoxLayout::LeftToRight);                        //сюда три кнопки
                secondLvlLayoutDownRight->setContentsMargins(5,5,5,5);
                secondLvlLayoutDownRight->setSpacing(30);

    baseLayout->addLayout(firstLvlLayoutTop);
    baseLayout->addLayout(firstLvlLayoutMid);
    baseLayout->addLayout(firstLvlLayoutDown);

    firstLvlLayoutTop->addWidget(groupbox_topLeft);
    groupbox_topLeft->setLayout(secondLvlLayoutTopLeft);
    firstLvlLayoutTop->addWidget(groupbox_topRight);
    groupbox_topRight->setLayout(secondLvlLayoutTopRight);
    firstLvlLayoutMid->addWidget(groupbox_midLeft);
    groupbox_midLeft->setLayout(secondLvlLayoutMidLeft);
    firstLvlLayoutMid->addWidget(groupbox_midCenter);
    groupbox_midCenter->setLayout(secondLvlLayoutMidMid);
    firstLvlLayoutMid->addWidget(groupbox_midRight);
    groupbox_midRight->setLayout(secondLvlLayoutMidRight);
    firstLvlLayoutDown->addWidget(groupbox_downLeft);
    groupbox_downLeft->setLayout(secondLvlLayoutDownLeft);
    firstLvlLayoutDown->addWidget(groupbox_downRight);
    groupbox_downRight->setLayout(secondLvlLayoutDownRight);

    secondLvlLayoutTopLeft->addWidget(label_SetTemp);
    secondLvlLayoutTopLeft->addLayout(thirdLvlLayoutTopLeftDown);
    secondLvlLayoutTopRight->addWidget(label_SettedTemp);
    secondLvlLayoutTopRight->addLayout(thirdLvlLayoutTopRightDown);
    secondLvlLayoutMidLeft->addWidget(label_MeasuredHumidity);
    secondLvlLayoutMidLeft->addLayout(thirdLvlLayoutMidLeftDown);
    secondLvlLayoutMidMid->addWidget(label_MeasuredTemp);
    secondLvlLayoutMidMid->addLayout(thirdLvlLayoutMidMidDown);
    secondLvlLayoutMidRight->addWidget(label_MeasuredPressure);
    secondLvlLayoutMidRight->addLayout(thirdLvlLayoutMidRightDown);
    secondLvlLayoutDownLeft->addWidget(label_SetAirflow);
    secondLvlLayoutDownLeft->addLayout(thirdLvlLayoutDownLeftDown);
    secondLvlLayoutDownRight->addWidget(pushbutton_SetOnOff);
    secondLvlLayoutDownRight->addWidget(pushbutton_Settings);
    secondLvlLayoutDownRight->addWidget(pushbutton_Faq);

    thirdLvlLayoutTopLeftDown->addWidget(pushbutton_SetTempUp);
    thirdLvlLayoutTopLeftDown->addWidget(pushbutton_SetTempDown);

    thirdLvlLayoutTopRightDown->addWidget(label_SetValueTemp);
    thirdLvlLayoutTopRightDown->addWidget(label_SetValueTempUnit);

    thirdLvlLayoutMidLeftDown->addWidget(label_MeasuredValueHumidity);
    thirdLvlLayoutMidLeftDown->addWidget(label_MeasuredValueHumidityUnit);

    thirdLvlLayoutMidMidDown->addWidget(label_MeasuredValueTemp);
    thirdLvlLayoutMidMidDown->addWidget(label_MeasuredValueTempUnit);

    thirdLvlLayoutMidRightDown->addWidget(label_MeasuredValuePressure);
    thirdLvlLayoutMidRightDown->addWidget(label_MeasuredValuePressureUnit);

    thirdLvlLayoutDownLeftDown->addWidget(pushbutton_SetAirflowUp);
    thirdLvlLayoutDownLeftDown->addWidget(pushbutton_SetAirflowMid);
    thirdLvlLayoutDownLeftDown->addWidget(pushbutton_SetAirflowDown);

    setLayout(baseLayout);
}
/*!
 * \brief MainWindow::slot_receiveSensorInfo
 * Располагает значения принятые от эмитации датчика в поля индикации
 * \param data
 * Структура, в которой храняться "изверенные датчиком" значения
 */
void MainWindow:: slot_receiveSensorInfo(setDataSensor &data)
{
    label_MeasuredValueTemp->setText(QString::number(data.temp));
    label_MeasuredValueHumidity->setText(QString::number(data.humidity));
    label_MeasuredValuePressure->setText(QString::number(data.pressure));
}
/*!
 * \brief MainWindow::slot_settingsClicked
 * обработчик нажатия на кнопку "настройки" с коннекторами для установки единиц измерения в настройках исохранения настроек
 */
void MainWindow::slot_settingsClicked()
{
    SettingsWindow* mySettingsWindow = new SettingsWindow;
    QObject::connect(mySettingsWindow, &SettingsWindow::signal_sendTempUnit, this, &MainWindow::slot_receivedUnitTempFromSettings);
    QObject::connect(mySettingsWindow, &SettingsWindow::signal_sendPressureUnit, this, &MainWindow::slot_receivedUnitPressureFromSettings);
    QObject::connect(mySettingsWindow, &SettingsWindow::signal_sendStepSettingTemp, this, &MainWindow::slot_receivedStepSettingTemp);
    QObject::connect(mySettingsWindow, &SettingsWindow::signal_saveSettings, this, &MainWindow::slot_saveSettingsXml);

    mySettingsWindow->setWindowTitle("Settings");
    mySettingsWindow->resize(400,600);
    mySettingsWindow->show();

}
/*!
 * \brief MainWindow::slot_receivedUnitTempFromSettings
 * Пересчитывает значения измеренной и установленной температуры в зависимости от единиц измерения, установленных в настройках
 * \param unitTempFromSettings
 * единицы измерения температуры, выбранная в настройках
 */
void MainWindow:: slot_receivedUnitTempFromSettings(unitTemp& unitTempFromSettings)
{
    double valueLabel=0.0;
    if(unitTempFromSettings !=currentunittemp)
            {
                switch(unitTempFromSettings)
                {
                case CURRENT_UNIT_TEMP_C:
                    if(currentunittemp==CURRENT_UNIT_TEMP_K)
                    {
                        valueLabel=label_MeasuredValueTemp->text().toDouble();
                        valueLabel-=273.15;
                        label_MeasuredValueTemp->setText(QString::number(valueLabel));

                        valueLabel=label_SetValueTemp->text().toDouble();
                        valueLabel-=273.15;
                        label_SetValueTemp->setText(QString::number(valueLabel));
                    }
                    else if(currentunittemp==CURRENT_UNIT_TEMP_F)
                    {
                        valueLabel=label_MeasuredValueTemp->text().toDouble();
                        valueLabel=(valueLabel-32.0)*(5.0/9.0);
                        label_MeasuredValueTemp->setText(QString::number(valueLabel));

                        valueLabel=label_SetValueTemp->text().toDouble();
                        valueLabel=(valueLabel-32.0)*(5.0/9.0);
                        label_SetValueTemp->setText(QString::number(valueLabel));
                    }

                    label_MeasuredValueTempUnit->setText("°C");
                    label_SetValueTempUnit->setText("°C");
                    currentunittemp=unitTempFromSettings;
                    break;

                case CURRENT_UNIT_TEMP_K:
                    if(currentunittemp==CURRENT_UNIT_TEMP_C)
                    {
                        valueLabel=label_MeasuredValueTemp->text().toDouble();
                        valueLabel+=273.15;
                        label_MeasuredValueTemp->setText(QString::number(valueLabel));

                        valueLabel=label_SetValueTemp->text().toDouble();
                        valueLabel+=273.15;
                        label_SetValueTemp->setText(QString::number(valueLabel));
                    }
                    else if(currentunittemp==CURRENT_UNIT_TEMP_F)
                    {
                        valueLabel=label_MeasuredValueTemp->text().toDouble();
                        valueLabel=(valueLabel-32.0)*(5.0/9.0)+273.15;
                        label_MeasuredValueTemp->setText(QString::number(valueLabel));

                        valueLabel=label_SetValueTemp->text().toDouble();
                        valueLabel=(valueLabel-32.0)*(5.0/9.0)+273.15;
                        label_SetValueTemp->setText(QString::number(valueLabel));
                    }

                    label_MeasuredValueTempUnit->setText("°K");
                    label_SetValueTempUnit->setText("°K");
                    currentunittemp=unitTempFromSettings;
                    break;

                case CURRENT_UNIT_TEMP_F:
                    if(currentunittemp==CURRENT_UNIT_TEMP_C)
                    {
                        valueLabel=label_MeasuredValueTemp->text().toDouble();
                        valueLabel=(valueLabel*(9.0/5.0))+32.0;
                        label_MeasuredValueTemp->setText(QString::number(valueLabel));

                        valueLabel=label_SetValueTemp->text().toDouble();
                        valueLabel=(valueLabel*(9.0/5.0))+32.0;
                        label_SetValueTemp->setText(QString::number(valueLabel));
                    }

                    else if(currentunittemp==CURRENT_UNIT_TEMP_K)
                    {
                        valueLabel=label_MeasuredValueTemp->text().toDouble();
                        valueLabel=(valueLabel-273.15)*(9.0/5.0)+32.0;
                        label_MeasuredValueTemp->setText(QString::number(valueLabel));

                        valueLabel=label_SetValueTemp->text().toDouble();
                        valueLabel=(valueLabel-273.15)*(9.0/5.0)+32.0;
                        label_SetValueTemp->setText(QString::number(valueLabel));
                    }
                    label_MeasuredValueTempUnit->setText("°F");
                    label_SetValueTempUnit->setText("°F");
                    currentunittemp=unitTempFromSettings;
                    break;
                }
            }
}
/*!
 * \brief MainWindow::slot_receivedUnitPressureFromSettings
 * Пересчитывает значения измеренного давления в зависимости от единиц измерения, установленных в настройках
 * \param unitPressureFromSettings единицы измерения давления, выбранная в настройках
 */
void MainWindow::slot_receivedUnitPressureFromSettings(unitPressure& unitPressureFromSettings)
{
    double valueLabel=0.0;
    if(unitPressureFromSettings!=currentunitpressure)
    {

        switch (unitPressureFromSettings)
        {
        case CURRENT_UNIT_PRESSURE_KPA:
            valueLabel=label_MeasuredValuePressure->text().toDouble();
            valueLabel*=0.13332;
            label_MeasuredValuePressure->setText(QString::number(valueLabel));
            label_MeasuredValuePressureUnit->setText("кПа");
            currentunitpressure=unitPressureFromSettings;
            break;
         case CURRENT_UNIT_PRESSURE_MM:
            valueLabel=label_MeasuredValuePressure->text().toDouble();
            valueLabel/=0.13332;
            label_MeasuredValuePressure->setText(QString::number(valueLabel));
            label_MeasuredValuePressureUnit->setText("мм.рт.ст.");
            currentunitpressure=unitPressureFromSettings;
            break;

        }
    }
}
/*!
 * \brief MainWindow::slot_pushButtonPlusClicked
 * обработчик нажатия на кнопку увеличения температуры
 */
void MainWindow::slot_pushButtonPlusClicked()
{
    double valueLabel;
    valueLabel=label_SetValueTemp->text().toDouble();
    valueLabel+=stepSettingTemp;
    label_SetValueTemp->setText(QString::number(valueLabel));
}
/*!
 * \brief MainWindow::slot_pushButtonMinusClicked
 * Обработчик нажатия на кнопку уменьшения температуры
 */
void MainWindow::slot_pushButtonMinusClicked()
{
    double valueLabel;
    valueLabel=label_SetValueTemp->text().toDouble();
    valueLabel-=stepSettingTemp;
    label_SetValueTemp->setText(QString::number(valueLabel));
}
/*!
 * \brief MainWindow::slot_timerTikTak
 * Метод,в котором происходит изменение измеренной температуры с запуском кондиционера
 */
void MainWindow::slot_timerTikTak()
{
    double valueLabel=0.0;

    if(label_SetValueTemp->text().toDouble()<label_MeasuredValueTemp->text().toDouble())
    {
        valueLabel=label_MeasuredValueTemp->text().toDouble();
        valueLabel-=0.01;
        label_MeasuredValueTemp->setText( QString::number(valueLabel));
    }
    else if(label_SetValueTemp->text().toDouble()>label_MeasuredValueTemp->text().toDouble())
    {
        valueLabel=label_MeasuredValueTemp->text().toDouble();
        valueLabel+=0.01;
        label_MeasuredValueTemp->setText( QString::number(valueLabel));
    }
}
/*!
 * \brief MainWindow::slot_onOffClicked
 * Обработчик нажатия на кнопку On/Off (включения кондиционера)
 */
void MainWindow::slot_onOffClicked()
{
    if(MyTimer->isActive())
        MyTimer->stop();
    else
        MyTimer->start();
    int state = pushbutton_SetOnOff->property("currentState").toInt();

            if(state == 0)
            {
                pushbutton_SetOnOff->setStyleSheet("background-color:green");
                pushbutton_SetOnOff->setProperty("currentState", 1);
            } else
            {
                pushbutton_SetOnOff->setStyleSheet("background-color:red");
                pushbutton_SetOnOff->setProperty("currentState", 0);
            }
}
/*!
 * \brief MainWindow::slot_airFlowUpClicked
 * Обработчик нажатия кнопки выбора направления обдува вверх
 */
void MainWindow::slot_airFlowUpClicked()
{
    if(currentAirflowDirection==CURRENT_DIRECTION_MID)
    {
        currentAirflowDirection=CURRENT_DIRECTION_UP;
        pushbutton_SetAirflowUp->setStyleSheet("background-color:green");
        pushbutton_SetAirflowMid->setStyleSheet("background-color:red");
    }
    else if(currentAirflowDirection==CURRENT_DIRECTION_DOWN)
    {
        currentAirflowDirection=CURRENT_DIRECTION_MID;
        pushbutton_SetAirflowUp->setStyleSheet("background-color:green");
        pushbutton_SetAirflowDown->setStyleSheet("background-color:red");
    }

}
/*!
 * \brief MainWindow::slot_airflowMidClicked
 * * Обработчик нажатия кнопки выбора направления обдува прямо
 */
void MainWindow::slot_airflowMidClicked()
{
    if(currentAirflowDirection==CURRENT_DIRECTION_UP)
    {
        currentAirflowDirection=CURRENT_DIRECTION_MID;
        pushbutton_SetAirflowMid->setStyleSheet("background-color:green");
        pushbutton_SetAirflowUp->setStyleSheet("background-color:red");
    }
    else if(currentAirflowDirection==CURRENT_DIRECTION_DOWN)
    {
        currentAirflowDirection=CURRENT_DIRECTION_MID;
        pushbutton_SetAirflowMid->setStyleSheet("background-color:green");
        pushbutton_SetAirflowDown->setStyleSheet("background-color:red");
    }
}
/*!
 * \brief MainWindow::slot_airflowDownClicked
 * * Обработчик нажатия кнопки выбора направления обдува вниз
 */
void MainWindow::slot_airflowDownClicked()
{
    if(currentAirflowDirection==CURRENT_DIRECTION_UP)
    {
        currentAirflowDirection=CURRENT_DIRECTION_DOWN;
        pushbutton_SetAirflowDown->setStyleSheet("background-color:green");
        pushbutton_SetAirflowUp->setStyleSheet("background-color:red");
    }
    else if(currentAirflowDirection==CURRENT_DIRECTION_MID)
    {
        currentAirflowDirection=CURRENT_DIRECTION_DOWN;
        pushbutton_SetAirflowDown->setStyleSheet("background-color:green");
        pushbutton_SetAirflowMid->setStyleSheet("background-color:red");
    }
}
/*!
 * \brief MainWindow::slot_pushButtonFaqClicked
 * Обработчик нажатия на кнопку вызова справки
 */
void MainWindow::slot_pushButtonFaqClicked()
{
    QDesktopServices :: openUrl  (  QUrl::fromLocalFile("file:///D:/HomeWork/Interviews/RadarMmsInterview/secondProbe/instruction.docx" ));
}
/*!
 * \brief MainWindow::slot_receivedStepSettingTemp
 * Метод изменяет шаг установки температуры в зависимости от изнменения шага в настройках
 * \param stepSettingTempFromSettings
 * шаг установки температуры
 */
void MainWindow::slot_receivedStepSettingTemp(double& stepSettingTempFromSettings)
{
    if(stepSettingTemp!=stepSettingTempFromSettings & stepSettingTempFromSettings!=0)
            stepSettingTemp=stepSettingTempFromSettings;
}
/*!
 * \brief MainWindow::slot_saveSettingsXml
 * Метод сохраняет настройки в XML файл при нажатии на кнопку сохранить в окне настроек
 */

void MainWindow::slot_saveSettingsXml()
{
    QFile xmlFile("settings.xml");
    if (!xmlFile.open(QFile::WriteOnly | QFile::Text ))
    {
        qDebug() << "Already opened or there is another issue";
        xmlFile.close();
    }
    QTextStream xmlContent(&xmlFile);

    QDomDocument document;

    QDomElement root = document.createElement("UnitsSettings");

    document.appendChild(root);

    QDomElement unit = document.createElement("Unit");
    unit.setAttribute("title", "Temperature");

    QString unitTempStr = MainWindow::label_MeasuredValueTempUnit->text().remove(0, 1);

    unit.setAttribute("unit", unitTempStr);
    root.appendChild(unit);

    unit = document.createElement("Unit");
    unit.setAttribute("title", "Pressure");

    QString unitPreStr = MainWindow::label_MeasuredValuePressureUnit->text();
    if (unitPreStr == "кПа")
        unitPreStr = "kPa";
    else if (unitPreStr == "мм.рт.ст.")
        unitPreStr = "mm";

    unit.setAttribute("unit", unitPreStr);
    root.appendChild(unit);

    xmlContent << document.toString();
}

void MainWindow::openSettingsXml()
{
    QDomDocument unitsXML;
    QFile xmlFile("settings.xml");
    if(!xmlFile.exists())
    {
        qDebug() << "The file" << xmlFile.fileName() << "does not exist.";
        return;
    }

    if (!xmlFile.open(QIODevice::ReadOnly ))
    {
        qDebug() << "Could not open" << xmlFile.fileName() << "for reading.";
        return;
    }
    qDebug() << QFileInfo(xmlFile).absoluteFilePath();

    unitsXML.setContent(&xmlFile);
    xmlFile.close();

    QDomElement root = unitsXML.documentElement();
    QDomElement node = root.firstChild().toElement();

    QString datas = "";

    while(node.isNull() == false)
    {
        qDebug() << node.tagName();
        if(node.tagName() == "Unit")
        {
            while(!node.isNull())
            {
                QString title = node.attribute("title","def");
                QString unitI = node.attribute("unit","def");

                if (title == "Temperature")
                {
                    MainWindow::label_MeasuredValueTempUnit->setText("°" + unitI);
                    MainWindow::label_SetValueTempUnit->setText("°" + unitI);
                    if (unitI=='F')
                        currentunittemp=CURRENT_UNIT_TEMP_F;
                    else if (unitI=='K')
                        currentunittemp=CURRENT_UNIT_TEMP_K;
                    else if (unitI=='C')
                        currentunittemp=CURRENT_UNIT_TEMP_C;
                }
                else if (title == "Pressure")
                {
                    QString unitPreStr;
                    if (unitI == "kPa")
                    {
                        unitPreStr = "кПа";
                        if(currentunitpressure==CURRENT_UNIT_PRESSURE_MM)
                            currentunitpressure=CURRENT_UNIT_PRESSURE_KPA;


                    }
                    else if (unitI == "mm")
                    {
                        unitPreStr = "мм.рт.ст.";
                        if(currentunitpressure==CURRENT_UNIT_PRESSURE_KPA)
                            currentunitpressure=CURRENT_UNIT_PRESSURE_MM;

                    }

                    MainWindow::label_MeasuredValuePressureUnit->setText(unitPreStr);
                }
                qDebug() << "title" << title;
                qDebug() << "unitI" << unitI;
                node = node.nextSibling().toElement();
            }
        }
        node = node.nextSibling().toElement();
    }


}
