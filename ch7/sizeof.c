#include <stdio.h>

int main(void)
{
    printf("size of int: %u\n", (unsigned int)sizeof(int));
    printf("size of short: %u\n", (unsigned int)sizeof(short));
    printf("size of long: %lu\n", (unsigned long)sizeof(long));
    printf("size of float: %u\n", (unsigned int)sizeof(float));
    printf("size of double: %lu\n", (unsigned long)sizeof(double));

    return 0;
}