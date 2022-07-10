#include <stdio.h>

int main(void)
{
    char ch;
    int word_count, length = 0;
    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ')
        {
            word_count++;
            continue;
        }

        length++;
    }
    word_count++;

    printf("Average word length: %.1f\n", length / (float)word_count);

    return 0;
}