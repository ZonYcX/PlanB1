#ifndef YL69_H
#define YL69_H
#include "Sensor.h"
#include "Part.h"
#include "Arduino.h"

class YL69 : public Sensor						// Klasse YL69 erbt von Sensor und Part
{
			public: 
					YL69(String aName);			// Konstruktoren
					YL69(String aName, int aPin);
					
					int getSensorValue ();			// Funktion fuer Messwert-Rueckgabe
				
			protected:
										
			
			private:
		
};

#endif // YL69_H 		
		
