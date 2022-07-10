#include <stdio.h>

int main(void)
{
    int num, digits;

    printf("Enter a non negative integer: ");
    scanf("%d", &num);

    do
    {
        num /= 10;
        digits++;
    } while (num > 0);

    printf("The number has %d digit(s).\n", digits);

    return 0;
}