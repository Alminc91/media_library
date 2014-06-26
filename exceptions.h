// $Id$
/**
 * \file exceptions.h
 * \brief Header Datei fuer unsere eigene Exception
 *
 * Fuert unser eigenes Exception Handling durch, die
 * Methode bzw. der Konstruktor gibt den Fehler auf
 * der Konsole aus und schreibt eine Logdatei.
 */

#ifndef _EX_
#define _EX_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class StatusError {
	string fehlertext;

	public:		
		StatusError(int signatur, int fehlernr);
		string text() { return fehlertext;} 
};

#endif
