#include <stdbool.h>
#include <stdio.h>

#define STACK_SIZE (100)

char g_contents[STACK_SIZE];
int g_top = 0;

void make_empty(void)
{
    g_top = 0;
}

bool is_empty(void)
{
    return g_top == 0;
}

bool is_full(void)
{
    return g_top == STACK_SIZE;
}

void push(char item)
{
    if (is_full())
    {
        // stack_overflow();
    }
    else
    {
        g_contents[g_top++] = item;
    }
}

int pop(void)
{
    if (is_empty())
    {
        // stack_underflow();
    }
    else
    {
        return g_contents[--g_top];
    }
}

int main(void)
{
    printf("Enter parentheses and/or braces: ");
    char ch;

    while ((ch = getchar()) != '\n')
    {
        if (ch == '(' || ch == '{')
        {
            push(ch);
        }
        else if (ch == ')' || ch == '}')
        {
            pop();
        }
    }

    if (is_empty())
    {
        printf("Parentheses/braces are nested properly.\n");
    }

    return 0;
}