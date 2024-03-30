#include<stdio.h>
#include<iostream>
#include"1.h"

using namespace std;

char** findEdges(char image[H][W]){
    char** a = new char *[H];
    for(int i = 0; i < H; i++){
        a[i] = new char[W];
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(image[i][j] == '1'){
                int check_i[4] = {-1, 1, 0, 0};
                int check_j[4] = {0, 0, -1, 1};
                for(int k = 0; k < 4; k++){
                    if(image[i + check_i[k]][j + check_j[k]] == '0'){
                        a[i][j] = '1';
                        break;
                    }
                    a[i][j] = '0';
                }
            }
            else{
                a[i][j] = '0';
            }
        }
    }
    return a;
}

int main(){
    char** result = findEdges(image);

    cout << "Original picture:" << endl;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << image[i][j] << " ";
            if(j == W - 1)
                cout << endl;
        }
    }

    cout << endl << endl << endl;

    cout << "Edges picture:" << endl;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << result[i][j] << " ";
            if(j == W - 1)
                cout << endl;
        }
    }


    return 0;
}
