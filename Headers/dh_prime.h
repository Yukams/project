#define MAX_PRIME 4294967296/1000 // 2^32 = sqrt(2^64)
#define MIN_PRIME 100
#define BLUE "\x1B[34m"
#define WHITE "\x1B[37m"
#define MAG "\x1B[35m"
#define GRN "\x1B[32m"
#define RED "\x1B[31m"

long random_long(long min,long max);
int rabin (long a, long n) ;
long puissance_mod_n (long a, long e, long n);
void xor(char *msg, char* key,int msg_length,char *crypted);
long generePremierRabin(long min,long max,int *cpt);
long seek_generator(long start,long p);
int nb_digit_base10(long n);
long generate_shared_key(long min,long max);
long genPrimeSophieGermain(long min,long max,int *cpt);
long xchange_shared_key(long generateur, long premier);
long int_pow(long a, long e);
