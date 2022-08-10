#include "stdio.h"
#include "stdlib.h"
#include "queue_list.h"

#define MAX_SIZE (100)
#define PUBLIC
#define PRIVATE static

struct node
{
    Item data;
    struct node *next;
};

struct queue_type
{
    struct node *first;
    struct node *last;
};

PRIVATE void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

// Create the new queue.
Queue create(void)
{
    Queue new_queue = malloc(sizeof(struct queue_type));
    if (new_queue == NULL)
    {
        terminate("Error in create: que could not be created.");
    }
    new_queue->first = NULL;
    new_queue->last = NULL;

    return new_queue;
}
// Inserting an item at the end of the Queue.
bool enque(Queue que, Item i)
{
    if (que == NULL)
    {
        return false;
    }

    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        return false;
    }

    new_node->data = i;
    if (is_empty(que))
    {
        que->first = new_node;
    }
    que->last->next = new_node;
    que->last = new_node;

    return true;
}
// Removing an item from the beginning of the queue.
bool deque(Queue que)
{
    if (is_empty(que))
    {
        return false;
    }

    struct node *temp = que->first;
    que->first = temp->next;
    free(temp);
}
// Returning the first item in the queue.
Item get_first(Queue que)
{
    if (is_empty(que))
    {
        terminate("Error: que is empty.");
    }

    return que->first->data;
}
// Returning the last item in the queue.
Item get_last(Queue que)
{
    if (is_empty(que))
    {
        terminate("Error: que is empty.");
    }

    return que->last->data;
}
// Testing whether queue is empty.
bool is_empty(Queue que)
{
    return que->first == NULL || que->last == NULL;
}