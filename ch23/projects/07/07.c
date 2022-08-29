#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int ch, d, cnt = 0;
    bool in_sentence = false;
    while ((ch = getc(stdin)) != EOF)
    {
        if (strchr("?!.", d) != NULL && isspace(ch))
        {
            cnt++;
        }
        d = ch;
    }

    printf("The number of sentences: %d\n", cnt);
    return 0;
}