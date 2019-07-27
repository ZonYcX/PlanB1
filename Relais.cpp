#include "Relais.h"


Relais::Relais(String aName) : Aktor(aName){}		//Vererbt von Part

Relais::Relais(String aName, int aPin):Aktor(aName) 				//Konstruktor mit Initialisierung von Attributen
{
	
	this->aktorPin = aPin;
	pinMode(aktorPin, OUTPUT);
}


bool Relais::setValue(bool  aktorValue)				//Funktion zum aktivieren/deaktivieren des Relais
{
	if(aktorValue == 1)								//bei Wert 1, wird das Relais angeschaltet
	{
		digitalWrite(aktorPin, HIGH);
		return true;
	}
	else  {											//wenn Wert 0, wird das Relais ausgeschaltet
		digitalWrite(aktorPin, LOW);
		return false;
	}
}

bool Relais::Toggel(int duration)
{
	digitalWrite(aktorPin, HIGH);
	delay(duration);
	digitalWrite(aktorPin, LOW);
}

