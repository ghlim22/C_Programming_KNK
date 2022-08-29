#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int ch;
    while ((ch = getc(stdin)) != EOF)
    {
        while (isspace(ch))
        {
            ch = getc(stdin);
        }

        while (ch != '\n' && ch != EOF)
        {
            putc(ch, stdout);
            ch = getc(stdin);
        }
    }
    return 0;
}