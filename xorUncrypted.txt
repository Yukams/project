#include <stdio.h>
#include <stdlib.h>

// Encrypt the message contained in <file_name> with the <key> and writes it in <file_to_write>
void xor(char* file_name, char* file_to_write, char* key) {
    FILE* fromFile = fopen(file_name, "r");
    FILE* toFile = fopen(file_to_write, "w");
    if (fromFile == NULL || toFile == NULL) {
          printf("Error while opening the file.\n");
          exit(1);
    }
    
    int k=0;
    char ch;
    while((ch = fgetc(fromFile)) != EOF) {
        fprintf(toFile, "%c", ch^key[k]);
        
        k++;
        if(key[k] == '\0') {
            k = 0;
        }
    }
    
    fclose(fromFile);
    fclose(toFile);
}

// Return file size
int getFileSize(FILE* file) {
    fseek(file, 0L, SEEK_END);
    int size = ftell(file);
    fseek(file, 0L, SEEK_SET);
    return size+1;
}


// Returns "true" if files are equals, "false" otherwise
// B = Before, A = After
int test_FilesAreEquals(char* filename_B, char* filename_A) {
    // Tests if files content is identical
    FILE* file_B = fopen(filename_B, "r");
    FILE* file_A = fopen(filename_A, "r");

    // Tests if files have the same size
    int size_B = getFileSize(file_B);
    if (getFileSize(file_A) != size_B) {
        fclose(file_B);
        fclose(file_A);
        return 0;
    }
    
    char ch1, ch2;
    while((ch1 = fgetc(file_B)) != EOF && (ch2 = fgetc(file_A))) {
        if (ch1 != ch2) {
            return 0;
            fclose(file_B);
            fclose(file_A);
        }
    }

    fclose(file_B);
    fclose(file_A);
    return 1;
}


int main() {
    xor("xor.c", "xorCrypted.txt", "gweek"); // Encrypts
    xor("xorCrypted.txt", "xorUncrypted.txt", "gweek"); // Uncrypts
    
    if (test_FilesAreEquals("xor.c", "xorUncrypted.txt")) {
        printf("Success : Files are equals\n");
    } else {
        printf("ERROR : Files are not equals\n");
        exit(3);
    }
    
    return 0;
}
