#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER (100)

void initialize_number_generator(void);
int choose_new_secret_number(void);
void read_guesses(int answer);

int main(void)
{
    char command;
    printf("Guess the secret number between 1 and 100.\n");

    do
    {
        initialize_number_generator();
        int secret_num = choose_new_secret_number();
        printf("A new number has been chosen.\n");

        read_guesses(secret_num);

        printf("Play again? (Y/N)\n");
        scanf(" %c", &command);
        printf("\n");
    } while ((command == 'y') || (command == 'Y'));

    return 0;
}

void initialize_number_generator(void)
{
    srand((unsigned int)time(0));
}

int choose_new_secret_number(void)
{
    return rand() % MAX_NUMBER + 1;
}

void read_guesses(int answer)
{
    int guess;
    int cnt = 0;
    while (1)
    {
        printf("Enter guess: ");
        scanf("%d", &guess);
        if (guess > answer)
        {
            printf("Too high; try again.\n");
        }
        else if (guess < answer)
        {
            printf("Too low; try again.\n");
        }
        else
        {
            cnt++;
            printf("You won in %d guesses!\n", cnt);
            return;
        }
        cnt++;
    }
}
