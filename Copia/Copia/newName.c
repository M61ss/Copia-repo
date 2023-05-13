#include "head.h"

char* NewName(const char* filename, const int numerocopia) {

	bool e = false;

	// controllo se il file ha un'estensione
	Finder(&e, filename);

	// alloco per il nuovo nome e stabilisco numero della copia
	char n[14] = "";
	sprintf(n, " - Copia (%d)", numerocopia);
	char* cpyname = malloc(strlen(filename) + strlen(n) + 1);     // va aggiunta la dimensione del numero che contrassegna la copia, cioè la stringa " (1)"

	// verifico che sia un file avente estensione
	if (e == true) {

		// copio il nome del file
		char* nome = malloc(2);
		size_t i = 0;
		while (filename[i] != '.') {
			nome = realloc(nome, i + 2);
			nome[i] = filename[i];

			i++;
		}
		nome[i] = 0;

		// copio l'estensione
		char* extention = malloc(2);
		size_t j = 0;
		while (filename[i] != 0) {
			extention = realloc(extention, j + 2);
			extention[j] = filename[i];

			j++;
			i++;
		}
		extention[j] = 0;

		// compongo la prima parte
		char* tmpname = malloc(strlen(nome) + strlen(n) + 1);
		strcpy(tmpname, nome);

		if (numerocopia > 0) {
			strcat(tmpname, n);
		}
		else {
			strcat(tmpname, " - Copia");
		}

		// aggiungo l'estensione
		strcpy(cpyname, tmpname);

		strcat(cpyname, extention);

		// free
		free(nome);
		free(extention);
		free(tmpname);
	}
	// nel caso il file non abbia estensione procedo semplicemente
	else {

		if (numerocopia > 0) {
			strcpy(cpyname, filename);

			strcat(cpyname, n);
		}
		else {
			strcpy(cpyname, filename);

			strcat(cpyname, " - Copia");
		}
	}
	


	return cpyname;
}