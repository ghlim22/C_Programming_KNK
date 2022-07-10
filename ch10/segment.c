#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_DIGITS (10)

const int segments[10][7] =
    {
        {1, 1, 1, 1, 1, 1, 0},
        {0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 0, 0, 1},
        {0, 1, 1, 0, 0, 1, 1},
        {1, 0, 1, 1, 0, 1, 1},
        {1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1}};

char digits[4][4 * MAX_DIGITS];

void clear_digits_array(void);
void process_digit(int digit, int position);
void print_digits_array(void);

int main(void)
{
    char ch;
    int pos = 0, cnt = 0, d;

    printf("Enter a number: ");
    while ((ch = getchar()) != '\n')
    {
        if (cnt >= MAX_DIGITS)
        {
            break;
        }
        if (ch >= '0' && ch <= '9')
        {
            d = atoi(&ch);
            process_digit(d, pos);
            pos += 4;
            cnt++;
        }
    }

    print_digits_array();

    return 0;
}

void clear_digits_array(void)
{
    for (int i = 0; i < sizeof(digits) / sizeof(digits[0]); ++i)
    {
        for (int j = 0; j < sizeof(digits[0]) / sizeof(digits[0][0]); ++j)
        {
            digits[i][j] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    for (int i = 0; i < 7; ++i)
    {
        if (segments[digit][i])
        {
            switch (i)
            {
            case 0:
                digits[0][position + 1] = '_';
                break;
            case 1:
                digits[1][position + 2] = '|';
                break;
            case 2:
                digits[2][position + 2] = '|';
                break;
            case 3:
                digits[2][position + 1] = '_';
                break;
            case 4:
                digits[2][position] = '|';
                break;
            case 5:
                digits[1][position] = '|';
                break;
            case 6:
                digits[1][position + 1] = '_';
                break;
            default:
                break;
            }
        }
    }
}

void print_digits_array(void)
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4 * MAX_DIGITS; ++j)
        {
            if (digits[i][j] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("%c", digits[i][j]);
            }
        }
        printf("\n");
    }
}
