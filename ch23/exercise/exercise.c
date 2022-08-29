#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// 1
double round_nearest(double x, int n)
{
    double power = pow(10.0, n);
    return x < 0.0 ? ceil(x * power - 0.5) / power : floor(x * power + 0.5) / power;
}
// 2
double evaluate_polynomial(double a[], int n, double x)
{
    double tmp = a[n];
    for (int i = n - 1; i >= 0; --i)
    {
        tmp = fma(tmp, x, a[i]);
    }
    return tmp;
}

// 4
bool is_identifier(char *str)
{
    if (!isalpha(*str) && *str != '_')
    {
        return false;
    }
    str++;
    while (*str)
    {
        if (!isalnum(*str) && *str != '_')
        {
            return false;
        }
        str++;
    }

    return true;
}

long int is_hex(char *str)
{
    long int res = 0L;
    int digit = -1;
    char *p = str;
    while (*str)
    {
        if (!isxdigit(*str))
        {
            return -1;
        }

        str++;
        digit++;
    }
    for (int i = digit; i >= 0; --i)
    {
        long int tmp = 0L;
        switch (*p)
        {
        case 'A':
        case 'a':
            tmp = 10L;
            break;
        case 'B':
        case 'b':
            tmp = 11L;
            break;
        case 'C':
        case 'c':
            tmp = 12L;
            break;
        case 'D':
        case 'd':
            tmp = 13L;
            break;
        case 'E':
        case 'e':
            tmp = 14L;
            break;
        case 'F':
        case 'f':
            tmp = 15L;
            break;
        default:
            tmp = *p - '0';
            break;
        }

        res |= tmp << i * 4;
        p++;
    }

    return res;
}

// 8
int numchar(const char *s, char ch)
{
    int count = 0;
    char *p;
    for (p = s; p != NULL && *p != '\0'; p = strchr(p, ch))
    {
        p++;
        count++;
    }
    return count;
}

// 7
void my_capitalize_ch(char *s, char ch)
{
    char *p;
    while ((p = strrchr(s, ch)) != NULL)
    {
        *s = toupper(ch);
        p--;
    }
}

// 12
// a

char *my_strdup(char *s)
{
    char *dest;
    if ((dest = malloc(strlen(s) + 1)) == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < strlen(s) + 1; ++i)
    {
        dest[i] = s[i];
    }

    return dest;
}

// b

int my_stricmp(const char *s1, const char *s2)
{
    int ret = 0;
    while (ret == 0 && *s1 & *s2)
    {
        ret += tolower(*s1) - tolower(*s2);
        s1++;
        s2++;
    }
    return ret;
}

// 12 (c)
char *my_strlwr(char *s)
{
    while (*s != '\0')
    {
        if (isupper(*s))
        {
            *s = tolower(*s);
        }
        s++;
    }
    return s;
}

// 12 (d)
char *my_strrev(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; ++i)
    {
        char tmp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = tmp;
    }
    return s;
}

// 12 (e)
char *my_strset(char *s, char ch)
{
    while (*s != '\0')
    {
        *s++ = ch;
    }

    return s;
}

// 13
int count_words(char *sentence)
{
    int cnt = 0;
    char *p = sentence;
    p = strtok(p, " \t\n\r\v\f");
    if (p == NULL)
    {
        return cnt;
    }
    cnt++;
    while ((p = strtok(NULL, " \t\n\r\v\f")) != NULL)
    {
        cnt++;
    }

    return cnt;
}

int main(void)
{
    char str[100];
    printf("enter hexadecimal digit: ");
    scanf("%s", str);
    long int res = is_hex(str);
    printf("%ld\n", res);

    // 9
    char ch = 'a';
    if (strchr("abc", ch) != NULL)
    {
        // do something...
    }

    // 10
    char *str1 = "";
    if (strstr("foo-bar-baz", str) != NULL)
    {
        //
    }

    // 11
    char str2[] = "hello";
    int n = 3;
    memset(str2 + strlen(str2) - n, '!', n);
    printf("%s\n", str2);

    char str3[] = "hello world disney land";
    int cnt = count_words(str3);
    printf("%d\n", cnt);

    double d1 = round_nearest(-12.345, 2);
    printf("%f\n", d1);

    char str4[] = "drake";
    my_strrev(str4);
    printf("%s\n", str4);

    return 0;
}