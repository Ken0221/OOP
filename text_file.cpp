#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define SEED 12345

int main(){
    FILE *f1;
    f1 = fopen("t1.txt", "w");
    if(f1 == NULL){
       cout << "Can\'t open file t1.txt " << endl;
       exit(1);
    }
    srand(SEED);
    //int init[10] = {0, 46, 2, 22, 27, 11, 41, 27, 19, 33};
    for(int i = 0; i < 10; i++){
        int n = rand() % 51;
        fprintf(f1, "%d\n", n);
    }
    fclose(f1);
    f1 = fopen("t1.txt", "r");
    int data[10];
    for(int i = 0; i < 10; i++){
       fscanf(f1, "%d", &data[i]);
    }
    /*for(int i = 0; i < 10; i++){
        printf("%d\n", data[i]);
    }*/
    for(int i = 0; i < 10 - 1; i++){
       for(int j = i + 1; j < 10; j++){
           if(data[i] > data[j]){
               int t = data[i];
               data[i] = data[j];
               data[j] = t;
           }
       }
    }
    /*for(int i = 0; i < 10; i++){
        printf("%d\n", data[i]);
    }*/
    fclose(f1);

    FILE *f2;
    f2 = fopen("t2.txt", "w");
    for(int i = 0; i < 10; i++){
       fprintf(f2, "%d\n", data[i]);
    }
    fclose(f2);

    f1 = fopen("t1.txt", "a+");
    for(int i = 0; i < 10; i++){
        fprintf(f1, "%d\n", data[i]);
    }
    /*fseek(f1, 0, SEEK_SET);
    for(int i = 0; i < 20; i++){
        int r;
        fscanf(f1, "%d", &r);
        if(i == 10)
            cout << endl;
        printf("r = %d\n", r);
    }*/ //check
    fclose(f1);

    //Repeat to binary
    FILE *fb1;
    fb1 = fopen("t1.dat", "wb");
    if(f1 == NULL){
       cout << "Can\'t open file t1.dat " << endl;
       exit(1);
    }
    srand(SEED);
    //int init[10] = {0, 46, 2, 22, 27, 11, 41, 27, 19, 33};
    for(int i = 0; i < 10; i++){
        int n = rand() % 51;
        fwrite(&n, sizeof(n), 1, fb1);
    }
    fclose(fb1);
    fb1 = fopen("t1.dat", "rb");
    int datab[10];
    for(int i = 0; i < 10; i++){
       fread(&datab[i], sizeof(datab[i]), 1, fb1);
    }
    /*for(int i = 0; i < 10; i++){
        printf("%d\n", data[i]);
    }*/
    for(int i = 0; i < 10 - 1; i++){
       for(int j = i + 1; j < 10; j++){
           if(datab[i] > datab[j]){
               int t = datab[i];
               datab[i] = datab[j];
               datab[j] = t;
           }
       }
    }
    /*for(int i = 0; i < 10; i++){
        printf("%d\n", data[i]);
    }*/
    fclose(fb1);

    FILE *fb2;
    fb2 = fopen("t2.dat", "wb");
    for(int i = 0; i < 10; i++){
       fwrite(&datab[i], sizeof(datab[i]), 1, fb2);
    }
    fclose(fb2);

    fb1 = fopen("t1.dat", "a+b");
    for(int i = 0; i < 10; i++){
        fwrite(&datab[i], sizeof(datab[i]), 1, fb1);
    }
    /*fseek(f1, 0, SEEK_SET);
    for(int i = 0; i < 20; i++){
        int r;
        fscanf(f1, "%d", &r);
        if(i == 10)
            cout << endl;
        printf("r = %d\n", r);
    }*/ //check
    fclose(fb1);

    
    return 0;
}
