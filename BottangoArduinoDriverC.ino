// !!! DRIVER VERSION: 0.7.0a1 !!!
// !!! Api Version: 8 !!!

#include "src/BottangoCore.h"
#include "src/BasicCommands.h"
#include <Wire.h>

void setup()
{
	Serial.begin ( 115200 );
	Wire.begin ( 9 );
	Wire.onReceive ( receiveEvent );
	BottangoCore::bottangoSetup();
}

void loop()
{
	BottangoCore::bottangoLoop();
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent ( int howMany )
{
	if ( Wire.available() > 0 )
	{
		int x = Wire.read();    // receive byte as an integer
		Serial.println ( x );
		BottangoCore::commandStreamProvider->startCommandStream ( x, false ); //starts playing an animation (and stops the current if any)
	}
}
