#include <stdio.h>

int main(void)
{
    char op;
    float num1, num2, temp;
    printf("Enter an expression: ");
    scanf("%f", &num1);
    op = getchar();
    scanf("%f", &num2);

    switch (op)
    {
    case '+':
        temp = num1 + num2;
        break;
    case '-':
        temp = num1 - num2;
        break;
    case '*':
        temp = num1 * num2;
        break;
    case '/':
        temp = num1 / num2;
        break;
    default:
        break;
    }

    while ((op = getchar()) != '\n')
    {
        scanf("%f", &num1);
        switch (op)
        {
        case '+':
            temp += num1;
            break;
        case '-':
            temp -= num1;
            break;
        case '*':
            temp *= num1;
            break;
        case '/':
            temp /= num1;
            break;
        default:
            break;
        }
    }

    printf("Value of expression: %.2f\n", temp);

    return 0;
}