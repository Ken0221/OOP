#include<iostream>
#include<stdio.h>
#define COLOR 4
#define POINT 13
using namespace std;

char color[COLOR][7] = {"黑桃", "紅心", "方塊", "梅花"};
char point[POINT][3] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

void flush_deal(int x[COLOR][POINT]){
    int t = 0;
    int player = 0;
    while(t < 52){
        int q = rand() % 52;
        int c = q % COLOR;
        int p = q % POINT;
        if(x[c][p] == 0){
            player = player % COLOR + 1;
            x[c][p] = player;
            t++;
        }
    }
}

void print(int x[COLOR][POINT]){
    for(int p = 1; p <= 4; p++){
        for(int i = 0; i < COLOR; i++){
            for(int j = 0; j < POINT; j++){
                if(x[i][j] == p){
                    printf("%4s%-3s", color[i], point[j]);
                }
            }
        }
        cout << endl;
    }
}

int main(){
    int x[COLOR][POINT];
    for(int i = 0; i < COLOR; i++){
        for(int j = 0; j < POINT; j++)
            x[i][j] = 0;
    }
    srand(time(NULL));
    flush_deal(x);
    print(x);
    return 0;
}
