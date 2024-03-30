#include<iostream>
#include<vector>
using namespace std;

void cal(int n, vector<int> &b){
    int t = 1;
    int k = 0;
    while(t < n){
        t *= 2;
        k++;
    }
    while(n > 0){
        if(n - t >= 0){
            n -= t;
            b.insert(b.begin(), k);
        }
        t /= 2;
        k--;
    }
}

int main(){
        vector<int> bin;
    int n;
    while(scanf("%d", &n) != EOF){
        cal(n,bin);
        for(int i = 0; i < bin.size(); i++){
            printf("%d ", bin[i]);
        }
        printf("\n");
        bin.clear();
    }
    return 0;
}
