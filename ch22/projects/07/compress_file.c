#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int compress(FILE *stream, FILE *new_stream);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        // usage...
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL)
    {
        //
    }
    FILE *dest = fopen(strcat(argv[1], ".rle"), "wb");
    if (dest == NULL)
    {
        //
    }

    while (compress(source, dest))
        ;

    return 0;
}

int compress(FILE *stream, FILE *new_stream)
{
    int ch, temp, cons = 0;

    ch = getc(stream);
    if (ch == EOF)
    {
        return 0;
    }
    cons++;

    while ((temp = getc(stream)) == ch)
    {
        cons++;
    }

    if (temp != EOF)
    {
        fseek(stream, -1L, SEEK_CUR); // move pos back 1 byte.
    }
    fputc(cons, new_stream);
    fputc(ch, new_stream);

    if (temp == EOF)
    {
        return 0;
    }

    return 1;
}