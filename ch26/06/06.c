#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t current = time(NULL);
    char date_time[30];
    strftime(date_time, sizeof(date_time), "%A, %B %d, %Y %I:%M %p\n", localtime(&current));
    printf("%s", date_time);
    return 0;
}