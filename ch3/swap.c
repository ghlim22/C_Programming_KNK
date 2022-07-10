#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 10;
    int y = 14;
    swap(&x, &y);

    printf("%d\n%d", x, y);

    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}