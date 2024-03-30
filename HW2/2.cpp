#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

class Quadratic{
    int a;
    int b;
    int c;
    int getDis(){
        int d = b * b - 4 * a * c;
        if(d > 0)
            return 2;
        if(d == 0)
            return 1;
        else
            return 0;
    }

public:
    Quadratic(int n, int m, int k){a = n, b = m, c = k;}
    void findRoot();
};

int main(){
    int a, b, c;
    while(cin >> a >> b >> c){
        Quadratic q1(a, b, c);
        q1.findRoot();
    }
    return 0;
}

void Quadratic::findRoot(){
    int dis = getDis();
    int d = b * b - 4 * a * c;
    if(dis == 2){
        double r1, r2;
        r1 = ((-b) + sqrt(d)) / 2 * a;
        r2 = ((-b) - sqrt(d)) / 2 * a;
        cout << fixed << setprecision(6) << "roots: " << r1 << "," << r2 << endl;
    }
    else if(dis == 1){
        double r = (-b) / 2 * a;
        cout << fixed << setprecision(6) << "root: " << r << endl;
    }
    else{
        cout << "The equation has no real roots" << endl;
    }
    cout << endl;
}
