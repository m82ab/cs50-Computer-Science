//recover
#include <stdio.h>
#include <stdlib.h>


int main(int x, char *argv[])
{
    // ensure proper usage
    if (x != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];


    // open input file
    FILE *k = fopen(infile, "r");
    if (k == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    unsigned char buffer[512];
    int y = 0;
    char filename[8];

    FILE *outptr = NULL;

    while (fread(&buffer, sizeof(buffer), 1, k))
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (outptr != NULL)
            {
                fclose(outptr);
            }

            sprintf(filename, "%03i.jpg", y++);
            printf("%s\n", filename);
            outptr = fopen(filename, "w");
            fwrite(&buffer, sizeof(buffer), 1, outptr);

        }

        else if (outptr != NULL)
        {
            fwrite(&buffer, sizeof(buffer), 1, outptr);
        }
    }

    fclose(k);
    fclose(outptr);
    return 0;
}