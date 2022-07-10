#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, min, total_min, departure, arrival;
    char *departure_noon, *arrival_noon;
    char noon;

    int departure_times[] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int arrival_times[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
    printf("Enter a 12-hour time: ");
    scanf("%d:%d %c", &hour, &min, &noon);

    if (noon == 'P' || noon == 'p')
    {
        if (hour != 12)
        {
            hour += 12;
        }
    }

    total_min = hour * 60 + min;
    /*
    if (total_min <= 480)
    {
        departure = 480;
        arrival = 616;
    }
    else if (total_min <= 583)
    {
        departure = 583;
        arrival = 712;
    }
    else if (total_min <= 679)
    {
        departure = 679;
        arrival = 811;
    }
    else if (total_min <= 767)
    {
        departure = 767;
        arrival = 900;
    }
    else if (total_min <= 840)
    {
        departure = 840;
        arrival = 968;
    }
    else if (total_min <= 945)
    {
        departure = 945;
        arrival = 1075;
    }
    else if (total_min <= 1140)
    {
        departure = 1140;
        arrival = 1280;
    }
    else if (total_min <= 1305)
    {
        departure = 1305;
        arrival = 1438;
    }
    else
    {
        departure = 480;
        arrival = 616;
    }
    */
    int index, difference = 1000;
    for (int i = 0; i < 8; ++i)
    {
        if (total_min > 1305)
        {
            index = 0;
            break;
        }
        if (departure_times[i] - total_min > 0 && departure_times[i] - total_min < difference)
        {
            index = i;
            difference = departure_times[i] - total_min;
        }
    }
    departure = departure_times[index];
    arrival = arrival_times[index];

    int departure_hour = departure / 60;
    int departure_min = departure % 60;
    if (departure_hour >= 12)
    {
        departure_noon = "p.m.";
        if (departure_hour != 12)
        {
            departure_hour -= 12;
        }
    }
    else
    {
        departure_noon = "a.m.";
    }

    int arrival_hour = arrival / 60;
    int arrival_min = arrival % 60;
    if (arrival_hour >= 12)
    {
        arrival_noon = "p.m.";
        if (arrival_hour != 12)
        {
            arrival_hour -= 12;
        }
    }
    else
    {
        arrival_noon = "a.m.";
    }

    printf("Closest departure time is %d:%.2d %s, arriving at %d:%.2d %s\n", departure_hour, departure_min, departure_noon, arrival_hour, arrival_min, arrival_noon);

    return 0;
}
