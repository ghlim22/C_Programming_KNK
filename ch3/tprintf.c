#include <stdio.h>

int main(void)
{
    int i;
    float x;

    i = 40;
    x = 14.23;

    printf("|%d|%5d|%-5d|%5.3d|\n", i, i, i, i);
    printf("|%10.3f|%10.3e|%-10g|\n", x, x, x);
    printf("\a");

    printf("Enter the number: ");
    scanf("%d/%f", &i, &x);

    printf("%d\n%f", i, x);

    return 0;
}