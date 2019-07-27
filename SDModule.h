#ifndef SDMODULE_H
#define SDMODULE_H
#include <SPI.h>
#include <SD.h>
#include "Part.h"
#include <Arduino.h>


class SDModule : public Part
{
    public:	
		SDModule(String aName);
		SDModule(String aName, int aPin);									//Konstruktor mit Initialisieung des Namens und des Pins
		
		bool initSD();											//Kontrolle, ob die SD-Karte gefunden und angesprochen werden kann
		int getRowCount(String aDatei);							//Gibt die Zeilenzahl einer Datei zurück
		bool writeRow(String aDatei, String aData);				//Schreibt eine Zeile mit übergebenen Inhalt in die gewünschte Datei
		String readRow(String aDatei, int aRow);				//Liest eine gewünschte Zeile aus einer Datei aus
		


    protected:
		int sdPin;												//enthält den Arduino-Pin, an welchem das SDModule angeschlossen ist

    private:
};

#endif // SDMODULE_H
