#include "SDModule.h"

SDModule::SDModule(String aName):Part(aName){}

SDModule::SDModule(String aName, int aPin):Part(aName)									//Konstruktor mit Initialisieung des Namens und des Pins
{
	this->sdPin = aPin;
}

bool SDModule::initSD() 												//Kontrolle, ob die SD-Karte gefunden und angesprochen werden kann
{
	SPI.begin();
	pinMode(sdPin, OUTPUT);
	if (!SD.begin(sdPin)) 												//Überprüft, ob die SD Karte gelesen werden kann
	{ 	Serial.println("SD-Karte konnte nicht initialisiert werden.");
		return false;}													//wenn nein, gibt es false zurück
	
	else{																// Wenn ja, dann öffnet es eine Datei
		File myFile = SD.open ("datalog.csv", FILE_WRITE);
		if (myFile)														//Wenn auf die Datei zugegriffen werden kann
		{
			myFile.close();												//Wird die Datei wieder geschlossen
			Serial.println("SD-Karte ist initialisiert");
			return true;												//Und Die Funktion gibt true zurück
		}
	}
}


int SDModule::getRowCount (String aDatei)						//Gibt die Zeilenzahl einer Datei zurück
{

		File dataFile;											//Erstellung eines Objektes
		int count;												//Zählvariable wird erstellt
		dataFile = SD.open(aDatei);								//Die gewünschte Datei wird geöffnet
		if (dataFile)											//Wenn die Datei geöffnet worden konnte
		{
			while (dataFile.available())						//Die Datei wird Zeile für Zeile abgelaufen
			{
				count++;										//und solange Zeilen vorhanden sind, wird die Zählvariable um 1 erhöht
			}
			dataFile.close();									//Datei wird geschlossen
		}
		else { return 0;}										//Wenn die Datei nicht geöffnet werden konnte, wird 0 zurückgegeben
		return count;											//Rückgabe der Zählvariable

}

bool SDModule::writeRow(String aDatei, String dataString)		//Schreibt eine Zeile mit übergebenen Inhalt in die gewünschte Datei
{
		File dataFile;											//Erstellung eines Objektes
		dataFile = SD.open(aDatei, FILE_WRITE);					//Die gewünschte Datei wird geöffnet zum schreiben vorbereitet
		if (dataFile)											//Wenn die Datei geöffnet worden konnte
		{
			dataFile.println(dataString);						//Wird der übergebene Inhalt in die Datei geschrieben
			dataFile.close();									//Datei wird geschlossen
			return 1;											//Gibt anschließend 1/True zurück
		}
		else {return 0;}										//Wenn die Datei nicht geöffnet werden konnte, wird 0/false zurückgegeben
}


String SDModule::readRow(String aDatei, int aRow)				//Liest eine gewünschte Zeile aus einer Datei aus
{
	String content;												//Variable für den Inhalt der Zeile
		File dataFile;											//Erstellung eines Objektes
		dataFile = SD.open(aDatei);								//Die gewünschte Datei wird geöffnet
		if(dataFile)											//Wenn die Datei geöffnet worden konnte
		{
			for (int i=0; i<aRow; i++)							//Die Datei wird Zeile für Zeile bis zur gewünschten Zeile abgelaufen
			{
				if (dataFile.available())
				{	content = dataFile.read();}					//und der Inhalt wird in der Variable gespeichert
			}
		}
	return content;												//Gibt anschließend den Wert der Variable und somit den Inhalt der letzten/gewünschten Zeile zurück
}
