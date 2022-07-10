#include <stdio.h>
#include <string.h>
#include <ctype.h>

int GetGCD(int m, int n);

int main(void)
{
    int num1, denom1, num2, denom2, result_num, result_denom;
    char operator;
    printf("Enter num1: ");
    scanf("%d/%d", &num1, &denom1);
    printf("Enter num2: ");
    scanf("%d/%d", &num2, &denom2);

    printf("Enter the operator: ");
    scanf(" %c", &operator);

    switch (operator)
    {
    case '+':
        result_num = num1 * denom2 + num2 * denom1;
        result_denom = denom1 * denom2;
        break;
    case '-':
        result_num = num1 * denom2 - num2 * denom1;
        result_denom = denom1 * denom2;
        break;
    case '*':
        result_num = num1 * num2;
        result_denom = denom1 * denom2;
        break;
    case '/':
        result_num = num1 * denom2;
        result_denom = num2 * denom1;
        break;
    default:
        break;
    }
    int m = GetGCD(result_num, result_denom);
    printf("The result is %d/%d\n", result_num / m, result_denom / m);

    return 0;
}

int GetGCD(int m, int n)
{
    while (n != 0)
    {
        int temp = m % n;
        m = n;
        n = temp;
    }

    return m;
}