#include "readline.h"
#include <stdio.h>
int read_line(char str[], int n)
{
    int ch, i = 0;

    while (is_space(getchar()))
        ;

    while (i < n && (ch = getchar()) != '\n' && !is_space(ch))
    {
        str[i++] = ch;
    }

    if (ch == '\n' && i < n - 1)
    {
        str[i++] = '\n';
    }

    str[i] = '\0';
    return i;
}

int read_line_new(char str[], int n)
{
    int ch, i = 0;

    while (is_space(getchar()))
        ;

    do
    {
        if (ch == '\n')
        {
            break;
        }

        if (i < n)
        {
            str[i++] = ch;
        }
        else
        {
            break;
        }
    } while ((ch = getchar()) != '\n' && ch != EOF);

    str[i] = '\n';
    str[i + 1] = '\0';
    return i;
}

int is_space(char ch)
{
    if (ch == ' ' || ch == '\n' || ch == '\t' || ch == '\v' || ch == '\f' || ch == '\r')
    {
        return 1;
    }

    return 0;
}
