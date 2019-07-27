#ifndef LDR_H
#define LDR_H
#include "Sensor.h"
#include "Part.h"
#include <Arduino.h>


class LDR : public Sensor				//Vererbung von Aktor und Part
{
    public:
    LDR(String aName);
		LDR(String aName, int aPin);				//Konstruktoren
		
		
		int getSensorValue();        						//Funktion für Rückgabe des Messwertes

    protected: 

    private:
};

#endif // LDR_H
