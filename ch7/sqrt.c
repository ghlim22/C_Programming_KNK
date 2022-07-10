#include <stdio.h>
#include <math.h>

int main(void)
{
    double actual, temp, average, cmp, x, y;
    printf("Enter a positive number: ");
    scanf("%lf", &x);
    y = 1;
    actual = fabs(x);
    do
    {
        cmp = y;
        temp = x / y;
        average = (temp + y) / 2.0;
        y = average;
    } while (y - cmp > 0.00001 || y - cmp < -0.00001);

    printf("Square root: %f", average);

    return 0;
}