#include <stdio.h>
#include <string.h>
#include <ctype.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int main(void)
{
    char input;
    //int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int point = 0, index;

    printf("Enter a word: ");

    input = getchar();
    point = POINTS[input - 'A'];

    while ((input = getchar()) != '\n')
    {
        if (input >= 'a' && input <= 'z')
        {
            input = toupper(input);
            point += POINTS[input - 'A'];
        }
        else if (input >= 'A' && input <= 'Z')
        {
            point += POINTS[input - 'A'];
        }
    }
    printf("Scrabble value: %d\n", point);

    return 0;
}

int compute_scrabble_value(const char *word)
{
    int point = 0;
    char input;
    while (*word != '\0')
    {
        input = *word;
        if (input >= 'a' && input <= 'z')
        {
            input = toupper(input);
            point += POINTS[input - 'A'];
        }
        else if (input >= 'A' && input <= 'Z')
        {
            point += POINTS[input - 'A'];
        }
    }
    
    return point;
}
