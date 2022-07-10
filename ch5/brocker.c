#include <stdio.h>

int main(void)
{
    float commision, value, share, price, rival_commision;
    do
    {
        printf("Enter the number of shares: ");
        scanf("%f", &share);
        if (share == 0)
        {
            break;
        }
        printf("Enter the price per share: ");
        scanf("%f", &price);

        value = share * price;

        if (value < 2500.00f)
        {
            commision = 30.00f + 0.017f * value;
        }
        else if (value < 6250.00f)
        {
            commision = 56.00f + 0.0066f * value;
        }
        else if (value < 20000.00f)
        {
            commision = 76.00f + 0.0034f * value;
        }
        else if (value < 50000.00f)
        {
            commision = 100.00f + 0.0022f * value;
        }
        else if (value < 5000000.00f)
        {
            commision = 155.00f + 0.0011f * value;
        }
        else
        {
            commision = 255.00f + 0.0009f * value;
        }

        if (commision < 39.00f)
        {
            commision = 39.00f;
        }

        if (share < 2000)
        {
            rival_commision = 33.00f + 0.03f * share;
        }
        else
        {
            rival_commision = 33.00f + 0.02f * share;
        }

        printf("Commision: $%.2f\n", commision);
        printf("Rival Commision: $%.2f\n", rival_commision);

    } while (share > 0);

    return 0;
}