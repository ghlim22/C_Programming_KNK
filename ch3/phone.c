#include <stdio.h>

int main(void)
{
    int first, second, third;
    printf("enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d)%d-%d", &first, &second, &third);
    printf("%d.%d.%d", first, second, third);

    return 0;
}