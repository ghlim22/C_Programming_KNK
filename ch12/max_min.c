#include <stdio.h>
#include <limits.h>

void max_min(int arr[], int len, int *max, int *min);

int main(void)
{
    int arr[10];
    int len = (int)(sizeof(arr) / sizeof(arr[0]));
    int big;
    int small;

    printf("Enter %d numbers: ", len);
    for (int i = 0; i < len; ++i)
    {
        scanf(" %d", &arr[i]);
    }

    max_min(arr, len, &big, &small);

    printf("Largest: %d\nSmallest: %d\n", big, small);

    return 0;
}

void max_min(int arr[], int len, int *max, int *min)
{
    int big = INT_MIN;
    int small = INT_MAX;
    int *p;
    for (p = &arr[0]; p < p + len; ++p)
    {
        if (*p > big)
        {
            big = *p;
        }

        if (*p < small)
        {
            small = *p;
        }
    }

    *max = big;
    *min = small;
}
