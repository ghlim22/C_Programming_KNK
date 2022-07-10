#include <stdio.h>
#include <stdbool.h>

int gcd(int m, int n);
int day_of_year(int month, int day, int year);
int num_digits(int n);
int digit(int n, int k);
int large(int arr[], int n);
double GetAverage(int arr[], int n);
int GetPositiveCount(int arr[], int n);

int main(void)
{
    int m, n, month, day, year;
    /*
    printf("Enter two numbers: ");
    scanf("%d%d", &m, &n);
    printf("The greatest common divisor is %d.\n", gcd(m, n));

    printf("Enter month/day/year: ");
    scanf("%d/%d/%d", &month, &day, &year);
    printf("Days of year: %d\n", day_of_year(month, day, year));


    printf("Enter a number and digit: ");
    scanf("%d%d", &m, &n);
    printf("The %dth digit of %d: %d\n", n, m, digit(m, n));
    */

    int arr[10] = {6, -12, 99, 42, 43, 103, -5, 80, 2, -1};
    printf("Large: %d\nAverage: %.2f\nPositive: %d\n", large(arr, 10), GetAverage(arr, 10), GetPositiveCount(arr, 10));

    return 0;
}

int gcd(int m, int n)
{
    int remainder;
    while (n != 0)
    {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    return m;
}

int day_of_year(int month, int day, int year)
{
    int total_days = 0;
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap = (year % 4 == 0) ^ (year % 100 == 0) ^ (year % 400 == 0);

    if (month > 2 && isLeap)
    {
        total_days++;
    }

    for (int i = 0; i < month - 1; ++i)
    {
        total_days += days[i];
    }

    total_days += day;

    return total_days;
}

int num_digits(int n)
{
    int digits = 0;
    while (n != 0)
    {
        n /= 10;
        digits++;
    }

    return digits;
}

int digit(int n, int k)
{
    int res;
    if (k > num_digits(n) || k <= 0)
    {
        return 0;
    }

    while (k-- != 0)
    {
        res = n % 10;
        n /= 10;
    }

    return res;
}

int large(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 0; i < n; ++i)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
    }

    return largest;
}

double GetAverage(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += arr[i];
    }

    return sum / (double)n;
}

int GetPositiveCount(int arr[], int n)
{
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > 0)
        {
            count++;
        }
    }

    return count;
}