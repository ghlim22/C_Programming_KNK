#include <stdbool.h>
#include <stdio.h>

#define STACK_SIZE (100)

int g_contents[STACK_SIZE];
int *top_ptr = &g_contents[0];

void make_empty(void)
{
    top_ptr = &g_contents[0];
}

bool is_empty(void)
{
    return top_ptr = &g_contents[0];
}

bool is_full(void)
{
    return top_ptr = &g_contents[STACK_SIZE];
}

void push(int item)
{
    if (is_full)
    {
        stack_overflow();
    }
    else
    {
        // g_contents[g_top++] = item;
        *(top_ptr++) = item;
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
        // return g_contents[--g_top];
        return *(--top_ptr);
    }
}
