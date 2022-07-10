#include <stdio.h>

int main(void)
{
    char ch, num[15];
    printf("Enter phone number: ");

    for (int i = 0; (ch = getchar()) != '\n'; ++i)
    {
        switch (ch)
        {
        case 'A':
        case 'B':
        case 'C':
            num[i] = '2';
            break;
        case 'D':
        case 'E':
        case 'F':
            num[i] = '3';
            break;
        case 'G':
        case 'H':
        case 'I':
            num[i] = '4';
            break;
        case 'J':
        case 'K':
        case 'L':
            num[i] = '5';
            break;
        case 'M':
        case 'N':
        case 'O':
            num[i] = '6';
            break;
        case 'P':
        case 'R':
        case 'S':
            num[i] = '7';
            break;
        case 'T':
        case 'U':
        case 'V':
            num[i] = '8';
            break;
        case 'W':
        case 'X':
        case 'Y':
            num[i] = '9';
            break;
        default:
            num[i] = ch;
            break;
        }
    }

    printf("In numeric form: ");
    for (int i = 0; i < 15; ++i)
    {
        printf("%c", num[i]);
    }

    printf("\n");

    return 0;
}