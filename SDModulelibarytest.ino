#include <DS3231.h>
#include <Wire.h>
#include <SD.h>
#include <SPI.h>
#include "YL69.h"
#include "Relais.h"
#include "LDR.h"
#include "SimpleDHT.h"
int pindht = 2;
DS3231 clock;
RTCDateTime dt;
SimpleDHT11 DHT(pindht);
File myFile;
LDR Licht("Licht", A2);
YL69 YL1("Bodenfeuchte", A0);
Relais Pumpe("Pumpe", 7);
Relais Lampe("Lampe", 7);
Relais Heizung("Heizung", 7);
Relais Luefter("Luefter", 7);



class Tempsensor : public Sensor {
private:
  byte temperature;
public:
  Tempsensor(String aName);
  int getSensorValue();
};

Tempsensor::Tempsensor(String aName) : Sensor(aName)
{
  temperature = 0;
}
int Tempsensor::getSensorValue()
{
  byte dummy = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = DHT.read(&temperature, &dummy, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("TEMPPPP Read DHT11 failed, err="); Serial.println(err); delay(1000);
    return 0;
  }
  delay(1500);    // delay damit der sensor vernünftog arbeiten kann und es keinen error gibt
  return (int)temperature;
}
class Humiditysensor : public Sensor {
private:
  byte humidity;
public:
  Humiditysensor(String aName);
  int getSensorValue();
};

Humiditysensor::Humiditysensor(String aName) : Sensor(aName)
{
  humidity = 0;
}
int Humiditysensor::getSensorValue()
{
  byte dummy = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = DHT.read(&dummy, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("HUMMMM Read DHT11 failed, err="); Serial.println(err); delay(1000);
    return 0;
  }
  delay(1500);// delay damit der sensor vernünftog arbeiten kann und es keinen error gibt
  return (int)humidity;
}
  Tempsensor T1("Temperatursensor");
  Humiditysensor H1("Humiditysensor");

  const int Sensoranzahl = 4;
  Sensor** Sensorarray = NULL;
  Relais** Relaisarray = NULL;
  int hours, seconds, minutes;
  int Vergleichswerte[Sensoranzahl] = { 50,50,50,50 };
  int Aktivitaetsdauer[Sensoranzahl] = { 4000,4000,4000,4000 };


void setup()
{
  Serial.begin(9600);

  

  Sensorarray = new Sensor*[Sensoranzahl];
  Sensorarray[0] = &T1;
  Sensorarray[1] = &H1;
  Sensorarray[2] = &Licht;
  Sensorarray[3] = &YL1;

  Relaisarray = new Relais*[Sensoranzahl];
  Relaisarray[0] = &Heizung;
  Relaisarray[1] = &Luefter;
  Relaisarray[2] = &Lampe;
  Relaisarray[3] = &Pumpe;


  //========== SD Module
  /*while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");


  if (!SD.begin(5)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  myFile = SD.open("test.txt", FILE_WRITE);

  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
    // close the file:
    myFile.close();
    Serial.println("done.");
  }
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }

  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");

    // read from the file until there's nothing else in it:
    while (myFile.available()) {
      Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  }
  else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  //==================== SD Module ende */
  //====== RS3231
  clock.begin();
  clock.setDateTime(__DATE__, __TIME__);

  //===== DHT


}

// Add the main program code into the continuous loop() function
void loop()
{
  dt = clock.getDateTime(); //setzt das Objekt dt mit der Zeit gleich
  hours = dt.hour;
  minutes = dt.minute;
  seconds = dt.second;
  String Test = getSensorMerge(hours, minutes, seconds);

  Serial.println(Test);



}

void Aktivitaetspruefung()
{
  for (int i = 0; i < Sensoranzahl; i++)
  {
    if (Sensorarray[i]->getSensorValue() < Vergleichswerte[i])
    {
      Relaisarray[i]->Toggel(Aktivitaetsdauer[i]);
    }
  }
}


String getSensorMerge(int hour, int min, int sec)
{
  String ergebnis = "";
  ergebnis += (String)hour + ':' + (String)min + ':' + (String)sec + " : ";
  for (int i = 0; i < Sensoranzahl; i++)
  {
    ergebnis += Sensorarray[i]->getName() + " : " + Sensorarray[i]->getSensorValue() + "; ";
  }
  return ergebnis;
}




bool writeRowSD(String aDatei, String dataString)   //Schreibt eine Zeile mit übergebenen Inhalt in die gewünschte Datei
{
  File dataFile;                      //Erstellung eines Objektes
  dataFile = SD.open(aDatei, FILE_WRITE);         //Die gewünschte Datei wird geöffnet zum schreiben vorbereitet
  if (dataFile)                     //Wenn die Datei geöffnet worden konnte
  {
    dataFile.println(dataString);           //Wird der übergebene Inhalt in die Datei geschrieben
    dataFile.close();                 //Datei wird geschlossen
    return 1;                     //Gibt anschließend 1/True zurück
  }
  else { return 0; }                    //Wenn die Datei nicht geöffnet werden konnte, wird 0/false zurückgegeben
}



int getRowCount(String aDatei)            //Gibt die Zeilenzahl einer Datei zurück
{

  File dataFile;                      //Erstellung eines Objektes
  int count;                        //Zählvariable wird erstellt
  dataFile = SD.open(aDatei);               //Die gewünschte Datei wird geöffnet
  if (dataFile)                     //Wenn die Datei geöffnet worden konnte
  {
    while (dataFile.available())            //Die Datei wird Zeile für Zeile abgelaufen
    {
      count++;                    //und solange Zeilen vorhanden sind, wird die Zählvariable um 1 erhöht
    }
    dataFile.close();                 //Datei wird geschlossen
  }
  else { return 0; }                    //Wenn die Datei nicht geöffnet werden konnte, wird 0 zurückgegeben
  return count;                     //Rückgabe der Zählvariable

}
