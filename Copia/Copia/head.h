#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"

extern void fcopy(FILE* f, const char* filename, const int ncopie);
extern char* newName(const char* filename, const int numerocopia);
extern void finder(bool* e, const char* filename);