#include "MainWindow.h"
#include "SensorWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SensorWindow sensorWindow;
    sensorWindow.setWindowTitle("Simulation of sensor values");
    sensorWindow.resize(400,200);
    sensorWindow.show();
    qApp->setStyle(QStyleFactory::create("Fusion"));
    return a.exec();
}
