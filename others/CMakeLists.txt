cmake_minimum_required(VERSION 3.17)
project(Projet C)

set(CMAKE_C_STANDARD 11)

include_directories(Headers)

add_executable(Projet
        ../c-files/cbc-crypt.c
        ../c-files/cbc-uncrypt.c
        ../c-files/crack_c1.c
        ../c-files/dh_crack.c
        ../c-files/dh_crypt.c
        ../c-files/dh_genkey.c
        ../c-files/dh_prime.c
        ../c-files/xor.c
        ../Headers/cbc-crypt.h
        ../Headers/cbc-uncrypt.h
        ../Headers/crack_c1.h
        ../Headers/dh.h
        ../Headers/dh_crack.h
        ../Headers/dh_prime.h
        ../Headers/xor.h)
