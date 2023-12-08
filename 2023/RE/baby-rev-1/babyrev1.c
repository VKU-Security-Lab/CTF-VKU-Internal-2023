#include<stdio.h>
#include<string.h>

int main(){
    char *flag = "VKU{r3verse?_1ts_50_345y_r1ght?}";
    char input[101];
    printf("Enter flag: ");
    scanf("%100s", input);
    if (strcmp(flag, input) == 0){
        printf("Correct!\n");
    } else {
        printf("Incorrect key, try again!\n");
    }
    return 0;
}