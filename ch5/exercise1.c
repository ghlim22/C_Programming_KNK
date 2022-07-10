#include <stdio.h>

int main(void)
{
    int input, digits;
    printf("Enter a number: ");
    scanf("%d", &input);

    if (input < 10)
    {
        digits = 1;
    }
    else if (input < 100)
    {
        digits = 2;
    }
    else
    {
        digits = 3;
    }

    printf("The number has %d digits.\n", digits);

    return 0;
}