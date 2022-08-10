#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct queue_type *Queue;
typedef int Item;

// Create the new queue.
Queue create(void);
// Inserting an item at the end of the Queue.
bool enque(Queue que, Item i);
// Removing an item from the beginning of the queue.
bool deque(Queue que);
// Returning the first item in the queue.
Item get_first(Queue que);
// Returning the last item in the queue.
Item get_last(Queue que);
// Testing whether queue is empty.
bool is_empty(Queue que);

#endif