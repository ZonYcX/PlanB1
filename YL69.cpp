#include "YL69.h" 

YL69::YL69(String aName) : Sensor(aName) {}				// Vererbung von Part 

YL69::YL69(String aName, int aPin):Sensor(aName) {				// Konstruktordefinition mit Attribut-Initialisierung 

	this->sensorPin = aPin;
}


int YL69::getSensorValue()						// Funktion fuer Messwert-Rueckgabe 
{
	this->sensorValue = analogRead(sensorPin);		// Speicherung des analogen Signals in der Variable sensorValue 
	return sensorValue;					// Ausgabe der Variable sensorValue
}
