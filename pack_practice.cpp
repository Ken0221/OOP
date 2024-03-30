#include<stdio.h>
#define NUM 5

struct item{
    int v;
    int w;
}

item[NUM] = {{15, 6}, {12, 4}, {9, 5}, {7, 3}, {4, 2}};
int f[NUM + 1][100];

int func(int k, int g){
    if(f[k][g] != -1){
        return f[k][g];
    }
    if(k == 0 || g == 0){
        return 0;
    }
    if(item[k - 1].w > g){
        f[k][g] = func(k - 1, g);
    }
    else{
        int vk = item[k - 1].v + func(k - 1, g - item[k - 1].w);
        int v = func(k - 1, g);
        f[k][g] = (vk > v)? vk : v;
    }
    return f[k][g];
}

int main(){
    int w;
    while(printf("input w(<100): ") && scanf("%d", &w) != EOF){
        for(int i = 0; i <= NUM; i++){
            for(int j = 0; j <= w; j++){
                f[i][j] = -1;
            }
        }
        for(int i = 0; i <= NUM; i++){
            for(int j = 0; j <= w; j++){
                f[i][j] = func(i, j);
                printf("%3d", f[i][j]);
            }
            printf("\n");
        }
        printf("%d\n", f[NUM][w]);
        int g = w;
        for(int i = NUM; i > 0; i--){
            if(f[i][g] != f[i - 1][g]){
                g -= item[i - 1].w;
                printf("%3d", i);
            }
        }
        printf("\n");
    }
}
