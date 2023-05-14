#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Funzioni di elaborazione
extern void Copy(FILE* f, char* filename, const int ncopie);
extern char* NewName(char* filename, const int numerocopia);
extern void Finder(char* extension, char* filename);