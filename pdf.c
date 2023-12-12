#include "cs50.h"
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Improper usage\n");
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

    // Read 4 bytes from file
    uint8_t buffer[4];
    fread(buffer, 1, 4, file); // Read into buffer, 1 at a time, 4 bytes total, from file pointer
    for (int i = 0; i < 4; i++)
    {
        printf("%i ", buffer[i]);
    }
}