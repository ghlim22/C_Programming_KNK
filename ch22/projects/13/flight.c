#include <stdio.h>
#include <ctype.h>

#define TIME_NUM (8)

int main(int argc, char *argv[])
{
    int hour, min, total_min, departure, arrival;
    char *departure_noon, *arrival_noon;
    char noon;
    FILE *fp;
    const int departure_times[] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    const int arrival_times[] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    if (argc != 2)
    {
        return 1;
    }

    if ((fp = fopen(argv[1], "w")) == NULL)
    {
        return 2;
    }

    for (int i = 0; i < TIME_NUM; ++i)
    {
        departure = departure_times[i];
        arrival = arrival_times[i];
        int departure_hour = departure / 60;
        int departure_min = departure % 60;
        int arrival_hour = arrival / 60;
        int arrival_min = arrival % 60;

        if (fprintf(fp, "%d:%d  %d:%d\n", departure_hour, departure_min, arrival_hour, arrival_min) <= 0)
        {
            fprintf(stderr, "error: writing error\n");
            return 3;
        }
    }

    fclose(fp);

    return 0;
}
