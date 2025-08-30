#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[512];
    FILE *img = NULL;
    char filename[8];
    int file_count = 0;


    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, card) == 512)
    {
        // Detect JPEG header
        if (buffer[0] == 0xff && 
            buffer[1] == 0xd8 && 
            buffer[2] == 0xff && 
            (buffer[3] & 0xf0) == 0xe0)
        { 
            // Close previous file if open
            if (img != NULL)
            {
                fclose(img);
            } 
            // Open a new JPEG file
            sprintf(filename, "%03i.jpg", file_count++);
                img = fopen(filename,"w");
            
        }   
        // If currently writing to JPEG, write to block
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(card);
}