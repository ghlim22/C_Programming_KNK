#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: convert file_name\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "file open error.\n");
        return 2;
    }

    int ch;
    while ((ch = getc(fp)) != EOF)
    {
        if ('a' <= ch && ch <= 'z')
        {
            ch -= 32;
        }

        if (putc(ch, stdout) == EOF)
        {
            fprintf(stderr, "writing error.\n");
            break;
        }
    }

    fclose(fp);

    return 0;
}