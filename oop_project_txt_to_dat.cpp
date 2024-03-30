#include<stdio.h>
#include<iostream>
using namespace std;

struct points{
    double x;
    double y;
    double z;
};

int main(){
    FILE *t = fopen("coefficient.txt", "r");
    FILE *d = fopen("map.dat", "w+b");
    if(t == NULL){
       cout << "Can\'t open file t " << endl;
       exit(1);
    }
    if(d == NULL){
       cout << "Can\'t open file d " << endl;
       exit(1);
    }

    points a[2];
    points b;

    rewind(t);
    rewind(d);
    //int n = 0;
    while(fscanf(t, "%lf %lf %lf %lf %lf %lf", &a[0].x, &a[0].y, &a[0].z, &a[1].x, &a[1].y, &a[1].z) != EOF){
        for(int i = 0; i < 2; i++){
            fwrite(&a[i], sizeof(a[i]), 1, d);
        }
        //cout << n++ << endl;
    }
    rewind(d);
    while(fread(&b, sizeof(b), 1, d)){
        cout << "[0]x = " << b.x << " [0]y = " << b.y << " [0]z = " << b.z/* <<  "[1]x = " << a[1].x << " [1]y = " << a[1].y << " [1]z = " << a[1].z */<< endl;
    }
    fclose(t);
    fclose(d);

    return 0;
}
