#include "cs50.h"
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Improper usage!\n");
        return 1;
    }

    // Open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("No such file found!\n");
        return 1;
    }

    // An array with 4 bytes to store the first 4 bytes of the file
    uint8_t buffer[4];

    // An array with integers representing the PDF signature
    uint8_t signature[] = {37, 80, 68, 70};

    fread(buffer, 1, 4, file); // Read into buffer, 1 at a time, 4 bytes total, from file pointer
    for (int i = 0; i < 4; i++)
    {
        if (buffer[i] != signature[i])
        {
            printf("Not likely a PDF file!\n");
            // Close file
            fclose(file);
            return 0;
        }
        printf("%i ", buffer[i]);
    }
    printf("\nLikely a PDF file!\n");
    // Close file
    fclose(file);
    return 0;
}