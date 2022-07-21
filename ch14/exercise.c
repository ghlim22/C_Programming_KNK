#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CUBE(x) ((x) * (x))
#define MOD_FOUR(N) ((N) % 4)
#define LESS_HUNDRED(x, y) ((x) * (y) < 100 ? 1 : 0)

#define NELEMS(a) (sizeof((a)) / sizeof((a)[0]))

#define DOUBLE(x) (2 * (x))

#define AVG(x, y) (((x) + (y)) / 2)
#define AREA(x, y) ((x) * (y))

#define DISP(f, x) (printf((#f) "(%g) = %g\n", (x), (f(x))))

#define STRINGIZE(x) #x
#define EXPAND_MACRO(x) STRINGIZE(x)
#define LINE_FILE ("Line" EXPAND_MACRO(__LINE__) " of file " __FILE__)

#define CHECK(x, y, n) ((x) >= 0 && (x) <= ((n)-1) && (y) >= 0 && (y) <= ((n)-1) ? 1 : 0)
#define MEDIAN(x, y, z) (((x) + (y) + (z)) / 3)
#define POLYNOMIAL(x) (3 * pow((x), 5) + 2 * pow((x), 4) - 5 * pow((x), 3) - pow((x), 2) + 7 * (x)-6)

#define ERROR(...) (fprintf(stderr, __VA_ARGS__))

int get_double(int x)
{
    return x * 2;
}

int main(void)
{
    int arr[] = {0, 1};

    printf("%d\n", NELEMS(arr));

#line 10 "foo.c"
    const char *str = LINE_FILE;
    puts(str);
    ERROR("Range error: %d\n", 3);
    return 0;
}