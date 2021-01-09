/// \file cbc-crypt.h
/// \author Valentin Tahon
/// \date Janvier 2021
/// \brief Header de cbc-crypt.c et de dh_crypt.c


/// \brief Effectue un cryptage d'un fichier grâce à la méthode de cryptage CBC
/// \param[in] file_name : nom du fichier source
/// \param[in] file_to_write : nom du fichier de destination
/// \param[in] vector : le vecteur d'initialisation
/// \param[in] key : clef de chiffrement
void cbc_crypt(char* file_name, char* file_to_write, char* vector, char* key);
