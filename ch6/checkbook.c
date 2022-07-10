#include <stdio.h>

#define CLEAR (0)
#define CREDIT (1)
#define DEBIT (2)
#define BALANCE (3)
#define EXIT (4)

int main(void)
{
    int user_command;
    float credit, debit, balance;

    printf("*** ACME checkbook-balancing program ***\n");
    printf("Command: 0 = clear, 1 = credit, 2 = debit, 3 = balance, 4 = exit\n");

    while (1)
    {
        printf("Enter command: ");
        scanf("%d", &user_command);

        switch (user_command)
        {
        case CLEAR:
            balance = 0;
            break;
        case CREDIT:
            printf("Enter amount of credit: ");
            scanf("%f", &credit);
            balance += credit;
            break;
        case DEBIT:
            printf("Enter amount of debit: ");
            scanf("%f", &debit);
            balance -= debit;
            break;
        case BALANCE:
            printf("Current balance: $%.2f\n", balance);
            break;
        case EXIT:
            return 0;
        default:
            printf("Command: 0 = clear, 1 = credit, 2 = debit, 3 = balance, 4 = exit\n");
            break;
        }
    }
}