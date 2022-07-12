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
    for (i = 0; i < LEN; ++i)
    {
        temp = getchar();
        if (temp == '\n')
        {
            i--;
            break;
        }
        else if (temp >= 'a' && temp <= 'z')
        {
            input[i] = temp;
        }
        else
        {
            --i;
        }
    }

    int len = i + 1;
    int mid = len / 2;
    bool isPalindrome = true;
    for (int j = 0; j < mid; ++j, --i)
    {
        if (len == 1)
        {
            break;
        }
        if (input[i] != input[j])
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