#include <stdio.h>

int main()
{
    FILE *file;
    long long number;
    file = fopen("flag.txt", "r");
    char flag[100]; 

    if (file == NULL)
    {
        printf("Cannot open file 'flag.txt'\n");
        fflush(stdout);
        return 1;
    }

    printf("Enter your number: ");
    fflush(stdout); 

    if(scanf("%lld", &number) != 1)
    {
        printf("Please enter a number!!\n");
        return 1;
    }

    if (number < 0)
    {
        printf("Please enter a number greater than 0!!\n");
        return 1;
    }

    printf("Your number: %d\n", (int)number);

    if ((int)number == -10172023)
    {
        printf("Congratulations, you are the best hacker I know\n");
        printf("Here is your flag: ");
        fflush(stdout);

        fgets(flag, 100, file);
        puts(flag);
    }
    else
    {
        printf("Noo :(, try again\n");
    }

    fclose(file);

    return 0;
}