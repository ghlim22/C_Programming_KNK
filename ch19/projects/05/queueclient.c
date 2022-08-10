#include <stdio.h>
#include "queueADT.h"

int main(void)
{
    Queue q1 = create(10);
    Queue q2 = create(10);

    for (int i = 0; i < 15; i++)
    {
        enque(q1, i);
        enque(q2, i);
    }

    for (int i = 0; i < 3; i++)
    {
        deque(q1);
        enque(q2, i);
    }

    printf("%d", get_first(q1));
    printf("%d", get_last(q1));

    return 0;
}