#include <stdio.h>
int power(int num, int n);

int main(void)
{
    int num, n;

    printf("Enter num and n: ");
    scanf("%d%d", &num, &n);

    printf("%d\n", power(num, n));
    return 0;
}

int power(int num, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (n % 2 == 0)
    {
        return power(num, n / 2) * power(num, n / 2);
    }
    else
    {
        return num * power(num, n - 1);
    }
}