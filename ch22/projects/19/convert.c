#include <stdio.h>
#include <stdlib.h>

// converts windows text file to unix text file.

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
        if (ch == '\x0d' || ch == '\x1a')
        {
            continue;
        }
        if (putc(ch, fp_out) == EOF)
        {
            // error occured.
        }
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}