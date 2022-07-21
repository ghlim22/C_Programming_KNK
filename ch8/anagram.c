#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
    int counts1[26] = {0}, counts2[26] = {0};

    printf("Enter first word: ");
    read_word(counts1);
    printf("Enter second word: ");
    read_word(counts2);

    if (equal_array(counts1, counts2))
    {
        printf("anagram.\n");
    }
    else
    {
        printf("not anagram.\n");
    }

    return 0;
}

void read_word(int counts[26])
{
    char ch;
    int index;
    while ((ch = getchar()) != '\n')
    {
        if (ch >= 'a' && ch <= 'z')
        {
            index = (ch - 'a');
            counts[index]++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            index = ch - 'A';
            counts[index]++;
        }
    }
}

bool equal_array(int counts1[26], int counts2[26])
{
    for (int i = 0; i < 26; ++i)
    {
        if (counts1[i] != counts2[i])
        {
            return false;
        }
    }

    return true;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int counts1[26], counts2[26];
    memset(counts1, 0, 26 * sizeof(int));
    memset(counts2, 0, 26 * sizeof(int));

    for (; *word1 != 0; ++word1)
    {
        char ch = *word1;
        int index;
        if (ch >= 'a' && ch <= 'z')
        {
            index = (ch - 'a');
            counts1[index]++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            index = ch - 'A';
            counts1[index]++;
        }
    }

    for (; *word2 != 0; ++word2)
    {
        int index;
        char ch = *word2;
        if (ch >= 'a' && ch <= 'z')
        {
            index = (ch - 'a');
            counts2[index]++;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            index = ch - 'A';
            counts2[index]++;
        }
    }

    return equal_array(counts1, counts2);
}
