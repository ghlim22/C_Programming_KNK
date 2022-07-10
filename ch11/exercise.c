#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year)
{
    bool is4 = false;
    bool is100 = false;
    bool is400 = false;

    if ((year % 4) == 0)
    {
        is4 = true;
        if ((year % 100) == 0)
        {
            is100 = true;
            if ((year % 400) == 0)
            {
                is400 = true;
            }
        }
    }

    return is4 ^ is100 ^ is400;
}

void split_time(long total_sec, int *hr, int *min, int *sec)
{
    *hr = total_sec / 3600;
    *min = total_sec % 3600 / 60;
    *sec = total_sec % 3600 % 60;
}

void find_two_largest(int a[], int n, int *out_largest, int *out_second_largest)
{
    if (out_largest == NULL || out_second_largest == NULL)
    {
        return;
    }

    int lar = a[0];
    int second_lar = a[0];

    for (int i = 1; i < n; ++i)
    {
        if (a[i] >= lar)
        {
            second_lar = lar;
            lar = a[i];
        }
        else if (a[i] > second_lar)
        {
            second_lar = a[i];
        }
    }

    *out_largest = lar;
    *out_second_largest = second_lar;
}

void split_date(int day_of_year, int year, int *out_month, int *out_day)
{
    int day_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year))
    {
        day_of_month[1]++;
    }

    int i;
    for (i = 0; i < 11; ++i)
    {
        if (day_of_year < day_of_month[i])
        {
            break;
        }
        day_of_year -= day_of_month[i];
    }
    *out_month = i + 1;
    *out_day = day_of_year;
}

void pay_amount(int dollars, int *out_twenties, int *out_tens, int *out_fives, int *out_ones)
{
    *out_twenties = dollars / 20;
    *out_tens = dollars % 20 / 10;
    *out_fives = dollars % 20 % 10 / 5;
    *out_ones = dollars % 20 % 10 % 5;
}

void find_closest_flight(int desired_time, int *out_departure_time, int *out_arrival_time)
{
    int departure_times[] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int arrival_times[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
    int index, difference = 10000;
    for (int i = 0; i < 8; ++i)
    {
        if (desired_time > 1305)
        {
            index = 0;
            break;
        }

        if (departure_times[i] - desired_time >= 0)
        {
            if (difference >= departure_times[i] - desired_time)
            {
                index = i;
                difference = departure_times[i] - desired_time;
            }
        }
    }

    *out_departure_time = departure_times[index];
    *out_arrival_time = arrival_times[index];
}

void reduce(int numerator, int denominator, int *out_reduced_numerator, int *out_reduced_denominator)
{
    int divisor;
    int m = numerator;
    int n = denominator;
    while (n != 0)
    {
        int temp = m % n;
        m = n;
        n = temp;
    }
    divisor = m;

    *out_reduced_numerator = numerator / divisor;
    *out_reduced_denominator = denominator / divisor;
}

int main(void)
{
    int month;
    int day;
    split_date(102, 2022, &month, &day);
    printf("%d %d\n", month, day);

    return 0;
}