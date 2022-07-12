#include <stdio.h>

#define N (10)
#define SIZE ((int)(sizeof(a) / sizeof(a[0])))

int main(void)
{
    int a[N] = {0}, *p;

    printf("Enter %d numbers: ", N);
    for (p = a; p < a + N; ++p)
    {
        scanf("%d", p);
    }

    printf("In reverse order: ");
    for (p = a + N - 1; p >= a; --p)
    {
        printf(" %d ", *p);
    }

    printf("\n");

    return 0;
}
