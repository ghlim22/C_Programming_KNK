#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

int main(void)
{
    int ch;
    bool in_word = false;
    while ((ch = getc(stdin)) != EOF)
    {
        if (!in_word && isalpha(ch))
        {
            in_word = true;
            ch = toupper(ch);
        }
        if (isspace(ch))
        {
            in_word = false;
        }
        putc(ch, stdout);
    }

    return 0;
}