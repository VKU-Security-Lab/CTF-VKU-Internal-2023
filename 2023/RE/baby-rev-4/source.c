#include <stdio.h>

void encrypt(char *flag, int len)
{
    for (int i = 0; i < len; i++)
    {
        flag[i] = (int)flag[i] ^ 0x10;
    }
}

int main()
{
    FILE *fileFlag = fopen("flag.txt", "r+");

    if (fileFlag == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char flag[33];
    fgets(flag, 33, fileFlag);
    encrypt(flag, 33);

    fseek(fileFlag, 0, SEEK_SET);

    for (int i = 0; i < 32; i++)
    {
        fprintf(fileFlag, "%d ", (int)flag[i]);
    }

    fclose(fileFlag);
    return 0;
}
