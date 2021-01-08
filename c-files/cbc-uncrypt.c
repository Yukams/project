#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../Headers/cbc-uncrypt.h"

void cbc_uncrypt(char* file_name, char* file_to_write, char* vector, char* key) {
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
