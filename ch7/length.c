#include <stdio.h>

typedef int8_t Int8;
typedef int16_t Int16;
typedef int32_t Int32;

int main(void)
{
    int counter = 0;
    printf("Enter a message: ");

    while (getchar() != '\n')
    {
        counter++;
    }

    printf("Your message was %d character(s) long.", counter);

    unsigned long size = (unsigned long)sizeof(long);
    printf("%zu\n", size);

    return 0;
}