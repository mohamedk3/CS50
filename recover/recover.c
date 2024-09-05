#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t  BYTE ;



int main(int argc, char *argv[])
{
    // open memory card

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Usage: ./recover IMAGE");
        return 1 ;
    }
    int BLOCK_SIZE = 512 ;
    BYTE buffer[BLOCK_SIZE];
    bool is_first = false ;
    bool found = false ;
    int  file_number = 0 ;
    char current_file[8];
    FILE *image;

    //repate until end of card
    while (true)
    {
        int max = fread(&buffer, sizeof(BYTE), BLOCK_SIZE, file);
        if (max != BLOCK_SIZE)
        {
            break;
        }


        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            //if first JPEG
            if (!is_first)
            {
                is_first = true ;
                sprintf(current_file, "%03i.jpg", file_number);
                image = fopen(current_file, "w");
                fwrite(&buffer, sizeof(BYTE), 512, image);
            }
            else
            {
                fclose(image);
                sprintf(current_file, "%03i.jpg", file_number);
                image = fopen(current_file, "w");
                fwrite(&buffer, sizeof(BYTE), 512, image);
            }
            file_number++;
            found = true;
        }

        else if (found)
        {
            fwrite(&buffer, sizeof(BYTE), 512, image);
        }
    }
}

