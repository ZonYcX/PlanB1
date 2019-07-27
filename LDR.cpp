#include "LDR.h"

LDR::LDR(String aName) : Sensor(aName){}				//Vererbt von Part

LDR::LDR(String aName, int aPin) : Sensor(aName)
{				//Konstruktor mit Initialisierung von Attributen
  this->sensorPin = aPin;
}


int LDR::getSensorValue()								//Funktion für Rückgabe des Messwertes
{	
	this->sensorValue = analogRead(sensorPin);		//analoges Signal wird in der Variable value gespeichert
	return sensorValue;								//und ausgegeben
}
