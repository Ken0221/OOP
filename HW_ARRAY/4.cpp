#include<stdio.h>
#include<iostream>
using namespace std;

int* sieve(int n){
    int *p = new int[n];
    for(int i = 0; i < n; i++){
        p[i] = 1;
    }
    int numCheck = 2;
    while(numCheck * numCheck <= n){
        for(int i = numCheck; numCheck * i <= n; i++){
            p[numCheck * i - 1] = 0;
        }
        for(int i = numCheck; i < n; i++){
            if(p[i] == 1){
                numCheck = i + 1;
                break;
            }
        }
    }
    return p;
}

int main(){
    int n;
    while(printf("input n: ") && scanf("%d", &n) != EOF){
        //cout << "input n: ";
        //cin >> n;
        int *p = sieve(n);
        cout << endl << "prime numbers:" << endl;
        for(int i = 1; i < n; i++){
            if(p[i] == 1)
                cout << i + 1 << " ";
        }
        cout << endl << endl;
    }
    return 0;
}
