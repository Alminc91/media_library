// $Id$
/**
 * \file medien.h
 * \brief Header Datei mit allen Klassen
 *
 * Enthaellt alle Klassen fuer unsere Medienverwaltung
 */

#include <string>

using namespace std;

enum eStatus {
	entliehen,
	praesent
};

/**
 * \brief Vater Klasse Medium
 */
class Medium {
	protected:
		int signatur;
		string titel;
		eStatus status;

	public:
		Medium();
		Medium(bool b) { }
		static void show_Headline();
		virtual void show_Medium();
		void entleihe_Medium();
		void rueckgabe_Medium();
		int get_signatur() { return signatur; }
};

/**
 * \brief Abgeleite Buch Klasse der Medium Klasse
 */
class Buch: public Medium {
	int seitenzahl;

	public:
		Buch();
		void show_Medium();
};

/**
 * \brief Abgeleite Video Klasse der Medium Klasse
 */
class Video: public Medium {
	double spieldauer;

	public:
		Video();
		void show_Medium();
};
