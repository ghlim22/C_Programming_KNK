#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int evaluate_RPN_expression(Stack s, const char *expression)
{
    while (1)
    {
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
    Stack s = create();
    while (1)
    {
        printf("Enter an RPN expression: ");
        while (1)
        {
            scanf(" %c", &ch);
            if (ch >= '0' && ch <= '9')
            {
                int num = atoi(&ch);
                push(s, num);
            }
            else
            {
                switch (ch)
                {
                case '+':
                    a = pop(s);
                    b = pop(s);
                    result = a + b;
                    push(s, result);
                    break;
                case '-':
                    a = pop(s);
                    b = pop(s);
                    result = b - a;
                    push(s, result);
                    break;
                case '*':
                    a = pop(s);
                    b = pop(s);
                    result = b * a;
                    push(s, result);
                    break;
                case '/':
                    a = pop(s);
                    b = pop(s);
                    result = b / a;
                    push(s, result);
                    break;
                case '=':
                    a = pop(s);
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
