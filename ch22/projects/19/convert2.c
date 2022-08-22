#include <stdio.h>
#include <stdlib.h>

// converts unit text file to windows text file.

int main(int argc, char *argv[])
{
    FILE *fp_in, *fp_out;
    int ch;

    if (argc != 3)
    {
        return 1;
    }

    if ((fp_in = fopen(argv[1], "rb")) == NULL)
    {
        return 1;
    }

    if ((fp_out = fopen(argv[2], "wb")) == NULL)
    {
        return 1;
    }

    while ((ch = getc(fp_in)) != EOF)
    {
        if (ch == '\x0a')
        {
            putc('\x0d', fp_out);
        }
        if (putc(ch, fp_out) == EOF)
        {
            // error occured.
        }
    }
    putc('\x1a', fp_out);

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}