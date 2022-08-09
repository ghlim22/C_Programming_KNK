#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *str1, const char *str2)
{
    char *result;

    result = malloc(strlen(str1) + strlen(str2) + 1);

    if (result == NULL)
    {
        printf("Error: malloc failed in concat.\n");
        return NULL;
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

void f(void)
{
    static int i = 0;
    i++;
    printf("%d\n", i);
}

int main(void)
{
    for (int i = 0; i < 10; ++i)
    {
        f();
    }
    return 0;
}