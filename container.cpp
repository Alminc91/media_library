// $Id$
/**
 * \file container.cpp
 * \brief Container Methoden
 *
 * ...
 */

#include "container.h"

void Container::add(T *element) {
	Knoten* k_tmp = new Knoten(first,element);

	if (first == NULL)
		iterator = k_tmp;

	first = k_tmp;
}

/**
 * \brief Loescht ein Element aus dem Container
 *
 */
bool Container::del() {
	/// Pruefen ob Element in der Liste
	if (iterator == NULL)
		return false;

	Knoten* k_tmp = first;
	if (iterator == first) {
		/// Erstes Element
		first = first->next;
		delete k_tmp->item;
		delete k_tmp;
		iterator = first;
	}
	else {
		/// Vorgaengerelement vom aktuellen Element suchen
		while ((k_tmp != NULL) && (k_tmp->next != iterator)) {
			k_tmp = k_tmp->next;
		}
		/// Falls Vorgaengerelement nicht vorhanden Liste NULL
		if (k_tmp == NULL)
			return false;
		k_tmp->next = iterator->next;
		delete iterator->item;
		delete iterator;
		iterator = k_tmp;
	}
	return true;
}

/**
 * \brief Erstes Element wird zum aktuellen Element
 *
 */
void Container::begin() {
	iterator = first;
}

/**
 * \brief Naechstes Element wird zum aktuellen Element
 *
 */
void Container::next() {
	if (iterator != NULL)
		iterator = iterator->next;
}

/**
 * \brief Liefere Zeiger auf aktuelles Element
 *
 */
T* Container::getitem() {
	if (iterator == NULL)
		return NULL;
	else
		return iterator->item;
}
