#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CNT (1000)

int main(void)
{
    srand((unsigned int)time(NULL));

    for (int i = 0; i < CNT; ++i)
    {
        if (rand() % 2 == 0)
        {
            putchar('0');
        }
        else
        {
            putchar('1');
        }

        if (i > 0 && i % 20 == 0)
        {
            putchar('\n');
        }
    }

    // b rand() % r + rand() % r;

    return 0;
}