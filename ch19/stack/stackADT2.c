#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "stackADT2.h"

#define STACK_SIZE (100)

struct stack_type
{
    Item *contents;
    int top;
    int size;
};

static void terminate(const char *msg)
{
    printf("%s\n", msg);
    exit(EXIT_FAILURE);
}

Stack create(int size)
{
    Stack new_stack = malloc(sizeof(struct stack_type));
    if (new_stack == NULL)
    {
        terminate("Error in create: stack could not be created.");
    }
    new_stack->contents = malloc(size * sizeof(Item));
    if (new_stack->contents == NULL)
    {
        free(new_stack);
        terminate("Error in create: stack could not be created.");
    }

    new_stack->top = 0;
    new_stack->size = size;
    return new_stack;
}

void destroy(Stack s)
{
    free(s->contents);
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
    return s->top == s->size;
}

void push(Stack s, Item i)
{
    if (is_full(s))
    {
        // terminate("Error in push: stack is full.");
        // doubled the size.
        int new_size = s->size * 2;
        s->contents = realloc(s->contents, sizeof(Item) * new_size);
        if (s->contents == NULL)
        {
            fprintf(stderr, "Error in realloc: stack size couldn't be doubled.\n");
            return;
        }

        s->size = new_size;
    }
    else
    {
        s->contents[s->top++] = i;
    }
}

Item pop(Stack s)
{
    if (is_empty(s))
    {
        terminate("Error in pop: stack is empty.");
    }

    return s->contents[--s->top];
}

Item peek(Stack s)
{
    if (is_empty(s))
    {
        terminate("Error in pop: stack is empty.");
    }

    return s->contents[s->top];
}