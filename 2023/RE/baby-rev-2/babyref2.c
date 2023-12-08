#include <stdio.h>
#include <string.h>

char *midFlag = "b4by_r3v3rs1ng_1s_3a5";

int main()
{
    char input[100];

    printf("Enter key: ");
    fgets(input, sizeof(input), stdin);

    int length = strlen(input);

    if (length > 0 && input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
        length--;
    }

    if (length != 32)
    {
        printf("Incorrect key!\n");
        return -1;
    }

    char str[5]; 
    strncpy(str, input, 4);
    str[4] = '\0';

    if (strcmp(str, "VKU{")) {
        printf("Incorrect key!\n");
        return -1;
    }
    if (input[31] != '}')
    {
        printf("Incorrect key!\n");
        return -1;
    }

    char str2[22];
    strncpy(str2, input+4, 21);
    str2[21] = '\0';
    if (strcmp(str2, midFlag))
    {
        printf("Incorrect key!\n");
        return -1;
    }

    if ((int)input[25] != 121 || (int)input[26] != 95 || (int)input[27] != 72 || (int)input[28] != 51 || (int)input[29] != 104 || (int)input[28] != 51) {
        printf("Incorrect key!\n");
        return -1;
    }
    printf("Correct key!\n");
    printf("Flag: %s\n", input);
    return 0;
}