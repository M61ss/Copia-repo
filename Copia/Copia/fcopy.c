#include "head.h"

void fcopy(FILE* f, const char* filename, const int ncopie) {

	for (int i = 0; i < ncopie; i++) {

		// mi riporto sempre a inizio file
		rewind(f);

		// creo il nuovo nome
		char* cpyname = newName(filename, i);

		// decl f cpy
		FILE* cpy = fopen(cpyname, "wb");

		// coping
		char tmp = 1;

		while (1) {

			// leggo dall'originale
			if (fread(&tmp, 1, 1, f) != 1) {

				// se ho finito o dà errore interrompo
				break;
			}

			// copio
			if (fwrite(&tmp, 1, 1, cpy) != 1) {

				// se c'è un errore interrompo
				break;
			}
		}

		// closing & free
		fclose(cpy);
		free(cpyname);
	}



	return;
}