#include <stdio.h>

int main()
{
    FILE *file;
    long long number;
    char flag[100];

    puts("Merry Christmas! Choose a lucky number for Santa to give you a gift.");
    printf("Enter your lucky number: ");
    fflush(stdout); 

    if(scanf("%lld", &number) != 1)
    {
        puts("Please enter a number!!");
        fflush(stdout);
        return 1;
    }

    if (number < 0)
    {
        puts("Please enter a number greater than 0!!\n");
        fflush(stdout);
        return 1;
    }

    printf("Your number: %d\n", (int)number);
    fflush(stdout);

    if ((int)number == -25122023)
    {
        puts("Congratulations!!!.\n You are truly a talented hacker. Santa Claus gives you a special gift.");
        printf("Here is your flag: ");
        fflush(stdout);

        file = fopen("flag.txt", "r");

        if (file == NULL)
        {
            puts("Cannot open file 'flag.txt' (Exploit directly on the server. Or contact the admin)");
            fflush(stdout);
            return 1;
        }

        fgets(flag, 100, file);
        puts(flag);
        fclose(file);
    }
    else
    {
        puts("Noooo :( You are so unlucky. Let's try again!!");
        fflush(stdout);
    }

    return 0;
}