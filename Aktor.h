#ifndef AKTOR_H
#define AKTOR_H
#include <Arduino.h>
#include "Part.h"

class Aktor : public Part                              //Basisklasse Aktor für Übergabe von Stellgröße an Bauteil
{
    public:
        Aktor();
        Aktor(String aName);
        template<typename T>              //Template für Freiheitsgrad des Stellgrößen-Datentyp
        bool setAktorValue(T aktorValue);      //an Aktor zu übergebende Stellgröße
        int getAktorPin();                     //gibt angeschlossenen PIN aus
        
    protected:
        int aktorPin;                          //enthält den Arduino-Pin, an welchem das Bauteil angeschlossen ist
};

#endif // AKTOR_H
