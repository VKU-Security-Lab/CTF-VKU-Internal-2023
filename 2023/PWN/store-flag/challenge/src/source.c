#include <stdio.h>

long long money = 30;

int check_money(int price)
{
    if (money >= price)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void check_cash()
{
    printf("==============================\n");
    printf("Here is your cash: %lld\n", money);
    printf("==============================\n");
}

void menu()
{
    puts("\n======== Menu ========\n");
    puts("1. Store\n");
    puts("2. Your cash\n");
    puts("3. Exit\n");
    printf("Your choice: ");
    fflush(stdout);
}

void store()
{
    int choice;
    printf("\n==================================\n");
    printf("This is our store's product table");
    printf("\n==================================\n");

    printf("Your cash: %lld\n", money);

    printf("|-----------------------------------------------------|\n");
    printf("| ID ---------- Product          ----------     Price |\n");
    printf("|-----------------------------------------------------|\n");
    printf("|  1 ---------- Christmas star   ----------       10$ |\n");
    printf("|  2 ---------- Christmas socks  ----------       15$ |\n");
    printf("|  3 ---------- Flag             ----------  1000000$ |\n");
    printf("|-----------------------------------------------------|\n");

    puts("1. Buy\n");
    puts("2. Back to menu\n");
    printf("Your choice: ");
    fflush(stdout);

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid option\n");
    }else{
        int amount;

        switch (choice)
        {
        case 1:
            printf("Enter your product id: ");
            fflush(stdout);

            int id;

            if (scanf("%d", &id) != 1)
            {
                puts("Invalid id\n");
                break;
            }

            switch (id)
            {
            case 1:
                printf("Enter amount: ");
                fflush(stdout);

                if (scanf("%d", &amount) != 1)
                {
                    puts("Invalid amount\n");
                    break;
                }
                if (check_money(10 * amount))
                {
                    printf("You bought %d Star\n", amount);
                    money -= 10 * amount;
                }
                else
                {
                    puts("You don't have enough money\n");
                }
                break;
            case 2:
                printf("Enter amount: ");
                fflush(stdout);

                if (scanf("%d", &amount) != 1)
                {
                    puts("Invalid amount\n");
                    break;
                }
                if (check_money(15 * amount))
                {
                    printf("You bought %d Socks\n", amount);
                    money -= 15 * amount;
                }
                else
                {
                    puts("You don't have enough money\n");
                }
                break;
            case 3:
                if (check_money(1000000))
                {
                    money -= 1000000;
                    puts("Congratulation. Merry Christmas, here is your flag: ");
                    FILE *file;
                    long long number;
                    file = fopen("/flag.txt", "r");
                    char flag[100];

                    if (file == NULL)
                    {
                        puts("Cannot open file 'flag.txt', contact admin\n");
                        fflush(stdout);
                        return;
                    }
                    fgets(flag, 100, file);
                    puts(flag);
                }
                else
                {
                    puts("You don't have enough money\n");
                }
                break;
            default:
                puts("Invalid choice\n");
                break;
            }
            break;
        case 2:
            break;
        default:
            puts("Invalid choice\n");
            break;
        }
    }
}

void bank_money()
{
    int choice;
    while (1)
    {
        menu();
        fflush(stdin);
        if (scanf("%d", &choice) != 1)
        {
            puts("Invalid option\n");
            continue;
        }

        if (choice == 1)
        {
            store();
        }
        else if (choice == 2)
        {
            check_cash();
        }
        else if (choice == 3)
        {
            puts("Bye bye, see you again\n");
            break;
        }
        else
        {
            puts("Invalid choice\n");
        }
    }
}

int main()
{
    puts("\n==================== Welcome to My Christmas Store ====================\n");
    puts("\nMerry Christmas and Happy New Year to you all. I'm Santa Claus. \nI'm here to give you a gift. You can buy anything you want in this \nstore. Please feel as comfortable as possible. Have a gud day =)))\n\n");
    check_cash();

    bank_money();
    return 0;
}
