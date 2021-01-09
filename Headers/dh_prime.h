/// \file xor.h
/// \author Valentin Tahon
/// \date Janvier 2021
/// \brief Header de dh_prime.c et dh_genkey.c

#define MAX_PRIME 4294967296/1000 // 2^32 = sqrt(2^64)
#define MIN_PRIME 100
#define BLUE "\x1B[34m"
#define WHITE "\x1B[37m"
#define MAG "\x1B[35m"
#define GRN "\x1B[32m"
#define RED "\x1B[31m"

/// \brief génère un uint aléatoire entre min et max
/// \param[in] min
/// \param[in] max
/// \return n : min≤n≤max
long random_long(long min,long max);

/// \brief test de Rabin sur la pimarité d'un entier
/// \brief c'est un test statistique. Il est plus rapide que le précédent.
/// \param[in] a : on met 2, ça marche
/// \param[in] n : le nombre à tester
/// \returns 1 il est premier, 0 sinon
int rabin (long a, long n) ;

/// \brief puissance modulaire, calcule a^e mod n
/// a*a peut dépasser la capacité d'un long
/// https://www.labri.fr/perso/betrema/deug/poly/exp-rapide.html
/// vu au S1 en Python
/// \param[in] a : nombre de base
/// \param[in] e : puissance
/// \param[in] n : modulo
/// \return le nombre a à la puissance e modulo n
long puissance_mod_n (long a, long e, long n);

/// \brief recherche d'un générateur du groupe (corps) cyclique Z/pZ avec p premier
/// \param[in] start
/// \param[in] p (nombre premier)
/// \return le générateur
long seek_generator(long start,long p);

/// \brief calcule un nombre premier p de Sophie Germain et un générateur du groupe p/Zp.
/// appelle le simulateur d'échange de clef partagée.
/// \param[in] min
/// \param[in] max
/// \returns la clef partagée
long generate_shared_key(long min,long max);

/// \brief fournit un nombre premier de Sophie Germain vérifié avec le test de rabin
/// \param[in] min et max
/// \param[out] cpt : le nombre d'essais pour trouver le nombre
/// \returns un nombre premier p min≤p≤max && p = 2*q+1 avec q premier
long genPrimeSophieGermain(long min,long max,int *cpt);

/// \brief similateur d'échange de clefs de Diffie-Hellman par réseau
/// \param[in] premier : un nombre premier
/// \param[in] generateur : un générateur du groupe Z/premierZ
/// \returns la clef commune générée
long xchange_shared_key(long generateur, long premier);
