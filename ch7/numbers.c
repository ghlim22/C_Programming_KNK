#include <stdio.h>

int main(void)
{
    long int lk;
    unsigned int num;
    long double num2;
    double num3;

    printf("Enter long int number: ");
    scanf("%ld", &lk);
    printf("%ld\n", lk);
    printf("Enter hexa num: ");
    scanf("%x", &num);
    printf("%x\n", num);
    printf("Enter octal num: ");
    scanf("%o", &num);
    printf("%o\n", num);
    printf("enter double num: ");
    scanf("%lf", &num3);
    printf("%f\n", num3);
    printf("enter long double num: ");
    scanf("%Lf", &num2);
    printf("%Lf\n", num2);

    return 0;
}