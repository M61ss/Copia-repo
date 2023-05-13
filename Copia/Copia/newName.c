#include "head.h"

char* NewName(const char* filename, const int numerocopia) {

	// Controllo se il file ha un'estensione
	bool e = false;
	Finder(&e, filename);

	// Alloco per il nuovo nome e stabilisco numero della copia
	char n[14] = "";
	sprintf(n, " - Copia (%d)", numerocopia);
	char* cpyname = malloc(strlen(filename) + strlen(n) + 1);     // Va aggiunta la dimensione del numero che contrassegna la copia, cioè la stringa " (1)"

	// Verifico che sia un file avente estensione
	if (e == true) {

		// Copio il nome del file
		char* nome = malloc(2);
		size_t i = 0;
		while (filename[i] != '.') {
			nome = realloc(nome, i + 2);
			nome[i] = filename[i];

			i++;
		}
		nome[i] = 0;

		// Copio l'estensione
		char* extention = malloc(2);
		size_t j = 0;
		while (filename[i] != 0) {
			extention = realloc(extention, j + 2);
			extention[j] = filename[i];

			j++;
			i++;
		}
		extention[j] = 0;

		// Compongo la prima parte
		char* tmpname = malloc(strlen(nome) + strlen(n) + 1);
		strcpy(tmpname, nome);

		if (numerocopia > 0) {
			strcat(tmpname, n);
		}
		else {
			strcat(tmpname, " - Copia");
		}

		// Aggiungo l'estensione
		strcpy(cpyname, tmpname);

		strcat(cpyname, extention);

		// free
		free(nome);
		free(extention);
		free(tmpname);
	}
	// Nel caso il file non abbia estensione procedo semplicemente
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