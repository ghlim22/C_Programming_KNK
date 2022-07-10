#include <stdio.h>
#include <stdbool.h>

int main(void)
{

    int digit, occur[10] = {0};
    long n;

    while (true)
    {
        printf("Enter a number: ");
        scanf("%ld", &n);
        if (n <= 0)
        {
            return 0;
        }

        while (n > 0)
        {
            digit = n % 10;
            occur[digit]++;
            n /= 10;
        }

        printf("Digit:      %-3d%-3d%-3d%-3d%-3d%-3d%-3d%-3d%-3d%-3d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
        printf("Occurrences:");
        for (int i = 0; i < 10; ++i)
        {
            printf("%-3d", occur[i]);
            occur[i] = 0;
        }
        printf("\n");
    }

    return 0;
}