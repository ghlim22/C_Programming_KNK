#include <stdio.h>

int main(void)
{
    int first_digit, second_digit, user_input;
    char *first, *second, *teen;

    printf("Enter a two-digit number: ");
    scanf("%d", &user_input);

    if (user_input >= 10 && user_input <= 19)
    {
        switch (user_input)
        {
        case 10:
            teen = "ten";
            break;
        case 11:
            teen = "eleven";
            break;
        case 12:
            teen = "tweleve";
            break;
        case 13:
            teen = "thirteen";
            break;
        case 14:
            teen = "fourteen";
            break;
        case 15:
            teen = "fifteen";
            break;
        case 16:
            teen = "sixteen";
            break;
        case 17:
            teen = "seventeen";
            break;
        case 18:
            teen = "eighteen";
            break;
        case 19:
            teen = "nineteen";
            break;
        default:
            break;
        }

        printf("Your entered the number %s.\n", teen);

        return 0;
    }
    else
    {
        switch (user_input / 10)
        {
        case 2:
            first = "twenty";
            break;
        case 3:
            first = "thirty";
            break;
        case 4:
            first = "fourty";
            break;
        case 5:
            first = "fifty";
            break;
        case 6:
            first = "sixty";
            break;
        case 7:
            first = "seventy";
            break;
        case 8:
            first = "eighty";
            break;
        case 9:
            first = "ninety";
            break;
        default:
            break;
        }

        switch (user_input % 10)
        {
        case 1:
            second = "one";
            break;
        case 2:
            second = "two";
            break;
        case 3:
            second = "three";
            break;
        case 4:
            second = "four";
            break;
        case 5:
            second = "five";
            break;
        case 6:
            second = "six";
            break;
        case 7:
            second = "seven";
            break;
        case 8:
            second = "eight";
            break;
        case 9:
            second = "nine";
            break;
        default:
            break;
        }
    }

    if (user_input < 10)
    {
        printf("You entered the number %s.\n", second);
    }
    else
    {
        printf("You entered the number %s-%s.\n", first, second);
    }

    return 0;
}