#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <assert.h>
#include "../Headers/dh_prime.h"

/// \file dh_genkey.c
/// \author Valentin Tahon
/// \date Janvier 2021
/// \brief Lance un scénario de génération de clef de chiffrement commune entre Alice et Bob
///et montre qui connait quoi, quand et où se produisent les échanges (local, réseau).

long generate_shared_key_dh(long min,long max, char* file_name){
    /// \brief calcule un nombre premier p de Sophie Germain et un générateur du groupe p/Zp.
    /// appelle le simulateur d'échange de clef partagée.
    /// Ecris les informations liées au générateur et au nombre premier dans le fichier <file_name>
    /// \returns la clef partagée
    FILE* toFile = fopen(file_name, "w");
    if (toFile == NULL) {
          perror("Error while opening the file.\n");
          exit(255);
    }
    
    int cpt;
    fprintf(toFile, "\nGénération de la clef partagée\n");
    long premier = genPrimeSophieGermain(min,max,&cpt);
    fprintf(toFile, "Premier (Sophie Germain) = %ld\n",premier);
    long generateur = seek_generator(3,premier); // exemple 100
    long ordre = puissance_mod_n (generateur, premier-1, premier); // generateur^{premier -1} (mod premier)
    fprintf(toFile, "Générateur = %ld ordre = %ld\n",generateur,ordre);
    assert (generateur != -1);
    fclose(toFile);
    return xchange_shared_key(generateur, premier);
}

int main(int argc, char *argv[]) {
    /// \brief programme principal, traite les arguments fournis lors de l'appel du programme
    /// Accepte les options -o (fichier en sortie), -h (affiche l'aide)
    int opt;
    
    int i=0;
    while (i < argc) {
        if(strcmp(argv[i], "-h") == 0) {
            printf("Usage : dh_genkey [-h] [-o file_name]\nDescription : Prints a key transfer conversation between Alice and Bob\nOption -h : prints help, doesn't launch the process\nOption -o : doesn't print the conversation but records it in <file-name>\n");
            exit(255);
        }
        i++;
    }
    
    while((opt = getopt(argc, argv, "o:")) != -1)
       {
           switch(opt)
           {
               case 'o':
                   generate_shared_key_dh(0, random_long(MIN_PRIME, MAX_PRIME), optarg);
                   return 0;
               case '?':
                   printf("Wrong option.\nUsage : dh_genkey [-h] [-o file_name]\n");
                   exit(255);
           }
       }
    
    long key = generate_shared_key(0, random_long(MIN_PRIME, MAX_PRIME));
    printf("\n%sLa clé%s commune trouvée %sest : %ld%s\n", RED, WHITE, RED, key, WHITE);
    return 0;
}
