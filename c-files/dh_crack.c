#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <assert.h>
#include "../Headers/crack_c1.h"

/// \file dh_crack.c
/// \author Valentin Tahon
/// \date Janvier 2021
/// \brief Lance une recherche de clefs de chiffrement XOR composée uniquement de chiffres, fourni un résultat exhaustif mais non définitif. Ne permet pas d'obtenir LA clef de déchiffrement.

int main(int argc, char *argv[]) {
    /// \brief Programme principal, traite les arguments fournis lors de l'appel du programme
    /// Accepte les options -i (fichier en entrée), -k (taille de la clef de chiffrement), -m (mode de chiffrement), -h (affiche l'aide)
    int opt;
    
    int i=0;
    while (i < argc) {
        if(strcmp(argv[i], "-h") == 0) {
            printf("\nUsage : %s [-h] [-i filename] [-k key_length] [-m c1|all] [-d dictionnary]\n\nOptions :\n[-h]\t\t: Prints help about the command\n[-i filename]\t: File to read the message we want to cypher\n[-k key_length]\t: Key length used to crack\n\n[-m c1|all]\n\t\t: Name of the methods used to crack\n[-d dictionnary]\t: To score how many word each possible key can find", argv[0]);
            exit(255);
        }
        i++;
    }
    
    char* input_file = NULL;
    int key_length;
    char* mode = NULL;
    while((opt = getopt(argc, argv, "i:d:k:m:l:")) != -1)
        {
            switch(opt)
            {
                case 'm':
                    mode = malloc((strlen(optarg) + 1) * sizeof(char));
                    strcpy(mode, optarg);
                    assert( mode != NULL );
                    if(strcmp(mode, "all") == 0) {
                        printf("\nThis mode is not available, call \"c1\" instead\n");
                        exit(255);
                    } else if (strcmp(mode, "c1") != 0) {
                        printf("\nUsage : -m c1\n");
                        exit(255);
                    }
                    break;
                case 'i':
                    input_file = malloc((strlen(optarg) + 1) * sizeof(char));
                    strcpy(input_file, optarg);
                    assert( input_file != NULL );

                    FILE* fromFile = fopen(input_file, "r");
                    if (fromFile == NULL) {
                          printf("Error while opening the input file.\n");
                          exit(255);
                    }
                    fclose(fromFile);
                    break;
                case 'l':
                    break;
                case 'd':
                    printf("\nDictionnaire non disponible, pas de traitement de C2 et C3\n");
                    exit(255);
                    break;
                case 'k':
                    key_length = atoi(optarg);
                    break;
                case '?':
                    printf("\nUsage : %s [-h] [-i filename] [-k key_length] [-m c1|all] [-d dictionnary]\n", argv[0]);
                    exit(255);
            }
        }

    if(mode != NULL && strcmp(mode, "c1") == 0) {
        crack_c1(input_file, key_length);
    }

    free(input_file);
    free(mode);
    return 0;
}
