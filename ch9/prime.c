#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2, cnt = sqrt(n); i < cnt; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))
    {
        printf("Prime.\n");
    }
    else
    {
        printf("Not Prime.\n");
    }

    return 0;
}
