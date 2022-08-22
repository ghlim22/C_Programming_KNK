#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *source_file;
    FILE *dest_file;
    int ch;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    if ((source_file = fopen(argv[1], "rb")) == NULL)
    {
        fprintf(stderr, "%s can't be opened.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if ((dest_file = fopen(argv[2], "wb")) == NULL)
    {
        fprintf(stderr, "%s can't be opened.\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(source_file)) != EOF)
    {
        putc(ch, dest_file);
    }

    if (!feof(source_file))
    {
        fprintf(stderr, "file copy not finished.\n");
    }

    fclose(source_file);
    fclose(dest_file);

    return 0;
}