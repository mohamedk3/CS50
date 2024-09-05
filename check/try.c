#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE ;

int main(int argc, char *argv[])
{
    // Check command-line arguments to Open memory card

    FILE* file = fopen(argv[1],"r");
    if (file == NULL){
        printf("the file can't open");
        return 1 ;
    }
    // set conter for JPEG
    int count = 0 ;
    // look for beginnig of a JPEG
    BYTE buffer[512];
    char jpeg[8];

      while(fread(&buffer,sizeof(BYTE),512,file) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (count == 0)
            {
                sprintf(jpeg,"%03i.jpg",count);
                FILE* image = fopen(jpeg,"w");
                fwrite(&buffer,sizeof(BYTE),512,image);
                count++;
                fclose(image);
            }
               else   {

                    sprintf(jpeg,"%03i.jpg",count);
                    FILE* image = fopen(jpeg,"w");
                    fwrite(&buffer,sizeof(BYTE),512,image);
                    count++;
            }
            }
        else  if (buffer[0] != 0xff && count > 0) {
            sprintf(jpeg,"%03i.jpg",count);
            FILE* image = fopen(jpeg,"w");
            fwrite(&buffer,sizeof(BYTE),512,image);
        }

    }
    fclose(file);

    //Open a new JPEG file
    //write 512 bytes until an new JPEG is found and keep repate it
    //stop at end of file
}