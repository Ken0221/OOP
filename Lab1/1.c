#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int difoe(char *num[], int len){
    int i_num[len];
    for(int i = 2; i < len; i++){
        i_num[i] = atoi(num[i]);
    }
    for(int i = 2; i < len; i++){
        for(int j = i; j < len; j++){
            if(i_num[i] > i_num[j]){
                int temp = i_num[i];
                i_num[i] = i_num[j];
                i_num[j] = temp;
            }
        }
    }
    int mineven;
    int maxodd;
    for(int i = 2; i < len; i++){
        if(i_num[i] % 2 == 0){
            mineven = i_num[i];
            break;
        }
    }
    for(int i = len - 1; i >= 2; i--){
        if(i_num[i] % 2 == 1){
            maxodd = i_num[i];
            break;
        }
    }
    int diff = abs(maxodd - mineven);
    return diff;
}

double odive(char *num[], int len){
    int odd = 0;
    int even = 0;
    int number[len];
    for(int i = 2; i < len; i++){
        number[i] = atoi(num[i]);
    }
    for(int i = 2; i < len; i++){
        int t = number[i];
        int k = 0;
        while(t != 0){
            t /= 10;
            k++;
        }
        t = abs(number[i]);
        int z = 1;
        for(int j = 0; j < k - 1; j++){
            z *= 10;
        }
        while(z != 0){
            if((t / z) % 2 == 1){
                odd += (t / z);
            }
            else{
                even += (t / z);
            }
            t -= (t / z) * z;
            z /= 10;
        }
    }
    double division = (double)odd / (double)even;
    return division;
}

int main(int argc, char *argv[])
{
    if ( strcmp( argv[1], "d") == 0 ) {
        int diff = difoe(argv, argc);
        printf("diff. = %d\n\n", diff);
    }
    
    if ( strcmp( argv[1], "o") == 0 ) {
        double division = odive(argv, argc);
        printf("division = %f\n\n", division);
	}
    return 0;
}

