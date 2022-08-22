#include <stdio.h>
#include <stdlib.h>

struct record
{
    /* data */
};

// 12
int count_periods(const char *filename)
{
    FILE *fp;
    int n = 0;
    int ch;

    if ((fp = fopen(filename, "r")) != NULL)
    {
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == '.')
            {
                n++;
            }
        }
        fclose(fp);
    }

    return n;
}

// 13
int line_length(const char *filename, int n)
{
    FILE *fp;
    int ch;
    int len = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return -1;
    }

    while (n > 1)
    {
        while ((ch = getc(fp)) != '\n')
        {
            if (ch == EOF)
            {
                return 0;
            }
        }
        n--;
    }

    while ((ch = getc(fp)) != '\n' && ch != EOF)
    {
        len++;
    }

    return len;
}

// 14
char *my_fgets(char *restrict s, int n, FILE *restrict stream)
{
    int ch, len = 0;

    while (len < n - 1)
    {
        if ((ch = fgetc(stream)) == EOF)
        {
            if (len == 0 || ferror(stream))
            {
                return NULL;
            }
        }

        s[len++] = ch;
        if (ch == '\n')
        {
            break;
        }
    }

    s[len] = '\0';
    return s;
}

int my_fputs(char *restrict s, FILE *restrict stream)
{
    while (*s != '\0')
    {
        if (fputc(*s, stream) == EOF)
        {
            return EOF;
        }
        s++;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    /*
    // 15
    FILE *fp;
    int n;
    fseek(fp, (long)(sizeof(struct record) * n), SEEK_SET);
    fseek(fp, -(long)(sizeof(struct record)), SEEK_END);
    fseek(fp, (long)(sizeof(struct record)), SEEK_CUR);
    fseek(fp, -(long)(sizeof(struct record) * 2), SEEK_CUR);
    */

    char sales_rank[100];
    char *str = "helllo#world123,1234afa";
    // 16
    sscanf(str, str[0] == '#' ? "%*[#]%[0123456789,]" : "%*[^#]%*[#]%*[^0123456789]%[0123456789,]", sales_rank);

    printf("%s\n", sales_rank);

    return 0;
}