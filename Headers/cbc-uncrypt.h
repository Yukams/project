/// \file cbc-uncrypt.h
/// \author Valentin Tahon
/// \date Janvier 2021
/// \brief Header de cbc-uncrypt.c et de dh_crypt.c

/// \brief Effectue un décryptage d'un fichier grâce à la méthode de décryptage CBC
/// \param[in] file_name : nom du fichier source
/// \param[in] file_to_write : nom du fichier de destination
/// \param[in] vector : le vecteur d'initialisation
/// \param[in] key : clef de chiffrement
void cbc_uncrypt(char* file_name, char* file_to_write, char* vector, char* key);
