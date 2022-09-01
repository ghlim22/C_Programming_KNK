#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *tmp, *c_locale;

    tmp = setlocale(LC_ALL, NULL);
    c_locale = malloc(strlen(tmp) + 1);
    strcpy(c_locale, tmp);
    tmp = setlocale(LC_ALL, "");

    if (strcmp(tmp, c_locale) == 0)
    {
        printf("native locale is the same as the C locale.\n");
    }
    else
    {
        printf("native locale is not the same as the C locale.\n");
    }

    return 0;
}
