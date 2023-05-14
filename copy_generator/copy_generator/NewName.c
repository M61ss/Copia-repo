#include "head.h"

char* NewName(char* filename, const int numerocopia) {

	// Controllo se il file ha un'estensione
	char* extension = calloc(6, sizeof(char));
	Finder(extension, filename);

	// Alloco per il nuovo nome e stabilisco numero della copia
	char* suffisso = calloc(20, sizeof(char));
	sprintf(suffisso, " - Copia (%d)", numerocopia);
	char* cpyname = malloc(strlen(filename) + strlen(suffisso) + strlen(extension) + 1);     // Al nome del file va aggiunta la dimensione del numero che contrassegna la copia, cioè la stringa " (1)"

	// Verifico che sia un file avente estensione
	if (extension[0] == '.') {

		// Compongo la prima parte (filename + suffisso)
		cpyname = realloc(cpyname, strlen(filename) + strlen(suffisso) + strlen(extension) + 1);
		strcpy(cpyname, filename);

		if (numerocopia > 0) {
			strcat(cpyname, suffisso);
		}
		else {
			strcat(cpyname, " - Copia");
		}

		// Aggiungo l'estensione ((filename + suffisso) + extension)
		strcat(cpyname, extension);

		// Riassegno al filename originario la sua estensione
		strcat(filename, extension);

	}
	// Nel caso il file non abbia estensione procedo semplicemente
	else {

		if (numerocopia > 0) {
			strcpy(cpyname, filename);
			strcat(cpyname, suffisso);
		}
		else {
			strcpy(cpyname, filename);
			strcat(cpyname, " - Copia");
		}
	}


	// Libero la memoria
	free(extension);
	free(suffisso);

	return cpyname;
}