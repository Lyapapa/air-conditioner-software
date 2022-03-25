#ifndef STRUCTS_H
#define STRUCTS_H

struct setDataSensor
{
    double temp;
    double humidity;
    double pressure;
};

enum unitTemp
{
    CURRENT_UNIT_TEMP_C,
    CURRENT_UNIT_TEMP_K,
    CURRENT_UNIT_TEMP_F
};
enum unitPressure
{
    CURRENT_UNIT_PRESSURE_KPA,
    CURRENT_UNIT_PRESSURE_MM
};
enum airflowDirection
{
  CURRENT_DIRECTION_UP,
  CURRENT_DIRECTION_MID,
  CURRENT_DIRECTION_DOWN
};


#endif // STRUCTS_H
