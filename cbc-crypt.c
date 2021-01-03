#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void cbc_uncrypt(char* file_name, char* file_to_write, char* vector, char* key) {
    FILE* fromFile = fopen(file_name, "r");
    FILE* toFile = fopen(file_to_write, "w");
    if (fromFile == NULL || toFile == NULL) {
          printf("Error while opening the file.\n");
          exit(2);
    }
    
    int k=0;
    int block=0;
    char ch;
    char v[16];
    for(int i=0; i<16; i++) {
        v[i]=vector[i];
    }
    
    while((ch = fgetc(fromFile)) != EOF || block != 0) {
        if(ch == EOF) {
            ch = ' ';
        }
        char output = (ch^key[k])^v[block];
        fprintf(toFile, "%c", output);
        v[block] = ch;
        
        block++;
        k++;
        if(block >= 16) {
            k = 0;
            block = 0;
        } else if (key[k] == '\0') {
            k = 0;
        }
    }
    
    fclose(fromFile);
    fclose(toFile);
}

void cbc_crypt(char* file_name, char* file_to_write, char* vector, char* key) {
    FILE* fromFile = fopen(file_name, "r");
    FILE* toFile = fopen(file_to_write, "w");
    if (fromFile == NULL || toFile == NULL) {
          printf("Error while opening the file.\n");
          exit(1);
    }
    
    int k=0;
    int block=0;
    char ch;
    char v[16];
    for(int i=0; i<16; i++) {
        v[i]=vector[i];
    }
    
    while((ch = fgetc(fromFile)) != EOF || block != 0) {
        if(ch == EOF) {
            ch = ' ';
        }
        char output = (v[block]^ch)^key[k];
        fprintf(toFile, "%c", output);
        v[block] = output;
        
        block++;
        k++;
        if(block >= 16) {
            k = 0;
            block = 0;
        } else if (key[k] == '\0') {
            k = 0;
        }
    }
    
    fclose(fromFile);
    fclose(toFile);
}

int main(int argc, char *argv[]) {
    if( argc == 5 ) {
        if(strlen(argv[5]) != 16) {
            printf("WARNING : Initial vector MUST be 16 char long. Exiting the program");
            exit(5);
        }
        char vector[strlen(argv[5])+1];
        strcpy(vector, argv[5]);
        char key[strlen(argv[2])+1];
        strcpy(key, argv[2]);
        char origin_file[strlen(argv[3])+1];
        strcpy(origin_file, argv[3]);
        char output_file[strlen(argv[4])+1];
        strcpy(output_file, argv[4]);
        
        cbc_crypt(origin_file, output_file, vector , key); // Encrypts
    }
    else if( argc > 5 ) {
        printf("Too many arguments supplied. Expected four. [key, filename_origin, filename_to_write, init_vector]\n");
        exit(3);
    }
    else {
        printf("Four arguments expected. [key, filename_origin, filename_to_write, init_vector]\n");
        exit(4);
    }
    
    return 0;
}
