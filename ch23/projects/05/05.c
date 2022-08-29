#include <stdio.h>
#include <math.h>

int main(void)
{
    double init_amount, rate;
    int years;

    printf("Enter the original amount deposited: ");
    scanf("%lf", &init_amount);
    printf("Enter the interest rate: ");
    scanf("%lf", &rate);
    printf("Enter the number of years: ");
    scanf("%d", &years);

    printf("The result is %6.2f\n", init_amount * exp(rate * years));
    return 0;
}