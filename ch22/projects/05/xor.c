#include <stdio.h>
#include <ctype.h>

#define KEY ('&')

int main(int argc, char *argv[])
{
    int orig_char, new_char;

    if (argc != 3)
    {
        fprintf(stderr, "usage: xor source dest");
        return 1;
    }

    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        //
    }

    FILE *output = fopen(argv[2], "wb");
    if (output = NULL)
    {
        //
    }

    while ((orig_char = fgetc(input)) != EOF)
    {
        new_char = KEY ^ orig_char;
        fputc(new_char, output);
    }

    fclose(input);
    fclose(output);

    return 0;
}