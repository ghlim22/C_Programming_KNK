#include <stdio.h>
#include <stdbool.h>

#define LEN (80)

int main(void)
{
    char input[LEN];
    char *p;
    char temp;
    int i;

    printf("Enter a message: ");
    for (p = input; p < p + LEN; ++p)
    {
        temp = getchar();
        if (temp == '\n')
        {
            p--;
            break;
        }
        else if (temp >= 'a' && temp <= 'z')
        {
            *p = temp;
        }
        else
        {
            --p;
        }
    }

    int len = (p - input) + 1;
    int mid = len / 2;
    bool isPalindrome = true;
    char *q;
    for (q = input; q < input + mid; ++q, --p)
    {
        if (len == 1)
        {
            break;
        }
        if (*p != *q)
        {
            isPalindrome = false;
        }
        len -= 2;
    }

    if (isPalindrome)
    {
        printf("Palindrome\n");
    }
    else
    {
        printf("Not a palindrome.\n");
    }

    return 0;
}