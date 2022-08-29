#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <assert.h>
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
    assert(new_stack != NULL);
    new_stack->contents = malloc(size * sizeof(Item));
    assert(new_stack->contents != NULL);

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
        assert(s->contents != NULL);

        s->size = new_size;
    }
    else
    {
        s->contents[s->top++] = i;
    }
}

Item pop(Stack s)
{
    assert(!is_empty(s));

    return s->contents[--s->top];
}

Item peek(Stack s)
{
    assert(!is_empty(s));

    return s->contents[s->top];
}