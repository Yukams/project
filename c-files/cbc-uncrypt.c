#include <stdio.h>
#include "../Headers/cbc-uncrypt.h"

/// \file cbc-uncrypt.c
/// \author Valentin Tahon
/// \date Janvier 2021
/// \brief Effectue un décryptage d'un fichier grâce à la méthode de décryptage CBC

void cbc_uncrypt(char* file_name, char* file_to_write, char* vector, char* key) {
    /// \brief Effectue un décryptage d'un fichier grâce à la méthode de décryptage CBC
    /// \param[in] file_name : nom du fichier source
    /// \param[in] file_to_write : nom du fichier de destination
    /// \param[in] vector : le vecteur d'initialisation
    /// \param[in] key : clef de chiffrement
    FILE* fromFile = fopen(file_name, "r");
    FILE* toFile = fopen(file_to_write, "w");
    
    int k=1;
    int block=0;
    int ch;
    char v[16];
    for(int i=0; i<16; i++) {
        v[i]=vector[i];
    }
    
    while((ch = fgetc(fromFile)) != EOF || block != 0) {
        if(ch == EOF) {
            ch = ' ';
        }
        char output = v[block]^(key[k]^ch);
        fprintf(toFile, "%c", output);
        v[block] = ch;
        
        block++;
        k++;
        if(block == 16) {
            k = 1;
            block = 0;
        } else if (key[k] == '\0') {
            k = 0;
        }
    }
    
    fclose(fromFile);
    fclose(toFile);
}
