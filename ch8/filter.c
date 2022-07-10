#include <stdio.h>
#include <string.h>

int main(void)
{
    char inputs[20] = {0}, temp;
    int count = 0;
    printf("Enter message: ");
    do
    {
        scanf("%c", &temp);
        inputs[count] = temp;
        count++;
    } while (temp != '\n');

    for (int i = 0; i < 20; ++i)
    {
        if (inputs[i] >= 'a' && inputs[i] <= 'z')
        {
            inputs[i] -= 32;
        }

        switch (inputs[i])
        {
        case 'A':
            inputs[i] = '4';
            break;
        case 'B':
            inputs[i] = '8';
            break;
        case 'E':
            inputs[i] = '3';
            break;
        case 'I':
            inputs[i] = '1';
            break;
        case 'O':
            inputs[i] = '0';
            break;
        case 'S':
            inputs[i] = '5';
            break;
        default:
            break;
        }

        if (inputs[i] >= 'A' && inputs[i] <= 'Z' || inputs[i] >= '0' && inputs[i] <= '9')
        {
            printf("%c", inputs[i]);
        }
    }

    for (int i = 0; i < 10; ++i)
    {
        printf("!");
    }

    printf("\n");

    return 0;
}