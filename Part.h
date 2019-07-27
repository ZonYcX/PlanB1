#ifndef PART_H
#define PART_H
#include "Arduino.h"

class Part                             //Basisklasse Part für Bauteile, stellt grundlegende Eigenschaften bereit
{
    public:
        Part();
        Part(String aName);             //Konstruktor für verwaltbare Bauteile 
        String getName();               //Rückgabe des Bauteilnamen

        
    protected:
        String partName;                    //Bauteilname zur Identifikation und Verwaltung

};

#endif // PART_H
