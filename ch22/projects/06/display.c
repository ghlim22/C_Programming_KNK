#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        //
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        return 1;
    }

    fprintf(stdout, "Offset                Bytes                Chracters\n");
    fprintf(stdout, "------- ------------------------------    ------------\n");

    int ch;
    long offset = 0L;
    while (1)
    {
        // print offset.
        offset = ftell(input);
        fprintf(stdout, "%6ld  ", offset);

        // print bytes.
        int i;
        for (i = 0; i < 10; ++i)
        {
            ch = fgetc(input);
            if (ch == EOF)
            {
                break;
            }
            fprintf(stdout, "%.2X ", (unsigned char)ch);
        }
        for (int n = 0; n < 10 - i; ++n)
        {
            fprintf(stdout, "   ");
        }
        fprintf(stdout, "  ");

        // print characters.
        fseek(input, (long)(-i), SEEK_CUR);
        for (int i = 0; i < 10; ++i)
        {
            ch = fgetc(input);
            if (ch == EOF)
            {
                return 0;
            }
            if (isprint(ch))
            {
                fprintf(stdout, "%c ", (unsigned char)ch);
            }
            else
            {
                fprintf(stdout, ". ");
            }
        }
        fprintf(stdout, "\n");
    }

    return 0;
}