#include <stdio.h>

int gcd(int m, int n);

int main(void)
{
    printf("%d", gcd(50, 14));
}

float compute_GPA(char grades[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; ++i)
    {
        switch (grades[i])
        {
        case 'A':
        case 'a':
            sum += 4;
            break;
        case 'B':
        case 'b':
            sum += 3;
            break;
        case 'C':
        case 'c':
            sum += 2;
            break;
        case 'D':
        case 'd':
            sum += 1;
            break;
        default:
            break;
        }
    }

    return sum / n;
}

double inner_production(double a[], double b[], int n)
{
    double sum = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            sum += a[i] * b[j];
        }
    }

    return sum;
}

int evaluate_position(char board[8][8])
{
    int white_point = 0, black_point = 0;

    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            switch (board[i][j])
            {
            case 'Q':
                white_point += 9;
                break;
            case 'R':
                white_point += 5;
                break;
            case 'B':
            case 'N':
                white_point += 3;
                break;
            case 'P':
                white_point += 1;
                break;
            case 'q':
                black_point += 9;
                break;
            case 'r':
                black_point += 5;
                break;
            case 'b':
            case 'n':
                black_point += 3;
                break;
            case 'p':
                black_point += 1;
                break;
            default:
                break;
            }
        }
    }

    return white_point - black_point;
}

double median(double x, double y, double z)
{
    int temp;

    if (x <= y)
    {
        if (y <= z)
        {
            temp = y;
        }
        else if (x <= z)
        {
            temp = z;
        }
        else
        {
            temp = x;
        }
    }
    else if (z <= y)
    {
        temp = y;
    }
    else if (x <= z)
    {
        temp = x;
    }

    return temp;
}

int fact(int num)
{
    int n = 1;
    for (int i = 2; i <= num; ++i)
    {
        n *= i;
    }

    return n;
}

int gcd(int m, int n)
{
    if (n == 0)
    {
        return m;
    }
    else
    {
        return gcd(n, m % n);
    }
}
