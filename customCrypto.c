#include <stdio.h>
#include <string.h>
#include "cryptoFunctions.c"

int main(int argc, char const *argv[])
{
    printf("You have entered %d arguments\n", argc);

    switch (argc)
    {
    case 2:
        printf("You have selected no flag\n");
        printf("By default encrypt flag will run\n");
        encrypt(argv[2]);
        break;

    case 3:
        if (strcmp(argv[1], "-encrypt") == 0)
        {
            printf("You have selected to encrypt file...\n");
            encrypt(argv[2]);
        }
        else if (strcmp(argv[1], "-decrypt") == 0)
        {
            printf("You have selected to decrypt file...\n");
            decrypt(argv[2]);
        }
        else
        {
            printf("You have selected wrong flag:\n");
            printf("Use -encrypt: For encypting the file\n");
            printf("Use -decrypt: For decrypting the file\n");
        }
        break;

    default:
        printf("Please enter valid flags and arguments\n");
        printf("Syntax: customCrypto [-flags] filename\n");
        break;
    }

    /*
    // Printing CLI args
    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
    */

    return 0;
}