#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    for (int i = 2; i * i < n; i += 2)
    {
        printf("%5d\n", i * i);
    }

    return 0;
}