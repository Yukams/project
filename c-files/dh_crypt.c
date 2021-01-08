#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <string.h>
#include <assert.h>
#include "../Headers/cbc-crypt.h"
#include "../Headers/cbc-uncrypt.h"
#include "../Headers/xor.h"

int main(int argc, char *argv[]) {
    int opt;
    
    int i=0;
    while (i < argc) {
        if(strcmp(argv[i], "-h") == 0) {
            printf("\nUsage : %s [-h] [-i filename] [-o filename] [-k key] [-m [xor] [cbc-crypt|cbc-uncrypt vector]]\n\nOptions :\n[-h]\t\t: Prints help about the command\n[-i filename]\t: File to read the message we want to cypher\n[-o filename]\t: File to write what we cyphered\n[-k key]\t: Key used to cypher\n\n[-m [xor] [cbc-crypt|cbc-uncrypt vector]]\n\t\t: Name of the method used to cypher and eventually, its vector\n", argv[0]);
            exit(255);
        }
        i++;
    }
    
    char* output_file = NULL;
    char* input_file = NULL;
    char* key = NULL;
    char* mode = NULL;
    char* init_vector = NULL;
    while((opt = getopt(argc, argv, "i:o:k:m:")) != -1)
        {
            switch(opt)
            {
                case 'o':
                    output_file = malloc((strlen(optarg) + 1) * sizeof(char));
                    strcpy(output_file, optarg);
                    assert( output_file != NULL );
                    
                    FILE* toFile = fopen(output_file, "w");
                    if (toFile == NULL) {
                          printf("Error while opening the output file.\n");
                          exit(255);
                    }
                    fclose(toFile);
                    break;
                case 'i':
                    input_file = malloc((strlen(optarg) + 1) * sizeof(char));
                    strcpy(input_file, optarg);
                    assert( input_file != NULL );
                    
                    printf("\n%s\n", input_file);
                    FILE* fromFile = fopen(input_file, "r");
                    if (fromFile == NULL) {
                          printf("Error while opening the input file.\n");
                          exit(255);
                    }
                    fclose(fromFile);
                    break;
                case 'k':
                    key = malloc((strlen(optarg) + 1) * sizeof(char));
                    strcpy(key, optarg);
                    assert( key != NULL );
                    break;
                case 'm':
                    mode = malloc((strlen(optarg) + 1) * sizeof(char));
                    strcpy(mode, optarg);
                    assert( mode != NULL );
                    if(strcmp(mode, "cbc-uncrypt") == 0 || strcmp(mode, "cbc-crypt") == 0) {
                        if(argv[optind] == NULL || argv[optind][0] == '-') {
                            printf("\n-m [cbc-uncrypt|cbc-crypt] needs a second argument <init_vector>\n");
                            exit(255);
                        }
                        init_vector = malloc((strlen(argv[optind]) + 1) * sizeof(char));
                        strcpy(init_vector, argv[optind]);
                        assert( init_vector != NULL );
                    }
                    else if (strcmp(mode, "xor") != 0) {
                        printf("\n-m only accepts three modes [cbc-uncrypt|cbc-crypt|xor]\n");
                        exit(255);
                    }
                    break;
                case '?':
                    printf("\nUsage : %s [-h] [-i filename] [-o filename] [-k key] [-m xor|cbc-crypt|cbc-uncrypt vector]\n", argv[0]);
                    exit(255);
            }
        }
    
    if(mode != NULL) {
        if(strcmp(mode, "cbc-uncrypt") == 0) {
            cbc_uncrypt(input_file, output_file, init_vector , key);
        }
        else if (strcmp(mode, "cbc-crypt") == 0) {
            cbc_crypt(input_file, output_file, init_vector , key);
        }
        else if (strcmp(mode, "xor") == 0){
            xor(input_file, output_file, key);
            if (test_FilesAreNotEquals(input_file, output_file)) {
                printf("\nSuccess : Files are not equals\n");
            } else {
                printf("\nERROR : Files are equals\n");
                exit(1);
            }
        }
        else {
            printf("\nNo mode selected... end of execution\n");
            exit(255);
        }
    }
    
    free(output_file);
    free(input_file);
    free(key);
    free(init_vector);
    free(mode);
    
    return 0;
}
