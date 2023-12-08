#include<stdio.h>

int main(int argc, char *argv[])
{
    char role[5] = "user";
    char name[20];
    
    puts("What's your name?");
    fflush(stdout);
    gets(name);
    printf("You are %s!\n", role);
    fflush(stdout);
    
    if (strcmp(role, "admin") == 0)
    {
        puts("Congratulation, here is your flag (If you can see the flag, run it on server):");
        fflush(stdout);
        system("cat /flag.txt");
        fflush(stdout);
    }
    else
    {
        printf("Hello, %s!\n", name);
        fflush(stdout);
    }
    return 0;
}