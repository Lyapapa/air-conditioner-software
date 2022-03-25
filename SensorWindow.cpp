#include"SensorWindow.h"

/*!
 * \brief SensorWindow::SensorWindow
 * класс эмитации значений с датчиков
 */
SensorWindow::SensorWindow(QWidget *parent)
    : QWidget(parent)
{
    designWindow();
    myConnections();
    openSettingsXml();
}

   SensorWindow:: ~SensorWindow()
{

}
   /*!
 * \brief SensorWindow::designWindow
 * метод формирования окна и всех его виджетов
 */
void SensorWindow::designWindow()
{
    myMainWindow = new MainWindow();
    myMainWindow->setWindowTitle("Air Conditioner software");
    myMainWindow->resize(1024,768);

    gbx = new QGroupBox("Значения имитирующие показания датчиков");

    tempValidator=new QDoubleValidator(-50.0, 50.0, 2);

    humidityValidator=new QDoubleValidator(0.0, 100.0, 2);

    pressureValidator=new QDoubleValidator(0.0, 110.0, 2);

    Edit_temp= new QLineEdit;
    Edit_temp->setValidator(tempValidator);
    Edit_temp->setText("20.1");

    Edit_humidity= new QLineEdit;
    Edit_humidity->setValidator(humidityValidator);
    Edit_humidity->setText("30.5");

    Edit_pressure= new QLineEdit;
    Edit_pressure->setValidator(pressureValidator);
    Edit_pressure->setText("102.5");

    Label_temp=new QLabel("Температура");
    Label_temp->setAlignment(Qt::AlignCenter);
    Label_tempUnit=new QLabel("°C");
    Label_humidity=new QLabel("Влажность");
    Label_humidity->setAlignment(Qt::AlignCenter);
    Label_humidityUnit=new QLabel("%");
    Label_pressure=new QLabel("Давление");
    Label_pressure->setAlignment(Qt::AlignCenter);
    Label_pressureUnit=new QLabel("кПа");
    PushButton_apply=new QPushButton("Применить");
    PushButton_apply->setShortcut(Qt::Key_Return);

    Layout_Sensor=new QHBoxLayout;
    Layout_SensorTemp=new QVBoxLayout;
    Layout_SensorHumidity=new QVBoxLayout;
    Layout_SensorPressure=new QVBoxLayout;

    Layout_Base=new QVBoxLayout;
    Layout_main = new QHBoxLayout;
    Layout_temp=new QHBoxLayout;
    Layout_temp->setContentsMargins(10,10,10,10);
    Layout_temp->setSpacing(20);
    Layout_humidity=new QHBoxLayout;
    Layout_humidity->setContentsMargins(10,10,10,10);
    Layout_humidity->setSpacing(20);
    Layout_pressure=new QHBoxLayout;
    Layout_pressure->setContentsMargins(10,10,10,10);
    Layout_pressure->setSpacing(20);

    Layout_main->addWidget(gbx);
    gbx->setLayout(Layout_Base);
    Layout_Base->addLayout(Layout_Sensor);
    Layout_Base->addWidget(PushButton_apply);

    Layout_Sensor->addLayout(Layout_SensorTemp);
    Layout_Sensor->addLayout(Layout_SensorHumidity);
    Layout_Sensor->addLayout(Layout_SensorPressure);

    Layout_SensorTemp->addWidget(Label_temp);
    Layout_SensorTemp->addLayout(Layout_temp);
    Layout_temp->addWidget(Edit_temp);
    Layout_temp->addWidget(Label_tempUnit);

    Layout_SensorHumidity->addWidget(Label_humidity);
    Layout_SensorHumidity->addLayout(Layout_humidity);
    Layout_humidity->addWidget(Edit_humidity);
    Layout_humidity->addWidget(Label_humidityUnit);

    Layout_SensorPressure->addWidget(Label_pressure);
    Layout_SensorPressure->addLayout(Layout_pressure);
    Layout_pressure->addWidget(Edit_pressure);
    Layout_pressure->addWidget(Label_pressureUnit);



    this->setLayout(Layout_main);
}
void SensorWindow::myConnections()
{
    //соединяет нажатие кнопки "принять" со слотом обработки нажатия
    QObject::connect(PushButton_apply, &QPushButton::clicked, this, &SensorWindow::slot_applyClicked);
    //соединяет сигнал "отправляющий" установленные значения со слотом отображения "измеренных" значений
    QObject::connect(this, &SensorWindow::signal_sensorInfo, myMainWindow, &MainWindow::slot_receiveSensorInfo);
}
/*!
 * \brief SensorWindow::slot_applyClicked
 * слот обработки нажатия кнопки "принять". Отправляет форматированные введенные данные
 */
void SensorWindow::slot_applyClicked()
{
    setDataSensor outData;
    outData.temp=Edit_temp->text().replace(",",".").toDouble();
    outData.humidity=Edit_humidity->text().replace(",",".").toDouble();
    outData.pressure=Edit_pressure->text().replace(",",".").toDouble();

    emit signal_sensorInfo(outData);
    myMainWindow->show();
    this->close();
}

void SensorWindow::openSettingsXml()
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
                    SensorWindow::Label_tempUnit->setText("°" + unitI);

                }
                else if (title == "Pressure")
                {
                    QString unitPreStr;
                    if (unitI == "kPa")
                        unitPreStr = "кПа";
                    else if (unitI == "mm")
                        unitPreStr = "мм.рт.ст.";
                    SensorWindow::Label_pressureUnit->setText(unitPreStr);
                }
                qDebug() << "title" << title;
                qDebug() << "unitI" << unitI;
                node = node.nextSibling().toElement();
            }
        }
        node = node.nextSibling().toElement();
    }
}
