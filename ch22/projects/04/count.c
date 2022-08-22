#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int count_chars(const char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        return -1;
    }

    int count = 0;
    int ch;
    while ((ch = getc(fp)) != EOF)
    {
        if (!isspace(ch))
        {
            count++;
        }
    }

    if (ferror(ch) || feof(ch))
    {
        return -1;
    }

    return count;
}

int count_words(const char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        return -1;
    }

    int word_count = 0;
    int ch;
    bool in_word = false;
    while ((ch = getc(fp)) != EOF)
    {
        if (isspace(ch))
        {
            in_word = false;
        }
        else if (!in_word)
        {
            in_word = true;
            word_count++;
        }
    }
    fclose(fp);

    return word_count;
}

int count_lines(const char *file_name)
{
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL)
    {
        return -1;
    }

    int line_count = 0;
    int ch;
    while ((ch = getc(fp)) != EOF)
    {
        if (ch == '\n')
        {
            line_count++;
        }
    }

    fclose(fp);

    return line_count;
}