#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE (100)

struct stack_type
{
    void *contents[STACK_SIZE];
    int top;
};

static void terminate(const char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

Stack create(void)
{
    Stack new_stack = malloc(sizeof(struct stack_type));
    if (new_stack == NULL)
    {
        terminate("Error in create: stack could not be created.");
    }

    new_stack->top = 0;
    return new_stack;
}

void destroy(Stack s)
{
    free(s);
}

void make_empty(Stack s)
{
    s->top = 0;
}

bool is_empty(Stack s)
{
    return s->top == 0;
}

bool is_full(Stack s)
{
    return s->top == STACK_SIZE;
}

void push(Stack s, void *i)
{
    if (is_full(s))
    {
        terminate("Error in push: stack is full.");
    }

    s->contents[s->top++] = i;
}

void *pop(Stack s)
{
    if (is_empty(s))
    {
        terminate("Error in pop: stack is empty.");
    }

    return s->contents[--s->top];
}
/*
Item peek(Stack s)
{
    if (is_empty(s))
    {
        terminate("Error in pop: stack is empty.");
    }

    return s->contents[s->top];
}
*/