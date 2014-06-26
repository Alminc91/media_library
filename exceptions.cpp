// $Id$
/**
 * \file exceptions.cpp
 * \brief Exception Handling
 *
 * ...
 */

#include "exceptions.h"

using namespace std;

/**
 * \brief Konstruktor fuer das eigene Exception Handling
 *
 */
StatusError::StatusError(int signatur, int fehlernr) {
	ostringstream s;
	/// ERROR.LOG Datei wird angelegt und geschrieben
	fstream log("ERROR.LOG", ios::out | ios::app);

	if (fehlernr)
		s << "\nFehler bei der Ruecknahme von Signatur: ";
	else 
		s << "\nFehler beim Verleih von Signatur: ";

	s << signatur << "\n";

	/// Ausgabe in Logdatei und Variable fehlertext
	fehlertext = s.str();
	log << fehlertext;
	log.close();

}
