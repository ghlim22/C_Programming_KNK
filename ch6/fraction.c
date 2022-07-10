#include <stdio.h>

int main(void)
{
    int numerator, denominator, divisor, m, n;

    printf("Enter a fraction: ");
    scanf("%d/%d", &numerator, &denominator);

    m = numerator;
    n = denominator;
    while (n != 0)
    {
        int temp = m % n;
        m = n;
        n = temp;
    }
    divisor = m;

    printf("In lowest terms: %d/%d\n", numerator / divisor, denominator / divisor);

    return 0;
}