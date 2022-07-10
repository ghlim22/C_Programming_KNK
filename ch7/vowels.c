#include <stdio.h>

int main(void)
{
    char ch;
    int count = 0;
    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n')
    {
        switch (ch)
        {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            count++;
            break;
        default:
            break;
        }
    }

    printf("Your sentence contains %d vowels.\n", count);

    return 0;
}