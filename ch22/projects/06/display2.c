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

    int i, n, offset;
    unsigned char buffer[10];

    for (offset = 0;; offset += 10)
    {

        n = fread(buffer, 1, 10, input);
        if (n == 0)
        {
            break;
        }
        // print offset.
        fprintf(stdout, "%6d  ", offset);

        // print bytes.
        for (i = 0; i < n; ++i)
        {
            fprintf(stdout, "%.2X ", buffer[i]);
        }
        for (; i < 10; ++i)
        {
            fprintf(stdout, "   ");
        }
        fprintf(stdout, " ");

        // print characters.
        for (i = 0; i < n; ++i)
        {
            if (isprint(buffer[i]))
            {
                fprintf(stdout, "%c ", buffer[i]);
            }
            else
            {
                fprintf(stdout, ". ");
            }
        }
        fprintf(stdout, "\n");
    }

    fclose(input);

    return 0;
}