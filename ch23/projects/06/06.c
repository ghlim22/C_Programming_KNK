#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    int ch;
    while ((ch = getc(stdin)) != EOF)
    {
        if (iscntrl(ch) && (ch != '\n'))
        {
            ch = '?';
        }
        putc(ch, stdout);
    }
    return 0;
}