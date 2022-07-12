#include <stdio.h>

#define N (10)

void quicksort(int a[], int *low, int *high);
int *split(int a[], int *low, int *high);

int main(void)
{
    int a[N], i;

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; ++i)
    {
        scanf("%d", &a[i]);
    }

    quicksort(a, &a[0], &a[N - 1]);

    printf("In sorted order: ");
    for (i = 0; i < N; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

void quicksort(int a[], int *low, int *high)
{
    int *middle;

    if (*low >= *high)
    {
        return;
    }

    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int *split(int a[], int *low, int *high)
{
    int part_element = *low;

    while (1)
    {
        while (low < high && part_element <= *high)
        {
            high--;
        }

        if (low >= high)
        {
            break;
        }

        // a[low++] = a[high];
        *low++ = *high;

        while (low < high && *low <= part_element)
        {
            low++;
        }

        if (low >= high)
        {
            break;
        }

        // a[high--] = a[low];
        *high-- = *low;
    }

    // a[high] = part_element;
    *high = part_element;
    return *high;
}