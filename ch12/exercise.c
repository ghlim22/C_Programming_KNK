#include <stdio.h>
#include <stdbool.h>

#define LEN (10)

void print_array(int a[], int n)
{
    int *p;
    for (p = &a[0]; p < p + n; ++p)
    {
        printf("%d ", *p);
    }
    printf("\n");
}

int sum_array(int a[], int n)
{
    int sum = 0;
    int *p;
    for (p = &a[0]; p < p + n; ++p)
    {
        sum += *p;
    }

    return sum;
}

bool search(const int a[], int n, int key)
{
    int *p;
    for (p = &a[0]; p < p + n; ++p)
    {
        if (*p == key)
            return true;
    }
    return false;
}

void store_zeros(int a[], int n)
{
    int *p;
    for (p = a; p < p + n; ++p)
    {
        *p = 0;
    }
}

double inner_product(const double *a, const double *b, int n)
{
    int sum = 0, *p, *q;
    for (p = a, q = a; p < p + n; ++p, ++q)
    {
        sum += (*p) * (*q);
    }
    return sum;
}

int *find_middle(int a[], int n)
{
    return *(a + n / 2);
}

void find_two_largest(const int *a, int n, int *largest, int *second_largest)
{
    int *p, lar, lar2;
    p = a;
    lar = *p;
    lar2 = *p;

    for (p = p + 1; p < p + n; ++p)
    {
        if (*p > lar)
        {
            lar2 = lar;
            lar = *p
        }
        else if (*p > lar2)
        {
            lar2 = *p;
        }
    }

    *largest = lar;
    *second_largest = lar2;
}

void indentity(int n, int arr[n][n])
{
    int *p = &arr[0][0];
    int cnt_zero = n;
    while (p++ < arr[0] + n * n)
    {
        if (cnt_zero == n)
        {
            *p = 1;
            cnt_zero = 0;
        }
        else
        {
            *p = 0;
            cnt_zero++;
        }
    }
}

void print_temperature_col(int tem[7][24], int i)
{
    int *p;
    for (p = tem[i]; p < tem[i] + 24; ++p)
    {
        printf("%d ", *p);
    }
}

int sum_two_dimensional_array(const int a[][LEN], int n)
{
    int sum = 0;
    const int *p;
    for (p = &a[0][0]; p < p + n * LEN; ++p)
    {
        sum += *p;
    }
    return sum;
}

int evaluate_position(char board[8][8])
{
    int white_point = 0, black_point = 0;
    char(*p)[8];
    char *q;

    for (p = &board[0][0]; p < board + 64; ++p)
    {
        switch (*q)
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

    return white_point - black_point;
}

int main(void)
{
    int arr[10];
    for (int *p = arr, i = 0; p < p + 10; ++p, ++i)
    {
        *p = i;
    }
    print_array(arr, 10);
    printf("sum: %d\n", sum_array(arr, 10));

    int temperatures[7][24];
    search(temperatures[0], 7 * 24, 32);

    return 0;
}