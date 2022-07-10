#include <stdio.h>

int main(void)
{
    int input;

    printf("Enter a number: ");
    scanf("%d", &input);
    printf("Result: %d\n", input * (input - 2));

    return 0;
}