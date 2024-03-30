#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

int palin1(char* a){
    for(int i = 0; i < strlen(a); i++){
        if(!isalpha(a[i])){
            for(int j = i; j < strlen(a); j++){
                a[j] = a[j + 1];
            }
        }
        if(isupper(a[i]))
            a[i] += 32;
    }

    for(int i = 0; i < strlen(a) / 2; i++){
        if(a[i] != a[strlen(a) - 1 - i]){
            return 0;
        }
    }
    return 1;
}

int palin2(char* a){
    for(int i = 0; i < strlen(a); i++){
        if(isupper(a[i]))
            a[i] += 32;;
    }
    char *p;
    p = strtok(a, " ");
    int t = 0;
    char *word[100];
    while(p != NULL){
        word[t] = p;
        p = strtok(NULL, ". ");
        t++;
    }
    int l = 0, r = t - 1;
    while(l < r){
        if(strcmp(word[l], word[r]) != 0)
            return 0;
        l++; r--;
    }
    return 1;
}

int palin3(char* a){
    int l = 0;
    int r = strlen(a) - 3;

    while (l < r) {
        if (a[l] != a[r] || a[l + 1] != a[r + 1] || a[l + 2] != a[r + 2]) {
            return 0;
        }
        l += 3;
        r -= 3;
    }
    return 1;
}


int main(){
    int c;
    int (*f[3])(char*) = {palin1, palin2, palin3};
    while(true){
        printf("0: Exit\n1: Case 1\n2: Case 2\n3: Case 3\nInput: ");
        scanf("%d", &c);
        if(c == 0)
            break;
        getchar();
        printf("Input a string: ");
        char a[100];
        fgets(a, 100, stdin);
        a[strlen(a) - 1] = '\0';
        int r = f[c - 1](a);
        if(r == 1)
            cout << "Is a palindrome" << endl << endl;
        else if(r == 0)
            cout << "Not a palindrome" << endl << endl;
    }
    return 0;
}
