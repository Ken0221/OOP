#include<iostream>
#include<stdio.h>
#include<iomanip>
using namespace std;
#define Item_num 5

struct Item{
    int v;
    int w;
};

    Item item[Item_num] = {{15, 6}, {12, 4}, {9, 5}, {7, 3}, {4, 2}};

int f[Item_num + 1][100];

int func(int k, int g){
    if(f[k][g] != -1)
        return f[k][g];
    if(k == 0 || g == 0)
        return 0;
    else if(item[k - 1].w > g)
        f[k][g] = func(k - 1, g);
    else{
        int vk = item[k - 1].v + func(k - 1, g - item[k - 1].w);
        int v = func(k - 1, g);
        f[k][g] = (vk > v)? vk : v;
    }
    return f[k][g];
}

int main(){
    for(int i = 0; i < Item_num + 1; i++){
        for(int j = 0; j < 100; j++){
            f[i][j] = -1;
        }
    }
    int w;
    while(scanf("%d", &w) != EOF){
        for(int k = 1; k <= Item_num; k++){
            for(int g = 1; g <= w; g++){
                int r = func(k, g);
                printf("%3d", r);
            }
            cout << endl;
        }

        printf("%3d\n", f[Item_num][w]);
	int k = 5, g = w;
	while(k > 0 && g > 0)
	{
		if(f[k][g] == f[k-1][g])
		{
			k--;
		}
		else
		{
			printf("%3d", k);
			g -= item[k-1].w;
			k--;
		}
	}

        cout << endl;
    }
    return 0;
}
