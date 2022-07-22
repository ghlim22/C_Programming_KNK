#include <stdio.h>
#include "stack.h"

#define STACK_SIZE (100)

int g_contents[STACK_SIZE];
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

void push(int item)
{
    if (is_full)
    {
        stack_overflow();
    }
    else
    {
        g_contents[g_top++] = item;
    }
}

int pop(void)
{
    if (is_empty)
    {
        stack_underflow();
    }
    else
    {
        return g_contents[--g_top];
    }
}
