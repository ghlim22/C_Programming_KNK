#include <stdio.h>

#pragma data(heap_size = > 1000, stack_size = > 2000)

#define MAX(i, j) ((x) > (y) ? (x) : (y))
#define IS_EVEN(n) ((n) % 2 == 0)
#define TOUPPER(c) ('a' <= (c) && (c) <= 'z' ? (c) - 'a' + 'A' : (c))
#define getchar() getc(stdin)
#define PRINT_INT(n) printf(#n "%d\n", (n))
#define MK_ID(n) i##n
#define GENERIC_MAX(type)           \
    type type##_max(type x, type y) \
    {                               \
        return x > y ? x : y        \
    }
#define PI (3.14159)
#define TWO_PI (2 * PI)
#define ECHO(s)  \
    do           \
    {            \
        gets(s); \
        puts(s); \
    } while (0)
#define CHECK_ZERO(divisor)                               \
    if (divisor == 0)                                     \
    {                                                     \
        printf("*** Attempt to divide by zero on line %d" \
               "of file %s ***\n",                        \
               __LINE__, __FILE__);                       \
    }
#define TEST(condition, ...) ((condition) ? printf("Passed test: %s\n", #condition) : printf(__VA_ARGS__))
#define FUNCTION_CALLED() printf("%s called\n", __func__);
#define FUNCTION_RETURNS() printf("%s returns\n", __func__);

#define DEBUG (1)

void function_example(void)
{
    FUNCTION_CALLED();
    FUNCTION_RETURNS();
}

int main(void)
{
    printf("Compiled on %s at %s.\n", __DATE__, __TIME__);
    int voltage = 20;
    int max_voltage = 15;

    TEST(voltage <= max_voltage, "Voltage %d exceeds %d\n", voltage, max_voltage);
    function_example();

    int i = 1;
    int j = 2;

#if DEBUG
    printf("value of i: %d\n", i);
    printf("value of j: %d\n", j);
#endif

#if defined(DEBUG)
    printf("value of i: %d\n", i);
    printf("value of j: %d\n", j);
#endif

#if defined(WIN32)
    printf("This is a windows.\n");
#elif defined(MAC_OS)
    printf(This is a mac.\n);
#elif defined(LINUX)
    printf("This is a linux.\n");
#else
#error No operating system specified
#endif

#if __STDC__
//
#else
//
#endif

#ifndef BUFFER_SIZE
#define BUFFER_SIZE (256)
#endif

#if 0
/* comments... */
// code
// conditioning out!
#endif

    return 0;
}
