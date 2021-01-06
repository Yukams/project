/// \file vernam_header.h
/// \author Vincent Dugat
/// \date mai 2020
#ifndef DH_H
#define DH_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <ctype.h> // opérations sur les caractères
/*#include "dh_bal.h"*/

#define MAX_FACTEURS 10 // nb max de facteurs premiers d'un nombre
#define BLOCK_SIZE 16 // taille des blocs pour CBC
#define LONGMAX 1000
#define ERROR -1
#define END -1

extern FILE *logfp; // fichier pour le debug

typedef unsigned char byte; // octet
typedef byte block_t[BLOCK_SIZE]; // bloc CBC : un octet par case

// à compléter
#endif
