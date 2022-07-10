#include <stdio.h>
#include <stdbool.h>

bool checkUPC(int input);

int main(void)
{
    int user_input;
    printf("Enter UPC: ");
    scanf("%d", &user_input);
    printf("%s\n", checkUPC(user_input) ? "VALID" : "NOT VALID");

    return 0;
}

bool checkUPC(int input)
{
    int first_sum, second_sum, total, check_digit;
    int last_digit = input % 10;
    int digits[11];

    printf("%d\n", last_digit);

    input /= 10;
    if (input / 10000000000 == 0)
    {
        digits[0] = 0;
        for (int i = 10; i > 0; --i)
        {
            digits[i] = input % 10;
            input /= 10;
            printf("%d", digits[i]);
        }
    }
    else
    {
        for (int i = 10; i >= 0; --i)
        {
            digits[i] = input % 10;
            input /= 10;
        }
    }
    printf("\n");

    first_sum = 0;
    for (int i = 0; i < 11; i += 2)
    {
        first_sum += digits[i];
    }

    second_sum = 0;
    for (int i = 1; i < 11; i += 2)
    {
        second_sum += digits[i];
    }

    total = first_sum * 3 + second_sum;
    total--;
    check_digit = 9 - total % 10;
    printf("%d\n", check_digit);

    return (check_digit == last_digit);
}