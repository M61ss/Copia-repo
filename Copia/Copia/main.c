#include "head.h"

int main(void) {

	// decl
	char filename[50];
	filename[49] = 0;
	int ncopie = 0;



	// inserimento nome file
	printf("Inserisci il percorso del file del quale vuoi creare una copia: ");
	if (scanf("%[^\n]c", filename) == 0) {
		printf("Errore: il testo inserito non e' valido.\n\n");
		return 0;
	}
	printf("\n");

	// inserimento numero copie
	printf("Inserisci il numero di copie che desideri creare: ");
	if (scanf("%d", &ncopie) == 0) {
		printf("Errore: il numero inserito non e' valido.\n\n");
		return 0;
	}
	printf("\n");

	// crt inserimenti
	if (ncopie < 1) {
		printf("Numero di copie inserito non valido.\n\n");
		return 0;
	}



	// fopen
	FILE* f = fopen(filename, "rb");

	// crt se esiste il file
	if (f == NULL) {
		printf("Il file risulta essere inesistente.\nVerificare che il percorso inserito sia valido, quindi riprovare.\n\n");
		return 1;
	}



	// f call
	fcopy(f, filename, ncopie);



	// mess
	if (ncopie == 1) {
		printf("Copia del file creata correttamente.\n\n");
	}
	else {
		printf("Copie del file creata correttamente.\n\n");
	}



	// closing
	fclose(f);



	return 0;
}