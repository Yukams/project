/// \file dh_crack.h
/// \author Valentin Tahon
/// \date Janvier 2021
/// \brief Header de crack_c1.c et de dh_crack.c

/// \brief Affiche à l'écran l'ensemble des chiffres de la clef qui correspondent à un dechiffrage ASCII
/// Cette fonction n'affiche pas les combinaisons de clefs en tant que tel, ni les clefs les plus probables
/// \param[in] file_name : nom du fichier source
/// \param[in] key_length: longueur de la clef
void crack_c1(char* file_name, int key_length);
