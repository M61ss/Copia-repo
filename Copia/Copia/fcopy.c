#include "head.h"

/*
Funzione per creare un numero di copie uguale a quello richiesto dall'utente. Per fare ciò usa un ciclo che crea tanti duplicati
quanti ne sono richiesti.
*/

void Copy(FILE* f, const char* filename, const int numero_copie) {

	for (int i = 0; i < numero_copie; i++) {

		// Mi riporto sempre a inizio file
		rewind(f);

		// Creazione del nuovo nome del file
		char* cpyname = NewName(filename, i);

		FILE* cpy = fopen(cpyname, "wb");

		// Inizio la copia byte per byte
		char tmp = 1;
		while (1) {

			// Leggo dall'originale
			if (fread(&tmp, 1, 1, f) != 1) {

				// Se ho finito o dà errore interrompo
				break;
			}

			// Scrivo sulla copia
			if (fwrite(&tmp, 1, 1, cpy) != 1) {

				// Se c'è un errore interrompo
				break;
			}
		}

		// Chiudo i file aperti e libero la memoria allocata
		fclose(cpy);
		free(cpyname);
	}


	return;
}