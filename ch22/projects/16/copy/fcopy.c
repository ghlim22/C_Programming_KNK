#include <stdio.h>
#include <stdlib.h>

#define UNIT_SIZE (512)

int main(int argc, char *argv[])
{
    FILE *source_file;
    FILE *dest_file;
    int ch, n;
    void *buffer = malloc(UNIT_SIZE);

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

    while ((n = fread(buffer, sizeof(char), UNIT_SIZE, source_file)) > 0)
    {
        fwrite(buffer, sizeof(char), n, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);

    return 0;
}