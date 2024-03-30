#include<stdio.h>
#include<string.h>

int main(){
    int c = 0;
    char str[100];
    char strnew[100] = "";
    char* ptr;
    scanf(" ");
    fgets(str, 100, stdin);
    ptr = strtok(str, ", ");
    while(ptr != NULL){
        if(strcmp(ptr, "is") == 0){
            strcat(strnew, "was");
        }
        else{
            strcat(strnew, ptr);
        }
        strcat(strnew, " ");
        ptr = strtok(NULL, ", ");
        c++;

    }
    printf("%d\n", c);
    printf("%s\n", strnew);
    return 0;
}
