#include<iostream>
#include<stdio.h>
//#include<stdlib.h>
#include<iomanip>
#include<time.h>
#define m 4 //colors
#define n 13 //points
using namespace std;
char c[4][7] = {"黑桃", "紅心", "方塊", "梅花"}; // g++的中文是三bytes
char d[n][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
//char c[4][7] = {"spade", "heart", "square", "flower"};

void flush(int x[m][n]){
   int i, j, p = 0, c = 0;
   while(c < 52){
        int q =      rand() % 52;
        i = q % m;
        j = q % n;
        if(x[i][j] == 0){
            p = p % m + 1;
            x[i][j] = p;
            c++;
        }
   }
}

void print(int x[m][n]){
    for(int p = 1; p <= m; p++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(x[i][j] == p){
                    printf("%4s%-3s", c[i], d[j]);
                }
            }
        }
        cout << endl;
    }
}

int main(){
    int x[m][n];
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            x[i][j] = 0;
        }
    }
    srand(time(NULL));
    flush(x);
    print(x);
    return 0;
}
