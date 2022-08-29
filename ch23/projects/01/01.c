#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c, d, x1, x2;

    printf("Enter a b c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    d = b * b - 4 * a * c;
    if (d < 0.0)
    {
        printf("root are complex\n");
    }
    else
    {
        x1 = (-b + sqrt(d)) / (2 * a);
        x2 = (-b - sqrt(d)) / (2 * a);

        printf("x1: %f\nx2: %f\n", x1, x2);
    }

    return 0;
}