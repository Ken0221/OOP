#include<iostream>
#include<string.h>
using namespace std;


int main(){
    char a[13];
    while(printf("input barcode: ") && scanf("%s", a) != EOF){
        if(strlen(a) != 12){
            printf("error: length should be 12!\n\n");
            continue;
        }
        int valid = 0;
        for(int i = 0; i < strlen(a); i++){
            if(a[i] < 48 || a[i] >= 58){
                printf("error: digit only!\n\n");
                valid = 1;
                break;
            }
        }
        if(valid == 1)
            continue;
        int s = 0;
        for(int i = 0; i < strlen(a) - 1; i+=2){
            s += (a[i] - 48);
        }
        s *= 3;
        for(int i = 1; i < strlen(a) - 1; i += 2){
            s += (a[i] - 48);
        }
        s = 10 - (s % 10);
        if(s == 10)
            s = 0;
        if(s == a[strlen(a) - 1] - 48)
            printf("check digit correct!");
        else
            printf("check digit incorrect!\ncheck digit should be: %d", s);

        printf("\n\n");
    }
    return 0;
}
