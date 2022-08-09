#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN (20)

void *my_malloc(size_t size);
int compare_words(const void *a, const void *b);

int main(void)
{
    char **words = NULL, *word = NULL;
    int i, size = 1, num_words = 0;

    words = (char **)my_malloc((size_t)sizeof(char *));
    for (i = 0;; ++i)
    {
        word = (char *)my_malloc((size_t)(WORD_LEN + 1));

        printf("Enter a word: ");
        fgets(word, WORD_LEN + 1, stdin);

        if (word[strlen(word) - 1] == '\n')
        {
            word[strlen(word) - 1] = '\0';
        }

        if (word[0] == '\0')
        {
            break;
        }

        *(words + i) = word;
        num_words++;

        if (num_words == size)
        {
            if ((words = (char **)realloc(words, (size_t)sizeof(char *) * (size *= 2))) == NULL)
            {
                printf("realloc error");
                exit(EXIT_FAILURE);
            }
        }
    }

    qsort(words, num_words, sizeof(char *), compare_words);
    for (int i = 0; i < num_words; ++i)
    {
        printf("%s ", *(words + i));
    }
    printf("\n");

    return 0;
}

void *my_malloc(size_t size)
{
    void *res = malloc(size);
    if (res == NULL)
    {
        fprintf(stderr, "malloc failed at my_malloc\n");
        exit(0);
    }
    return res;
}

int compare_words(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}
