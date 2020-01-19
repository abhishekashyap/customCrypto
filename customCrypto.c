#include <stdio.h>
#include <string.h>

int encrypt() { return 0; }

int decrypt() { return 0; }

void openFile(char *filename) 
{
    FILE *fp;
    fp = fopen(filename, "r+");

    if (fp == NULL)
    {
        printf("File does not exist / unable to open file");
    }
    else
    {
        printf("File exists");
    }
    
    fclose(fp);

}


int main(int argc, char const *argv[])
{
    printf("You have entered %d arguments\n", argc);

    switch (argc)
    {
    case 2:
        printf("You have selected no flag\n");
        printf("By default encrypt flag will run\n");
        openFile(argv[2]);
        encrypt();
        break;

    case 3:
        if (strcmp(argv[1], "-encrypt") == 0)
        {
            printf("You have selected to encrypt file...\n");
            openFile(argv[2]);
            encrypt();
        }
        else if (strcmp(argv[1], "-decrypt") == 0)
        {
            printf("You have selected to decrypt file...\n");
            openFile(argv[2]);
            decrypt();
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