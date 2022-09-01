#include <stdio.h>
#include <stdlib.h>

void foo1(void)
{
    printf("That's all, ");
}

void foo2(void)
{
    printf("folks!");
}

int main(void)
{
    atexit(foo2);
    atexit(foo1);

    return 0;
}