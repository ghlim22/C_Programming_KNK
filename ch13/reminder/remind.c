#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "readline.h"

#define MAX_REMIND (50)
#define MSG_LEN (60)

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[22], msg_str[MSG_LEN + 1];
    int month, day, hour, min, i, j, num_remind = 0;

    FILE *output = fopen("output.txt", "a");

    while (1)
    {
        if (num_remind == MAX_REMIND)
        {
            printf("no space left\n");
            break;
        }

        printf("Enter reminder(\'mm/dd hh:mm message\'): ");
        scanf("%2d/ %2d", &month, &day);
        if (day == 0 || month == 0)
        {
            break;
        }
        if (day > 31 || day < 0)
        {
            printf("wrong date.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        scanf(" %2d: %2d", &hour, &min);
        sprintf(day_str, "%4.2d%4.2d%2.2d:%2.2d ", month, day, hour, min);

        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; ++i)
        {
            if (strcmp(day_str, reminders[i]) < 0)
            {
                break;
            }
        }
        for (j = num_remind; j > i; --j)
        {
            strcpy(reminders[j], reminders[j - 1]);
        }

        strcpy(reminders[i], day_str);
        strcpy(reminders[i], msg_str);

        num_remind++;
    }

    printf("\nMonth Day Time Reminder\n");
    for (i = 0; i < num_remind; ++i)
    {
        printf(" %s\n", reminders[i]);
        fprintf(output, " %s\n", reminders[i]);
    }

    fclose(output);

    return 0;
}
