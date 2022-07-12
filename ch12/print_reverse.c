#include <stdio.h>
#include <string.h>

int main(void)
{
    char input[80];
    char *p;
    printf("Enter a message: ");
    // scanf("%79[^\n]", input);
    int cur = 0;
    char ch;
    p = input;
    while ((ch = getchar()) != '\n')
    {
        *p++ = ch;
    }
    cur--;
    printf("Reversal is: ");
    // p = &input[cur];
    while (p >= input)
    {
        printf("%c", *p);
        p--;
    }

    return 0;
}