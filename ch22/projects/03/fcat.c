#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        fprintf(stderr, "usage: fcat f1 f2 ...");
        return 1;
    }

    FILE *fp;
    for (int i = 1; i < argc; ++i)
    {
        if ((fp = fopen(argv[i], "r") == NULL))
        {
            fprintf(stderr, "Can't open %s.\n", argv[i]);
            return 2;
        }
        int ch;
        while ((ch = fgetc(fp)) != EOF)
        {
            if (putc(ch, stdout) == EOF)
            {
                fprintf(stderr, "output error!\n");
                fclose(fp);
                return 3;
            }
        }

        if (ferror(fp) || feof(fp))
        {
            fprintf(stderr, "input error!\n");
            fclose(fp);
            return 4;
        }

        fclose(fp);
    }

    return 0;
}