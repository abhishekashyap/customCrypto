#include <stdio.h>
#include <string.h>

int encrypt() { return 0; }

int main(int argc, char const *argv[])
{
    printf("You have entered %d arguments\n", argc);

    switch (argc)
    {
    case 1:
        printf("You have selected no flag\n");
        printf("By default encrypt flag will run\n");
        encrypt();
        break;

    case 2:
        if (strcmp(argv[1], "-encrypt") == 0)
        {
            printf("You have selected to encrypt file...\n");
        }
        else if (strcmp(argv[1], "-decrypt") == 0)
        {
            printf("You have selected to decrypt file...\n");
        }
        else
        {
            printf("You have selected wrong flag:\n");
            printf("Use -encrypt: For encypting the file\n");
            printf("Use -decrypt: For decrypting the file\n");
        }
        break;

    default:
        printf("Please enter valid command\n");
        break;
    }

    for (int i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    return 0;
}