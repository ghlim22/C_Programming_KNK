#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    FILE *input_fp;
    int ch, i;
    char area[3 + 1], local[3 + 1], exact[4 + 1];

    area[3] = '\0';
    local[3] = '\0';
    exact[4] = '\0';

    if (argc != 2)
    {
        return 1;
    }

    if ((input_fp = fopen(argv[1], "r")) == NULL)
    {
        return 1;
    }

    i = 0;
    while ((ch = fgetc(input_fp)) != EOF)
    {
        if (isdigit(ch))
        {
            if (i < 3)
            {
                area[i++] = ch;
            }
            else if (i < 6)
            {
                local[i++ - 3] = ch;
            }
            else
            {
                exact[i++ - 6] = ch;
                if (i == 10)
                {
                    i = 0;
                    printf("(%s) %s-%s\n", area, local, exact);
                }
            }
        }
    }

    return 0;
}