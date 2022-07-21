#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>

void capitalize(char str[]);
void capitalize_new(char str[]);
void censor(char str[]);
void get_extension(const char *file_name, char *extension);
void build_index_url(const char *domain, char *index_url);

int main(void)
{
    char ptr[] = "Hello";
    capitalize_new(ptr);
    printf("%s\n", ptr);

    char test[] = "food fool";
    censor(test);
    printf("%s\n", test);

    char ext[10];
    get_extension("Apple.exec", ext);
    printf("%s\n", ext);

    char domain[30];
    build_index_url("naver.com", domain);
    printf("%s\n", domain);

    return 0;
}

void capitalize(char str[])
{
    for (int i = 0; str[i] != '\0'; ++i)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
}

void capitalize_new(char str[])
{
    for (char *p = str; *p != '\0'; ++p)
    {
        if (*p >= 'a' && *p <= 'z')
        {
            *p -= 32;
        }
    }
}

void censor(char str[])
{
    for (char *p = str + 2; *p != '\0'; ++p)
    {
        if (*p == 'o' && *(p - 1) == 'o' && *(p - 2) == 'f')
        {
            *p = 'x';
            *(p - 1) = 'x';
            *(p - 2) = 'x';
        }
    }
}

int Str_cmp(char *s, char *t)
{
    while (*s == *t)
    {
        if (*s == '\0')
        {
            return 0;
        }

        s++;
        t++;
    }

    return *s - *t;
}

void get_extension(const char *file_name, char *extension)
{
    char *p = NULL;
    for (p = file_name; *p != '\0'; ++p)
    {
        if (*p == '.')
        {
            break;
        }
    }

    if (*p != '.')
    {
        extension = "";
        return;
    }

    strcpy(extension, p + 1);
}

void build_index_url(const char *domain, char *index_url)
{
    sprintf(index_url, "http://www.%s/index.html", domain);
}

// a) 4
// b) 4
// c) f returns 0 두 문자열에 겹치는 글자가 없다면 0 return

int count_spaces(const char *s)
{
    int cnt = 0;
    while (*s != '/0')
    {
        if (s++ == ' ')
        {
            cnt++;
        }
    }

    return cnt;
}

bool test_extension(const char *file_name, const char *extension)
{
    while (*file_name++ != '.')
        ;

    while (*file_name)
    {
        if (toupper(*file_name++) != toupper(*extension++))
        {
            return false;
        }
    }

    return true;
}

void remove_filename(char *url)
{
    int len = strlen(url);
    for (int i = len - 1; i >= 0; --i)
    {
        if (url[i] == '/')
        {
            url[i] = '\0';
            break;
        }
    }
}
