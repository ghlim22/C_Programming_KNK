#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int uncompress(FILE *source, FILE *dest);

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        //
    }

    int len = strlen(argv[1]) - 4;
    if (strcmp(argv[1] + len, ".rle"))
    {
        printf("Worng ext\n");
        return 1;
    }

    FILE *source = fopen(argv[1], "rb");
    if (source == NULL)
    {
        return 1;
    }

    char *new_file_name = malloc(100);
    strncpy(new_file_name, argv[1], len);

    FILE *dest = fopen(new_file_name, "wb");
    if (dest == NULL)
    {
    }

    while (uncompress(source, dest))
        ;

    fclose(source);
    fclose(dest);
    free(new_file_name);

    return 0;
}

int uncompress(FILE *source, FILE *dest)
{
    int ch, count, temp;

    count = getc(source);
    ch = getc(source);

    if (count == EOF || ch == EOF)
    {
        return 0;
    }

    for (int i = 0; i < count; ++i)
    {
        putc(ch, dest);
    }
    return 1;
}