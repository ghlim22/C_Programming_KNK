#include <stdio.h>

int main(void)
{
    int i, j;
    float x;

    printf("enter number");
    scanf("%d- %f- %d", &i, &x, &j);
    printf("%d -%.3f -%d", i, x, j);

    return 0;
}