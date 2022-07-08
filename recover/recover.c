#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    //check if only one argument.
    if(argc != 2){
    printf("Usage: ./recover IMAGE\n");
    return 1;
    }

    // open memory card
    FILE* infile = fopen(argv[1], "r");

    //check if file can be opened
    if(infile == NULL){
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    //define one byte
    typedef uint8_t BYTE;

    //initialize viriables
    BYTE buffer[512];
    int counter = 0;
    FILE* image_pointer = NULL;
    char image_name[8];

    while(fread(&buffer, sizeof(BYTE), 512, infile) == 512){

        //if start of an image
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0){

            //if not first image
            if(!(counter == 0)){
                fclose(image_pointer);
            }

            //open new file
            sprintf(image_name, "%03i.jpg", counter);
            image_pointer = fopen(image_name, "w");
            counter ++;
        }

        //write to current image file
        if(counter != 0){
            fwrite(&buffer, sizeof(BYTE), 512, image_pointer);
        }
    }
    fclose(image_pointer);
    fclose(infile);
}