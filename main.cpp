// $Id$
/**
 * \file main.cpp
 * \brief Testprogramm der Klassen
 *
 * Die Aufgabe zeigt den Umgang mit Klassen, Methoden und Funktionen. Die Datei 
 * main.cpp ist nur zum Testen der Klassen vorhanden.
 */

#include <iostream>
#include "container.h"
#include "exceptions.h"

using namespace std;

/**
 * Globale Variablen
 * hier wird die maximale Medien Anzahl festgelegt
 */
Container container;

/** 
 * Prototypen
 * So koennen die Funktionen nach der "main" angelegt werden
 */
void create_Medium();
void create_Buch();
void create_Video();
void show_Medien();
void entleihe_Medium();
void rueckgabe_Medium();
void loesche_Medium();

int main() {
	char auswahl = '\0';

	/**
	 * Lies Optionen von stdin, pro Option ist eine "hilfs" Funktion
	 * hinterlegt, diese ruft dann ggf. ein Methode der Klasse auf oder
	 * erstellt ein Objekt.
	 */
	while( auswahl != 'q' ) {
		cout << "Medienverwaltung\n"
			 << "----------------\n\n";
		cout << "(m) Neues Medium anlegen\n"
			 << "(b) Neues Buch anlegen\n"
			 << "(v) Neues Video anlegen\n"
			 << "(l) Medien anzeigen\n"
			 << "(e Signatur) Entleihen eines Mediums\n"
			 << "(r Signatur) Rueckgabe eines Mediums\n"
			 << "(d Signatur) Loeschen eines Mediums\n"
			 << "(q) Programm beenden\n\n";
		cout << "Auswahl: ";
		cin >> auswahl;

		switch (auswahl) {
			case 'm': create_Medium(); break;
			case 'b': create_Buch(); break;
			case 'v': create_Video(); break;
			case 'l': show_Medien(); break;
			case 'e': entleihe_Medium(); break;
			case 'r': rueckgabe_Medium(); break;
			case 'd': loesche_Medium(); break;
		}
	}

	return 0;
}

/**
 * \fn void create_Medium()
 * \brief Erstellt ein neues Medium Objekt
 */
void create_Medium() {
	Medium* m_tmp = new Medium;
	container.add(m_tmp);
}

/**
 * \fn void create_Buch()
 * \brief Erstellt ein neues Buch Objekt
 */
void create_Buch() {
	Buch* m_tmp = new Buch;
	container.add(m_tmp);
}

/**
 * \fn void create_Video()
 * \brief Erstellt ein neues Video Objekt
 */
void create_Video() {
	Video* m_tmp = new Video;
	container.add(m_tmp);
}

/**
 * \fn void show_Medium()
 * \brief 
 */
void show_Medien() {
	container.begin();
	if (container.getitem() != NULL) {
		Medium::show_Headline();
		for (;container.getitem() != NULL; container.next()) {
			container.getitem()->show_Medium();
		}
		cout << endl;
	}
	else {
		cout << "\nEs wurden noch keine Medien angelegt.\n\n";
	}
}

/**
 * \fn void entleihe_Medium()
 * \brief Liest Signatur von stdin
 */
void entleihe_Medium() {
	int signatur;
	cin >> signatur;

	for (container.begin(); container.getitem() != NULL; container.next()) {
		if (container.getitem()->get_signatur() == signatur) {
			try { container.getitem()->entleihe_Medium(); }
			catch (StatusError error) {cout << error.text(); }
		}
	}
}

/**
 * \fn void rueckgabe_Medium()
 * \brief Liest Signatur von stdin
 */
void rueckgabe_Medium() {
	int signatur;
	cin >> signatur;

	for (container.begin(); container.getitem() != NULL; container.next()) {
		if (container.getitem()->get_signatur() == signatur) {
			try { container.getitem()->rueckgabe_Medium(); }
			catch (StatusError error) { cout << error.text(); }
		}
	}
}

/**
 * \fn void loesche_Medium()
 * \brief Liest Signatur von stdin
 */
void loesche_Medium() {
	int signatur;
	cin >> signatur;

	for (container.begin(); container.getitem() != NULL; container.next()) {
		if (container.getitem()->get_signatur() == signatur) {
			if (container.del()) {
				cout << endl << "Element wurde erfolgreich geloescht!\n" << endl;
				break;
			}
		}
	}
}

