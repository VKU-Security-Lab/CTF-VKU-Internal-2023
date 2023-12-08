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
    printf("\n======== Menu ========\n");
    printf("1. Store\n");
    printf("2. Your cash\n");
    printf("3. Exit\n");
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

    printf("|----------------------------------------------|\n");
    printf("| ID ---------- Product   ----------     Price |\n");
    printf("|----------------------------------------------|\n");
    printf("|  1 ---------- Shirt     ----------       10$ |\n");
    printf("|  2 ---------- Trousers  ----------       15$ |\n");
    printf("|  3 ---------- Flag      ----------  1000000$ |\n");
    printf("|----------------------------------------------|\n");

    printf("1. Buy\n");
    printf("2. Back to menu\n");
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
                printf("Invalid id\n");
                break;
            }

            switch (id)
            {
            case 1:
                printf("Enter amount: ");
                fflush(stdout);

                if (scanf("%d", &amount) != 1)
                {
                    printf("Invalid amount\n");
                    break;
                }
                if (check_money(10 * amount))
                {
                    printf("You bought %d shirts\n", amount);
                    money -= 10 * amount;
                }
                else
                {
                    printf("You don't have enough money\n");
                }
                break;
            case 2:
                printf("Enter amount: ");
                fflush(stdout);

                if (scanf("%d", &amount) != 1)
                {
                    printf("Invalid amount\n");
                    break;
                }
                if (check_money(15 * amount))
                {
                    printf("You bought %d trousers\n", amount);
                    money -= 15 * amount;
                }
                else
                {
                    printf("You don't have enough money\n");
                }
                break;
            case 3:
                if (check_money(1000000))
                {
                    money -= 1000000;
                    printf("Congratulation, here is your flag: ");
                    FILE *file;
                    long long number;
                    file = fopen("flag.txt", "r");
                    char flag[100];

                    if (file == NULL)
                    {
                        printf("Cannot open file 'flag.txt', contact admin\n");
                        fflush(stdout);
                        return;
                    }
                    fgets(flag, 100, file);
                    puts(flag);
                }
                else
                {
                    printf("You don't have enough money\n");
                }
                break;
            default:
                printf("Invalid choice\n");
                break;
            }
            break;
        case 2:
            break;
        default:
            printf("Invalid choice\n");
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
            printf("Invalid option\n");
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
            printf("Bye bye, see you again\n");
            break;
        }
        else
        {
            printf("Invalid choice\n");
        }
    }
}

int main()
{
    printf("\n==================== Welcome to My Store ====================\n");
    printf("\n[!] You can buy anything you want in this store. Please feel \nas comfortable as possible. Have a gud day =)))\n\n");
    check_cash();

    bank_money();
    return 0;
}
