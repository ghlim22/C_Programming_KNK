#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define STACK_SIZE (100)

int g_contents[STACK_SIZE];
int g_top = 0;

int evaluate_RPN_expression(const char *expression)
{
    while (1)
    {
        int result, a, b;
        char ch = *expression;
        if (ch >= '0' && ch <= '9')
        {
            int num = atoi(&ch);
            push(num);
        }
        else
        {
            switch (ch)
            {
            case '+':
                a = pop();
                b = pop();
                result = a + b;
                push(result);
                break;
            case '-':
                a = pop();
                b = pop();
                result = b - a;
                push(result);
                break;
            case '*':
                a = pop();
                b = pop();
                result = b * a;
                push(result);
                break;
            case '/':
                a = pop();
                b = pop();
                result = b / a;
                push(result);
                break;
            case '=':
                a = pop();
                printf("%d\n", a);
                break;
            default:
                return 0;
            }
        }
    }
    return pop();
}

int main(void)
{
    char ch;
    int a, b, result;
    while (1)
    {
        printf("Enter an RPN expression: ");
        while (1)
        {
            scanf(" %c", &ch);
            if (ch >= '0' && ch <= '9')
            {
                int num = atoi(&ch);
                push(num);
            }
            else
            {
                switch (ch)
                {
                case '+':
                    a = pop();
                    b = pop();
                    result = a + b;
                    push(result);
                    break;
                case '-':
                    a = pop();
                    b = pop();
                    result = b - a;
                    push(result);
                    break;
                case '*':
                    a = pop();
                    b = pop();
                    result = b * a;
                    push(result);
                    break;
                case '/':
                    a = pop();
                    b = pop();
                    result = b / a;
                    push(result);
                    break;
                case '=':
                    a = pop();
                    printf("%d\n", a);
                    break;
                default:
                    return 0;
                }
            }
        }
    }

    return 0;
}
