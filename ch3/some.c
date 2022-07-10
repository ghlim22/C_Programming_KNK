#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *list = malloc(sizeof(int));
    printf("%lu", sizeof(int));
    free(list);

    return 0;
}