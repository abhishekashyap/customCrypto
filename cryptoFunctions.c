#include "customCrypto.h"

int encrypt(const char *filename)
{
    printf("\nEntered encrypt function\n");

    FILE *fileToRead;
    FILE *fileToWrite;

    char filename2[] = "EncryptedFile.crp"; // Use strcat instead

    fileToRead = fopen(filename, "r");
    fileToWrite = fopen(filename2, "w");

    if (fileToRead == NULL || fileToWrite == NULL)
    {
        printf("File does not exist / unable to open file\n");
    }
    else
    {
        printf("File found\n");

        char dataToBeRead[50];
        // using fgets() method
        while (fgets(dataToBeRead, 50, fileToRead) != NULL)
        {
            // Print the dataToBeRead
            printf("%s", dataToBeRead);

            // Main logic
            for (int i = 0; i < 50; i++)
            {
                if (dataToBeRead[i] == 9)
                {
                    // Tab space - ASCII value = 9
                    // Replace with TT
                    // Write the dataToBeWritten into the file
                    char dataToBeWritten[] = "TT";

                    // writing in the file using fputs()
                    fputs(dataToBeWritten, fileToWrite);
                    fputs("\n", fileToWrite);
                }

                else if (dataToBeRead[i] == 13)
                {
                    // Cairrage return - ASCII value = 13
                    // Replace with <CR>
                    // Write the dataToBeWritten into the file
                    char dataToBeWritten[] = "<CR>";

                    // writing in the file using fputs()
                    fputs(dataToBeWritten, fileToWrite);
                    fputs("\n", fileToWrite);
                }

                else
                {
                    char outChar = dataToBeRead[i] - 16;

                    if (outChar < 32)
                    {
                        outChar = (outChar - 32) + 144;
                    }
                  
                    
                    

                    // char dataToBeWritten[] = (dataToBeRead[i] - 32) + 144;

                    // if (strlen(dataToBeWritten) > 0)
                    // {

                    //     // writing in the file using fputs()
                    //     fputs(dataToBeWritten, fileToWrite);
                    //     fputs("\n", fileToWrite);
                    // }
                }
            }
        }

        fclose(fileToRead);
    }

    return 0;
}

int decrypt(const char *filename)
{
    printf("\nEntered decrypt function\n");

    FILE *fileToRead;
    fileToRead = fopen(filename, "r+");

    if (fileToRead == NULL)
    {
        printf("File does not exist / unable to open file\n");
    }
    else
    {
        printf("File found\n");

        char dataToBeRead[50];
        // using fgets() method
        while (fgets(dataToBeRead, 50, fileToRead) != NULL)
        {
            // Print the dataToBeRead
            printf("%s", dataToBeRead);
        }

        fclose(fileToRead);
    }

    return 0;
}