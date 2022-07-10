#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char f, ch;
    char *last;
    char name[20] = {0};
    printf("Enter a first and last name: ");
    scanf(" %c", &f);
    while ((ch = getchar()) != ' ')
    {
    }
    /*
    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ')
        {
            continue;
        }
        printf("%c", ch);
    }
    */
    for (int i = 0; (ch = getchar()) != '\n'; ++i)
    {
        if (ch == ' ')
        {
            continue;
        }

        name[i] = ch;
    }
    for (int i = 0; name[i] != 0; ++i)
    {
        printf("%c", name[i]);
    }
    printf(", %c.\n", f);

    return 0;
}