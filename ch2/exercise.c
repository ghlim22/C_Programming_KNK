#include <stdio.h>
#define PI (3.14f)
#define SPHERE_FACTOR (4.0f / 3.0f * PI * PI * PI)

int main(void)
{
    printf("       *\n");
    printf("      *\n");
    printf("     *\n");
    printf("*   *\n");
    printf(" * *\n");
    printf("  *\n");

    int radius;
    printf("Enter the radius: ");
    scanf("%d", &radius);
    printf("The volume of a sphere with a %d meter radius: %.2f m^3\n", radius, radius * SPHERE_FACTOR);

    {
        float user_input;
        printf("Enter an amount: ");
        scanf("%f", &user_input);
        printf("With tax added: $%f\n", user_input * (1.05f));
    }

    {
        int x;
        printf("Enter the number x: ");
        scanf("%d", &x);
        printf("3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 = %d\n", 3 * x * x * x * x * x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6);
        printf("((((3x + 2) * x - 5) * x) + 7) * x - 6 = %d\n", ((((3 * x + 2) * x - 5) * x) + 7) * x - 6);
    }

    {
        int amount;
        printf("Enter a dollar amount: ");
        scanf("%d", &amount);
        printf("$20 bills: %d\n", amount / 20);
        printf("$10 bills: %d\n", (amount % 20) / 10);
        printf("$5 bills: %d\n", (amount % 20) % 10 / 5);
        printf("$1 bills: %d\n", amount % 20 % 10 % 5);
    }






}