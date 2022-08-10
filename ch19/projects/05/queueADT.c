#include "stdio.h"
#include "stdlib.h"
#include "queueADT.h"

#define MAX_SIZE (100)
#define PUBLIC
#define PRIVATE static

struct queue_type
{
    Item *contents;
    int pos_insert; // the position of the first empty slot in the array. the next of the last element
    int pos_remove; // the position of the next item to be removed. first element
    int cur_nums;   // the number of items in the queue.
    int size;
};

PRIVATE void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(int size)
{
    Queue new_que = malloc(sizeof(struct queue_type));
    if (new_que == NULL)
    {
        terminate("Error in create: stack could not be created.");
    }
    new_que->contents = malloc(size * sizeof(Item));
    if (new_que->contents == NULL)
    {
        terminate("Error in create: stack could not be created.");
    }
    new_que->pos_insert = 0;
    new_que->pos_remove = 0;
    new_que->cur_nums = 0;
    new_que->size = size;

    return new_que;
}

void enque(Queue que, Item i)
{
    // que->pos_remove = que->pos_insert;
    que->contents[que->pos_insert++] = i;
    que->pos_insert %= que->size;
    que->cur_nums++;
}

void deque(Queue que)
{
    if (is_empty(que))
    {
        terminate("Error in deque: que is empty.");
    }
    que->pos_remove++;
    que->pos_remove %= que->size;
    que->cur_nums--;
}

Item get_first(Queue que)
{
    if (is_empty(que))
    {
        terminate("Error in deque: que is empty.");
    }

    return que->contents[que->pos_remove];
}

Item get_last(Queue que)
{
    if (is_empty(que))
    {
        terminate("Error in deque: que is empty.");
    }

    return que->contents[(que->pos_remove + que->cur_nums - 1) % que->size];
}

bool is_empty(Queue que)
{
    return que->cur_nums == 0;
}

void destory(Queue que)
{
    que->cur_nums = 0;
    que->pos_insert = 0;
    que->pos_remove = 0;
}