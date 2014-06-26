#include <iostream>
#include <iomanip>
#include "medien.h"
#include "exceptions.h"

using namespace std;

/**
 * \brief Konstruktor der Klasse Medium
 *
 * Der jeweilige Konstruktor liest die Signatur den Titel etc.
 * von stdin.
 */
Medium::Medium() {
	status = praesent;
	do {
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << "Bitte Mediumdaten eingeben: Signatur, Seitenzahl und Titel\n\n";
		cout << "Signatur: ";
	} while (!(cin >> signatur) && cin.fail());
	cout << "Titel: ";
	/// \bug http://stackoverflow.com/questions/1734480/c-string-question
	cin.ignore( numeric_limits<streamsize>::max(), '\n' );
	getline(cin, titel );
	cout << "\nDie Mediendaten wurden gespeichert.\n\n";
}

void Medium::show_Headline() {
	cout << setw(10) << "Signatur  " << left << setw(8)  << "Typ" 
	     << setw(22) << "Titel"      << left << setw(12) << "Status"
		 << setw(20) << "weitere Daten" << endl;
}

/**
 * \brief Gibt die Medium Informationen an stdout aus
 *
 * Das Medium wird an stdout ausgegeben, hierbei wird per setw()
 * Breite angeben und somit tabellarisch ausgegeben.
 */
void Medium::show_Medium() {	
	cout << right << setw(8) << signatur << "  " << left << setw(8) << "Medium" 
	     << setw(22);

	if (titel.size() > 20) {
		string kurztitel = titel.substr(0,17);
		kurztitel += "...";
		cout << kurztitel;
	}
	else {
		cout << titel;
	}
	cout << left << setw(12);

	if (status == entliehen) cout << "entl.";
	else cout << "vorh.";

	cout << endl;
}

/**
 * \brief Entleiht ein Medium
 *
 * Zur Entleihung eines Mediums wird entliehen auf wahr gesetzt.
 */
void Medium::entleihe_Medium() {
	if (status == praesent) {
		status = entliehen;
		cout << "\nDas Medium wurde entliehen.\n\n";
	}
	else {
		throw StatusError(signatur, 0);
	}
}

/**
 * \brief Rueckgabe eines Medium
 *
 * Zur Rueckgabe wird entliehen auf unwahr gesetzt.
 */
void Medium::rueckgabe_Medium() {
	if (status == entliehen) {
		status = praesent;
		cout << "\nDas Medium wurde zurueckgenommen.\n\n";
	}
	else {
		throw StatusError(signatur, 1);
	}
}

/**
 * \brief Konstruktor der Klasse Buch
 *
 * Damit bei der Buch Klasse der Default Konstruktor der
 * Klasse Medium nicht aufgerufen wird, wird dieser mit
 * einem Konstruktor Medium(false) ueberschrieben.
 */
Buch::Buch(): Medium(false) {
	status = praesent;
	do {
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << "Bitte Buchdaten eingeben: Signatur, Seitenzahl und Titel\n\n";
		cout << "Signatur: ";
	} while (!(cin >> signatur) && cin.fail());
	cout << "Seitenzahl: ";
	cin >> seitenzahl;
	cout << "Titel: ";
	/// \bug http://stackoverflow.com/questions/1734480/c-string-question
	cin.ignore( numeric_limits<streamsize>::max(), '\n' );
	getline(cin, titel, '\n');
	cout << "\nDie Buchdaten wurden gespeichert.\n\n";
}

/**
 * \brief Gibt die Buch Informationen an stdout aus
 *
 * Das Buch wird an stdout ausgegeben, hierbei wird per setw()
 * Breite angeben und somit tabellarisch ausgegeben.
 */
void Buch::show_Medium() {
	cout << right << setw(8) << signatur << "  " << left << setw(8) << "Buch" 
	     << setw(22);

	if (titel.size() > 20) {
		string kurztitel = titel.substr(0,17);
		kurztitel += "...";
		cout << kurztitel;
	}
	else {
		cout << titel;
	}
	cout << left << setw(12);

	if (status == entliehen) cout << "entl.";
	else cout << "vorh.";

	cout << left << "Seitenzahl " << seitenzahl << endl;
}

/**
 * \brief Konstruktor der Klasse Video
 *
 * Damit bei der Video Klasse der Default Konstruktor der
 * Klasse Medium nicht aufgerufen wird, wird dieser mit
 * einem Konstruktor Medium(false) ueberschrieben.
 */
Video::Video(): Medium(false) {
	status = praesent;
	do {
		cin.clear();
		cin.ignore( numeric_limits<streamsize>::max(), '\n' );
		cout << "Bitte Videodaten eingeben: Signatur, Spieldauer und Titel\n\n";
		cout << "Signatur: ";
	} while (!(cin >> signatur) && cin.fail());
	cout << "Spieldauer: ";
	cin >> spieldauer;
	cout << "Titel: ";
	/// \bug http://stackoverflow.com/questions/1734480/c-string-question
	cin.ignore( numeric_limits<streamsize>::max(), '\n' );
	getline(cin, titel, '\n');
	cout << "\nDie Videodaten wurden gespeichert.\n\n";
}

/**
 * \brief Gibt die Video Informationen an stdout aus
 *
 * Das Video wird an stdout ausgegeben, hierbei wird per setw()
 * Breite angeben und somit tabellarisch ausgegeben.
 */
void Video::show_Medium() {
	cout << right << setw(8) << signatur << "  " << left << setw(8) << "Video" 
	     << setw(22);

	if (titel.size() > 20) {
		string kurztitel = titel.substr(0,17);
		kurztitel += "...";
		cout << kurztitel;
	}
	else {
		cout << titel;
	}
	cout << left << setw(12);

	if (status == entliehen) cout << "entl.";
	else cout << "vorh.";

	cout << left << "Dauer " << fixed << setprecision(2) << spieldauer << " min" << endl;
}
