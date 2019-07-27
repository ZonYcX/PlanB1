#ifndef Relais_H
#define Relais_H
#include <Arduino.h>
#include "Part.h"
#include "Aktor.h"

class Relais : public Aktor		//Vererbung von Aktor und Part
{
    public:
        Relais(String aName);
		Relais(String aName, int aPin);			//Konstruktoren
		
		
		
		bool setValue( bool aktorValue);		//Funktion zum aktivieren/deaktivieren des Relais
		bool Toggel(int);
    protected:

    private:
};

#endif // Relais_H
