#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v;
    int n;
    while(printf("Input scores:") && scanf("%d", &n) != EOF){
        if(n == -999){
            continue;
        }
        v.push_back(n);
        while(scanf("%d", &n) != EOF){
            if(n == -999)
                break;
            v.push_back(n);
        }
        sort(v.begin(), v.end());
        int s = 1;
        for(int i = 0; i < v.size(); i++){
            while(v[i] == v[i + 1] && i < v.size() - 1){
                s++;
                i++;
            }
            printf("%3d:%2d\n", v[i], s);
            s = 1;
        }
    }
    return 0;
}
