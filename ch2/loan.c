#include <stdio.h>

float get_monthly_amount(float value, float rate, float monthly_pay, int month);

int main(void)
{
    float total_amount, interest_rate, monthly_payment;
    int payment_count;

    printf("Enter amount of loan: ");
    scanf("%f", &total_amount);
    printf("Enter interest rate: ");
    scanf("%f", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthly_payment);
    printf("Enter the number of payments: ");
    scanf("%d", &payment_count);

    interest_rate /= 100.0f;
    float monthly_rate = interest_rate / 12;

    /*
    total_amount = total_amount - monthly_payment;
    printf("Balance remaining after first payment: $%.2f\n", total_amount);

    total_amount = (total_amount * (1 + monthly_rate)) - monthly_payment;
    printf("Balance remaining after second payment: $%.2f\n", total_amount);

    total_amount = (total_amount * (1 + monthly_rate)) - monthly_payment;
    printf("Balance remaining after third payment: $%.2f\n", total_amount);
    */

    for (int i = 0; i < payment_count; ++i)
    {
        total_amount = total_amount - monthly_payment;
        printf("Balance remaining after %d'th payment: $%.2f\n", i + 1, total_amount);
        total_amount *= 1 + monthly_rate;
    }

    return 0;
}
