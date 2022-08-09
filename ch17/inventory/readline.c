#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "readline.h"

int read_line(char *str, int len)
{
    int ch, cur = 0;
    while (isspace(ch = getchar()))
    {
        ;
    }

    while (ch != '\n' && ch != EOF)
    {
        if (cur < len)
        {
            str[cur++] = ch;
        }
        ch = getchar();
    }
    str[cur] = '\0';
    return cur;
}