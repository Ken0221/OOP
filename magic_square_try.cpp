#include<iostream>
#include<ctime>
#include<iomanip>
#define nMax 20

using namespace std;

int main(){
    int n = 0;
    while(n < 3 || !(n % 2) || n > 19){
        cout << "Enter odd array size (3-19): ";
        cin >> n;
    }
    int x[nMax][nMax] = {0};
    int i = 0;
    int j = (n - 1) / 2;
    x[i][j] = 1;
    for(int k = 2; k <= n * n; k++){
        i--; j++;
        if(i < 0 && j > n - 1){
            i = 1;
            j = n - 1;
        }
        else if(i < 0)
            i = n - 1;
        else if(j > n - 1)
            j = 0;

        if(x[i][j] != 0){
            i += 2;
            j--;
        }
        x[i][j] = k;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++)
            cout << setw(4) << x[i][j];
        cout << endl;
    }

    return 0;
}
