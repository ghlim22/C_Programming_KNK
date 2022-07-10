#include <stdio.h>

int main(void)
{
    int input;
    float result = 1;

    printf("Enter a positive integer: ");
    scanf("%d", &input);

    for (int i = 1; i <= input; ++i)
    {
        result *= i;
    }

    printf("Factorial of %d: %f\n", input, result);

    return 0;
}
