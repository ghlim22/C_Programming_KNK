#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char **argv)
{
    setlocale(LC_ALL, argv[1]);
    struct lconv *tmp = localeconv();
    printf("decimal point: \"%s\"", tmp->decimal_point);
    printf("thousands sep: \"%s\"", tmp->thousands_sep);

    return 0;
}