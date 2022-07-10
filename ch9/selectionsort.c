#include <stdio.h>

void selection_sort(int arr[], int len);

int main(void)
{
    int len = 10, arr[len];

    printf("Enter %d numbers: ", len);
    for (int i = 0; i < len; ++i)
    {
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, len);

    printf("Sorted:\n");
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
}

void selection_sort(int arr[], int len)
{
    int largeIdx = 0;

    if (len == 1)
    {
        return;
    }

    for (int i = 1; i < len; ++i)
    {
        if (arr[i] > arr[largeIdx])
        {
            largeIdx = i;
        }
    }

    int temp = arr[largeIdx];
    arr[largeIdx] = arr[len - 1];
    arr[len - 1] = temp;

    selection_sort(arr, len - 1);
}