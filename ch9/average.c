#include <stdio.h>

double GetAverage(double a, double b);

int main(void)
{
    double x, y, z;

    printf("Enter three numbers: ");
    scanf("%lf%lf%lf", &x, &y, &z);

    printf("Average of %g and %g: %g\n", x, y, GetAverage(x, y));
    printf("Average of %g and %g: %g\n", y, z, GetAverage(y, z));
    printf("Average of %g and %g: %g\n", x, z, GetAverage(x, z));

    return 0;
}

double GetAverage(double a, double b)
{
    return (a + b) / 2;
}