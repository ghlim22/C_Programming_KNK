#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

#define STACK_SIZE (100)

struct node
{
    Item data;
    struct node *next;
};

struct stack_type
{
    struct node *top;
    int len;
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
    new_stack->top = NULL;
    new_stack->len = 0;

    return new_stack;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while (!is_empty(s))
    {
        pop(s);
    }
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        terminate("Error in push: stack is full.");
    }

    new_node->data = i;
    new_node->next = s->top;
    s->top = new_node;
    s->len++;
}

Item pop(Stack s)
{
    struct node *old_top;
    Item i;

    if (is_empty(s))
    {
        terminate("Error in pop: stack is empty.");
    }

    old_top = s->top;
    s->top = old_top->next;
    i = old_top->data;
    free(old_top);
    s->len--;

    return i;
}

Item peek(Stack s)
{
    if (is_empty(s))
    {
        terminate("Error in pop: stack is empty.");
    }

    return s->top->data;
}

int length(Stack s)
{
    if (is_empty(s))
    {
        printf("stack length: %d\n", 0);
        return 0;
    }
    printf("stack length: %d\n", s->len);
    return s->len;
}