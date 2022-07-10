#include <stdio.h>

void printreverse(int num);

int main(void)
{
    int input;
    printf("Enter a three-digit number: ");
    scanf("%d", &input);

    printreverse(input);

    return 0;
}

void printreverse(int num)
{
    if (num == 0)
    {
        return;
    }
    printf("%d", num % 10);
    printreverse(num / 10);
}