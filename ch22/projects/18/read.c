#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NUM (10000)

int compare_num(const void *a, const void *b);

int arr[MAX_NUM];

int main(int argc, char *argv[])
{
    FILE *fp;
    int num = 0;
    if (argc != 2)
    {
        return 1;
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        return 1;
    }

    while (fscanf(fp, "%d", &arr[num++]) == 1)
    {
        ;
    }

    qsort(arr, sizeof(int), num, compare_num);

    int max_num = arr[num - 1];
    int min_num = arr[0];

    int median;
    if (num % 2 == 0)
    {
        median = (arr[num / 2] + arr[num / 2 - 1]) / 2;
    }

    printf("max: %d\nmin: %d\nmedian: %d\n", max_num, min_num, median);

    return 0;
}

int compare_num(const void *a, const void *b)
{
    int *x = (int *)a;
    int *y = (int *)b;

    if (*x < *y)
    {
        return -1;
    }
    else if (*x == *y)
    {
        return 0;
    }
    return 1;
}
