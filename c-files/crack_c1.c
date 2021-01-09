#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "../Headers/crack_c1.h"

/// \file crack_c1.c
/// \author Valentin Tahon
/// \date Janvier 2021
/// \brief Lance une recherche de clefs de chiffrement XOR composée uniquement de chiffres

// Return file size
int getFileSize(FILE* file) {
    /// \brief Calcule la taille du fichier en nombre de caractères
    /// \return size+1 qui correspond à la taille réelle
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size+1;
}

void crack_c1(char* file_name, int key_length) {
    /// \brief Affiche à l'écran l'ensemble des chiffres de la clef qui correspondent à un dechiffrage ASCII
    /// Cette fonction n'affiche pas les combinaisons de clefs en tant que tel, ni les clefs les plus probables
    //ASCII values between 0 and 127
    FILE* fromFile = fopen(file_name, "r");
    
    int keys[key_length][10];
    int crack;
    int message_size = getFileSize(fromFile);
    char message[message_size];
    
    //Gets message
    int m = 0;
    char ch;
    while((ch = fgetc(fromFile)) != EOF) {
        message[m]=ch;
        m++;
    }
    
    //Finds possible keys
    int z;
    int isTrue;
    int i;
    for(int k=0; k < key_length; k++) {
        z = 0;
        printf("[");
        for(char value = 48; value < 58; value++) {
            if(k == 0 && value == 48) {value++;}
            isTrue = 0;
            i = 0;
            while(k+(key_length*i) < message_size) {
                if(!isalnum(message[k+(key_length*i)]^value) && !ispunct(value^message[k+(key_length*i)]) && !isspace(message[k+(key_length*i)]^value)) {
                    isTrue = 1;
                    break;
                }
                i++;
            }
            if(isTrue == 0) {
                keys[k][z]=value;
                z++;
                printf("%c,", value);
            }
            if(value == 57) {
                printf("]");
            }
        }
        printf("\n");
    }
    printf("\n\nEverything is under control my friend\n");
}
