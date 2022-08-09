#include <stdlib.h>
#include <stdbool.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

Node *top = NULL;

bool is_empty(void)
{
    return top == NULL;
}

void make_empty(void)
{
    Node *next_node;
    while (top != NULL)
    {
        next_node = top->next;
        free(top);
        top = next_node;
    }
}

bool push(int item)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL)
    {
        return false;
    }

    new_node->data = item;

    if (top == NULL)
    {
        top = new_node;
        top->next = NULL;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }

    return true;
}

int pop(void)
{
    if (is_empty())
    {
        return NULL;
    }

    Node *temp = top;
    int item = temp->data;
    top = top->next;
    free(temp);
    return item;
}


