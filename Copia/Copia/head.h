#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Funzioni di elaborazione
extern void Copy(FILE* f, const char* filename, const int ncopie);
extern char* NewName(const char* filename, const int numerocopia);
extern void Finder(char* extension, const char* filename);

// Tools
extern void BackRemove(char* buffer);