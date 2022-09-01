#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

void print_num(int n)
{
    if (n == 0)
    {
        return;
    }

    print_num(n / 10);
    putchar((n % 10) + '0');
}

void print_str(const char *str)
{
    while (*str != '\0')
    {
        putchar(*str++);
    }
}

int find_max(int n, ...)
{
    va_list ap;
    int i, cur, largest;

    va_start(ap, n);
    largest = n;
    while ((cur = va_arg(ap, int)) != 0)
    {
        if (cur > largest)
        {
            largest = cur;
        }
    }
    va_end(ap);
    return largest;
}

int my_printf(const char *format, ...)
{
    int i = 0;
    int count = 0;
    int len = strlen(format);
    char cur;

    va_list ap;
    va_start(ap, format);

    while ((cur = format[i]) != '\0')
    {
        if (cur == '%')
        {
            if (i < len)
            {
                switch (format[i + 1])
                {
                case 'd':
                    print_num(va_arg(ap, int));
                    count++;
                    break;
                case 's':
                    print_str(va_arg(ap, const char *));
                    count++;
                    break;
                default:
                    break;
                }
                i++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            putchar(cur);
            count++;
        }
        i++;
    }
    va_end(ap);
    return count;
}

void display(int n, ...)
{
    va_list ap;
    va_start(ap, n);

    for (int i = 0; i < n; ++i)
    {
        print_str(va_arg(ap, char *));
        putchar(' ');
    }
    putchar('\n');
}

char *vstrcat(const char *first, ...)
{
    char *cur, *res;
    int mem_size = 0;
    va_list ap;
    va_start(ap, first);
    mem_size += strlen(first);
    while ((cur = va_arg(ap, char *)) != (char *)NULL)
    {
        mem_size += strlen(cur);
    }
    va_end(ap);

    res = malloc(mem_size + 1);
    if (res == NULL)
    {
        return NULL;
    }

    va_start(ap, first);
    strcpy(res, first);
    while ((cur = va_arg(ap, char *)) != (char *)NULL)
    {
        strcat(res, cur);
    }

    return res;
}

char *max_pair(int num_pairs, ...)
{
    va_list ap;
    va_start(ap, num_pairs);
    int largest = va_arg(ap, int);
    char *largest_name = malloc(sizeof(char) * 100);
    strcpy(largest_name, va_arg(ap, char *));

    for (int i = 0; i < num_pairs - 1; ++i)
    {
        int cur = va_arg(ap, int);

        if (cur > largest)
        {
            largest = cur;
            strcpy(largest_name, va_arg(ap, char *));
        }
        else
        {
            va_arg(ap, char *);
        }
    }

    return largest_name;
}

double random_d(void)
{
    return (double)rand() / (RAND_MAX + 1);
}

time_t pass_year(int year)
{
    struct tm t;
    t.tm_year = year - 1900;
    t.tm_yday = 0;
    t.tm_hour = 0;
    return mktime(t);
}

int main(void)
{
    int max = find_max(1, 2, 5, 3, 10, 427, 22, 0);
    printf("%d\n", max);

    my_printf("my name is %s. i was born in %d.\n", "hyun", 2000);

    display(4, "Special", "Agent", "Dale", "Cooper");

    char *res = vstrcat("hello, ", "world ", "This is from ", "Austin\n");
    printf("%s", res);

    char *max_name = max_pair(5, 180, "Seinfeld", 180, "I love lucy", 39, "The Honeymonners", 210, "All in the family", 86, "The Sopranos");
    printf("%s", max_name);
    free(max_name);
    return 0;
}