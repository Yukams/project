
#ifndef CRACK_H
#define CRACK_H
 
#define  MAX_SIZE_KEY 8  /* 7 + '\0' caractères max dans la clef */
#define  MAX_VALID_KEY_CHARS 10 // dix chiffres
#define  MAX_KEYS 30000
 
typedef struct {
    int key_size;
    byte **tab_keys;
} t_tab_keys;
 
typedef struct {
    byte **words_tab;
    int dim;
} t_words_lst;
 
void create_tab_keys(t_tab_keys *tab_keys, int key_size);
 
void init_tab_keys(t_tab_keys *tab_keys);
 
void print_key_chars(t_tab_keys tab_keys);
 
void print_tab_keys(t_tab_keys tab_keys);
 
void remove_key_char(byte *tab, int char_index);
 
int crack_c1(char * file_name_in, t_tab_keys tab_keys, int key_size);
 
int crack_c2_by_key(char * file_name_in, t_tab_keys *tab_keys, int key_size, byte keys[MAX_KEYS][MAX_SIZE_KEY], int keys_sort_scores[]);
 
int crack_c2_by_char(char * file_name_in, t_tab_keys *tab_keys, int key_size, byte * best_key);
 
int generate_keys_from_char(t_tab_keys *tab_keys, int key_size, byte keys[][MAX_SIZE_KEY]);
 
void print_keys(byte keys[][MAX_SIZE_KEY], int size);
 
void crack_c3_dict(char *inFilename,char *dico_name,int nb_keys,byte keys[MAX_KEYS][MAX_SIZE_KEY],int keys_sort_scores[],int *best_index);
 
int dichoRecur(byte **tab,int deb, int fin, byte *valeur);
 
#endif
