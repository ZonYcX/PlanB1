#include "Aktor.h"
#include <Arduino.h>
#include "Part.h"

Aktor::Aktor() : Part() 
{
    aktorPin = 0;
}

Aktor::Aktor(String aName) : Part(aName) 
{
    aktorPin = 0;
}

template<typename T>
bool Aktor::setAktorValue(T  aktorValue)
{
    return true;                       //gibt true zurück falls Aktion erfolgreich
}

int Aktor::getAktorPin()
{
    return aktorPin;                        //gibt angeschlossenen Arduino-Pin zurück
}
