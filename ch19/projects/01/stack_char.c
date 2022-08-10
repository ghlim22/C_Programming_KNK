#include <stdbool.h>
#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    Stack s = create();

    printf("Enter parentheses and/or braces: ");
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (ch == '(' || ch == '{')
        {
            push(s, ch);
        }
        else if (ch == ')' || ch == '}')
        {
            pop(s);
        }
    }

    if (is_empty(s))
    {
        printf("Parentheses/braces are nested properly.\n");
    }

    return 0;
}