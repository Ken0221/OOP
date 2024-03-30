#include<iostream>
using namespace std;

int main(){
    int r = 3;
    float **p = new float *[r];
    for(int i = 0; i < r; i++){
        p[i] = new float[3];
    }
    int k = 1;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            p[i][j] = k;
            k++;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < r; j++){
            cout << p[i][j];
        }
        cout << endl;
    }
    for(int i = 0; i < r; i++){
        delete []p[i];
    }
    delete []p;

    return 0;
}
