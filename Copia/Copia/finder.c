#include "head.h"

/*
A partire dal fondo della stringa cerco un punto che si trovi a una distanza di massimo 5 caratteri (punto compreso) dalla fine
del nome del file. In questo modo abbasso drasticamente le probabilità di rilevazione di false estensioni provocate dalla presenza
di punti arbiatrari inseriti dagli utenti nei nomi che danno ai file.
*/

void Finder(bool* e, const char* filename) {

	// Se incontro un punto vuol dire che il nome del file ha estensione
	size_t counter = 0;
	for (size_t i = strlen(filename) - 1; counter != 5; i--) {

		if (filename[i] == '.') {

			*e = true;
		}
		counter++;
	}


	return;
}