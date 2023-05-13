#include "head.h"

/*
A partire dal fondo della stringa cerco un punto che si trovi a una distanza di massimo 5 caratteri (punto compreso) dalla fine
del nome del file. In questo modo abbasso drasticamente le probabilità di rilevazione di false estensioni provocate dalla presenza
di punti arbiatrari inseriti dagli utenti nei nomi che danno ai file. Infine copio l'estensione in una stringa a parte e la rimuovo
da quella principale.
*/

void Finder(char* extension, char* filename) {

	// Se incontro un punto entro 5 caratteri considero che il file abbia estensione
	bool flag = false;
	size_t counter = 0;
	for (size_t i = strlen(filename) - 1; counter != 5; i--) {
		if (filename[i] == '.') {

			counter++;
			flag = true;
		}
		counter++;
	}

	// Se il file ha estensione, copio quest'ultima in extention
	if (flag == true) {

		for (size_t i = strlen(filename) - 1; counter != 0; i--) {
			
			extension[counter] = filename[i];

			// Cancello da filename il carattere trasferito in extension
			for (size_t j = i; j < strlen(filename); j++) {

				filename[j] = filename[j + 1];
			}

			counter--;
		}
	}


	return;
}