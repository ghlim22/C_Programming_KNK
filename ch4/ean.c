#include <stdio.h>
#define DIGIT_LENGTH (12)

int main(void)
{
    int num, first_sum, second_sum, total;
    int digits[DIGIT_LENGTH];
    printf("Enter the first 12 digits of a UPC: ");
    scanf("%d", &num);

    for (int i = DIGIT_LENGTH - 1; i > 0; --i)
    {
        digits[i] = num % 10;
        num /= 10;
    }

    first_sum = 0;
    for (int i = 1; i < DIGIT_LENGTH; i += 2)
    {
        first_sum += digits[i];
    }
    second_sum = 0;
    for (int i = 0; i < DIGIT_LENGTH; i += 2)
    {
        second_sum += digits[i];
    }

    total = first_sum * 3 + second_sum - 1;
    printf("Check digit: %d\n", 9 - total % 10);

    return 0;
}