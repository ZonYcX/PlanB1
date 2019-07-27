#ifndef SENSOR_H
#define SENSOR_H
#include <Arduino.h>
#include "Part.h"

class Sensor : public Part      //Basisklasse Sensor für Abfrage von Sensordaten vom Bauteil
{
    public:
        Sensor();
        Sensor(String aName);
        virtual int getSensorValue();   //gibt den Sensorwert aus
        int getSensorPin();     //gibt angeschlossenen PIN aus
    
    protected:
        int sensorValue;        //enthält Sensorwert
        int sensorPin;          //enthält den Arduino-Pin, an welchem das Bauteil angeschlossen ist

};

#endif // SENSOR_H
