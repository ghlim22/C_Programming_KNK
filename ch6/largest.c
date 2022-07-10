#include <stdio.h>

int main(void)
{
    int input, largest;
    largest = 0;
    do
    {
        printf("Enter a number: ");
        scanf("%d", &input);
        if (input > largest)
        {
            largest = input;
        }
    } while (input > 0);

    printf("The largest number entered was %d.\n", largest);

    return 0;
}