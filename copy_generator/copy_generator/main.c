#include "head.h"

/*
Il seguente programma non è pensato per essere utilizzato singolarmente, ma per essere inserito in un programma più complesso.
In caso di necessità di creare delle copie di alcuni file per conto del programma che ha in uso questo stesso, il compito
di questo codice sarà di generare uno o più duplicati dei file specificati (controllando se essi esistano e che le copie vengano
generate correttamente). L'esecuzione intende interrompersi subito dopo la creazione (con successo o insuccesso) delle copie,
in quanto l'obiettivo è utilizzare tale codice come strumento integrato al programma che lo ha in uso tramite
chiamata via linea di comando.
*/

int main(void) {

	// Stringhe container per il nome del file e il numero di copie da creare
	char* filename = calloc(51, sizeof(char));
	char* ncopie = calloc(9, sizeof(char));

	while (1) {

		printf("Inserisci il percorso del file del quale vuoi creare una copia: ");
		fgets(filename, 50, stdin);
		filename[strlen(filename) - 1] = filename[strlen(filename)];

		printf("Inserisci il numero di copie che desideri creare: ");
		fgets(ncopie, 8, stdin);
		ncopie[strlen(ncopie) - 1] = ncopie[strlen(ncopie)];

		const int numero_copie = atoi(ncopie);
		if (numero_copie < 1) {

			printf("Nessuna copia del file selezionato creata.\n");
			free(ncopie);					// Libero la memoria allocata per ncopie, tanto non serve più
			break;
		}
		free(ncopie);


		// Apertura del file
		FILE* f = fopen(filename, "rb");
		if (f == NULL) {

			printf("\nIl file specificato risulta essere inesistente.\n"
				"Verificare che il percorso inserito sia valido, quindi riprovare.\n\n");
			continue;
		}


		// Chiamata alla funzione per la creazione delle copie
		Copy(f, filename, numero_copie);


		// Messaggio di conferma sulla creazione delle copie
		if (numero_copie == 1) {
			printf("\nCopia del file creata correttamente.\n\n");
		}
		else {
			printf("\nCopie del file create correttamente: %d.\n\n", numero_copie);
		}

		// Chiudo il file
		fclose(f);
		break;
	}


	// Libero la memoria
	free(filename);

	return EXIT_SUCCESS;
}