#include "head.h"

void Finder(bool* e, const char* filename) {

	// vedo se ha estensione
	if (strchr(filename, '.') != NULL) {
		*e = true;
	}



	return;
}