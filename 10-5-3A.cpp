#include<stdio.h>
#include<string.h>

int main(){
    char s1[80] = "      Turbo   c       ", s2[80] = "\0";
    int i, j = 0;
    for(i = 0; i < strlen(s1); i++){
        if(s1[i] != ' ' && j == 0){
            j = i;
        }
        if(j > 0){
            s2[i - j] = s1[i];
        }
    }

    for(i = strlen(s2) - 1; i >= 0; i--){
        if(s2[i] != ' ')
           break;
    }
    s2[i + 1] = '\0';
    printf("The string is %s.\n", s2);
    return 0;
}

