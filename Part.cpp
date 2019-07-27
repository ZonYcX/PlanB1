#include "Part.h"

Part::Part() {}

Part::Part(String aName)
{
    partName = aName;                                        //deklariert Bauteilnamen
}

String Part::getName()
{
    return partName;                                         //gibt Bauteilnamen zurück
}
