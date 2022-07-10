#include <stdio.h>

int main(void)
{
    int input[4];
    int max, min;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &input[0], &input[1], &input[2], &input[3]);

    max = input[0];
    min = input[0];

    for (int i = 1; i < 4; ++i)
    {
        if (input[i] > max)
        {
            max = input[i];
        }

        if (input[i] < min)
        {
            min = input[i];
        }
    }

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);

    return 0;
}