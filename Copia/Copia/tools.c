#include "head.h"

// Funzione per rimuovere gli a capo catturati da fgets
void BackRemove(char* buffer) {

	for (int i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == '\n') {

			for (int j = i; j < strlen(buffer); j++) {

				buffer[j] = buffer[j + 1];
			}
		}
	}
}