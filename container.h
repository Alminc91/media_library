// $Id$
/**
 * \file container.h
 * \brief Header Datei mit der Container und Knoten Klasse
 *
 * Enthaellt die Container Klasse, der Container ist eine
 * Datenstruktur das unsere Medienelemente verwaltet.
 */

#include <iostream>
#include "medien.h"

using namespace std;

/// T ist der Typ der Containerelemente
typedef Medium T;

/**
 * \brief Knoten Klasse
 *
 */
class Knoten {
	friend class Container;
	Knoten* next;
	T* item;

	public:
		Knoten(Knoten* next, T* item) { this->next = next; this->item = item; }
};

/**
 * \brief Container Klasse
 *
 */
class Container {
	/// Zeiger auf das erste Containerelement
	Knoten* first;
	/// Zeiger auf das aktuelle Containerelement
	Knoten* iterator;

	public:
		Container() { first = NULL; iterator = NULL; }
		void add(T* element);
		bool del();
		void begin();
		void next();
		T* getitem();
};
