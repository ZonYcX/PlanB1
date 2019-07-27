#include "Sensor.h"
#include <Arduino.h>
#include "Part.h"

Sensor::Sensor() : Part() 
{
    sensorPin = 0;
    sensorValue = 0;
}

Sensor::Sensor(String aName) : Part(aName) 
{
  sensorPin = 0;
  sensorValue = 0;  
}

int Sensor::getSensorValue()
{
    return sensorValue;          //gibt Inhalt von Value aus
}

int Sensor::getSensorPin()
{
    return sensorPin;            //gibt angeschlossenen Arduino-Pin zurück
}
