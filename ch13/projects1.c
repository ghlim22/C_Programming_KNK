#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

int main(void)
{
    char temp[21];
    char smallest_word[21];
    char largest_word[21];
    int len = 0;

    while (1)
    {
        printf("Enter word: ");
        scanf("%s", temp);
        len = strlen(temp);
        if (len == 4)
        {
            break;
        }

        if (strcmp(smallest_word, "") == 0)
        {
            strcpy(smallest_word, temp);
            strcpy(largest_word, temp);
        }
        else
        {
            if (strcmp(temp, smallest_word) < 0)
            {
                strcpy(smallest_word, temp);
            }

            if (strcmp(temp, largest_word) > 0)
            {
                strcpy(largest_word, temp);
            }
        }
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}
