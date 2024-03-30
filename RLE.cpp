#include<iostream>
#include<string.h>
using namespace std;

char* compress(char* a){
    char* b = new char[100];
    int k = 0;
    for(int i = 0; i < strlen(a); i++){
        if(isalpha(a[i]) && a[i] == a[i + 1]){
            int t = 0;
            for(int j = i + 1; j < strlen(a); j++){
                if(a[j] != a[i])
                    break;
                t++;
            }
            b[k] = '0' + t + 1;
            k++;
            b[k] = a[i];
            i += t;
        }
        else
            b[k] = a[i];
        k++;
    }
    b[k] = '\0';
    return b;
}

char* decompress(char* a){
    char *d = new char[100];
    int k = 0;
    for(int i = 0; i < strlen(a); i++){
        if(isdigit(a[i]) && isalpha(a[i + 1])){
            for(int j = 0; j < a[i] - '0'; j++){
                d[k] = a[i + 1];
                k++;
            }
            i++;
        }
        else{
            d[k] = a[i];
            k++;
        }
    }
    d[k] = '\0';
    return d;
}

int main(){
    char a[100];
    while(printf("Input data: ") && scanf("%s", a) != EOF){
        getchar();
        char* c = compress(a);
        char* d = decompress(c);
        cout << "Compressed: " << c << endl;
        cout << "Decompressed: " << d << endl;
        if(strcmp(a, d) == 0)
            cout << "Decompress successfully!!" << endl;
        else
            cout << "Decompress failed!!" << endl;
        cout << endl;
    }
    return 0;
}
