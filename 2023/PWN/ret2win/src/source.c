#include <stdio.h>
#include <stdlib.h>

void hacked()
{
    printf("You win! Here is your flag\n");
    fflush(stdout);
    system("/usr/bin/cat /flag.txt");
}

void hello()
{
    char buffer[24];

    printf("Enter your name:\n");
    fflush(stdout);
    scanf("%s", buffer);
    printf("Hi, %s\n", buffer);
    fflush(stdout);
}

int main()
{
    hello();
    return 0;
}