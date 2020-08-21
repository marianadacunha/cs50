#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#define BLOCKSIZE 512

int main(int argc, char *argv[])
{
    // Prints an error message if the user doesn't specify the name of the file
    if (argc != 2)
    {
        printf("Usage: ./recover [...image_name]\n");
        return 1;
    }
    // Prints an error message if the memory card was not successfully opened
    if (argv[1] == NULL)
    {
        printf("Could not open %s\n", argv[1]);
        return 1;
    }

    FILE *inputPointer = fopen(argv[1], "r");

    if (inputPointer == NULL)
    {
        printf("Unable to open file: %s\n", argv[1]);
        return 1;
    }
    
    // Name of the file will be 8 characters long: xxx.jpg + the \0
    char fileName[8];
    // Creating variables that we are going to use and then allocate memory for them
    FILE *outputPointer = NULL;
    uint8_t buffer[BLOCKSIZE];
    int counter = 0;

    while (fread(buffer, BLOCKSIZE, 1, inputPointer) || feof(inputPointer) == 0)
    {
        // Reads first 4 bytes of buffer to see if there's a JPG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Closes previous JPG file, if it exists
            if (counter > 0)
            {
                fclose(outputPointer);
            }
            // Creates and names a new file
            sprintf(fileName, "%03i.jpg", counter);
            outputPointer = fopen(fileName, "a");
            counter++;
        }
        if (outputPointer != NULL)
        {
            fwrite(buffer, BLOCKSIZE, 1, outputPointer);
        }
    }
    if (inputPointer != NULL)
    {
        fclose(inputPointer);
    }
    return 0;
}