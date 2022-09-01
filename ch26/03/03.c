#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE (1000)

int compare_int(const void *a, const void *b)
{
    int *x = a;
    int *y = b;
    if (*x < *y)
    {
        return -1;
    }
    else if (*x == *y)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main(void)
{
    int arr[ARR_SIZE];
    for (int i = 0; i < ARR_SIZE; ++i)
    {
        arr[i] = ARR_SIZE - i;
    }
    clock_t start_time = clock();
    qsort(arr, ARR_SIZE, sizeof(arr[0]), compare_int);
    printf("sort time: %g sec.\n", ((double)clock() - start_time) / CLOCKS_PER_SEC);

    return 0;
}