/// \file xor.h
/// \author Valentin Tahon
/// \date Janvier 2021
/// \brief Header de xor.c et dh_crypt.c

/// \brief Effectue le cryptage xor en prenant chaque caractère du fichier d'entrée et en effectuant un cryptage XOR avec un caracètre de la clef fournie. Ecris ensuite le caractère crypté dans le fichier de sortie
/// \param[in] file_name : nom du fichier source
/// \param[in] file_to_write : nom du fichier de destination
/// \param[in] key : clef de chiffrement
void xor(char* file_name, char* file_to_write, char* key);

/// \brief Vérifie que le fichier en entrée soit différents de celui en sortie, en conservant le même nombre de caractères
/// \param[in] filename_B : le fichier modifié
/// \param[in] filename_A : le fichier d'origine
int test_FilesAreNotEquals(char* filename_B, char* filename_A);
