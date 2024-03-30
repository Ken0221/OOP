#include<stdio.h>
#include<iostream>
#define SEED 12345

using namespace std;

int seqsearch(int* data, int N, int target, int &c){
    for(int i = 0; i < N; i++){
        c++;
        if(target == data[i]){
            return 1;
        }
    }
    return 0;
}
//Using the sequential search to find the target in the array.
//The parameter &c returns the number of the search to find the target
//The function returns 1 if the target number is in the array, otherwise returns 0.



int binsearch(int* data, int N, int target, int &c){
    int str = 0;
    int end = N - 1;
    int mid = (str + end) / 2;
    while(str <= end){
        c++;
        mid = (str + end) / 2;
        if(target == data[mid])
            return 1;
        else if(target > data[mid])
            str = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}
//Using the binary search to find the target in the array.
//The parameter &c returns the number of the search to find the target.
//The function returns 1 if the target number is in the array, otherwise returns 0.
//Remind that you should sort the array before searching.

void sort(int *data, int N){
    for(int i = 0; i < N - 1; i++){
        for(int j = i + 1; j < N; j++){
            if(data[i] > data[j]){
                int t = data[i];
                data[i] = data[j];
                data[j] = t;
            }
        }
    }
} //which sort the data in ascendent order.

int main(){
    int N, M;
    srand(SEED);

    while(printf("N, M: "),scanf("%d %d",&N,&M)!=EOF){
        int *data = new int[N];
        int *datatmp = new int[M];
        int *sortdata = new int[N];

//The following three for loop to randomly create N個 "NOT duplicated" data
//range from 1 to M
        for (int i = 1; i <= M; i++)
            datatmp[i - 1] = i;
        for (int i = 0; i < M; i++) {
            int t = rand() % M;
            int d = datatmp[i];
            datatmp[i] = datatmp[t];
            datatmp[t] = d;
        }
        for (int i = 0; i < N; i++)
            data[i] = datatmp[i];

        for(int i = 0; i < N; i++)
            sortdata[i]=data[i];

        sort(sortdata, N);
        int seqfind = 0,binfind = 0,sc = 0,bc = 0, tsc = 0,tbc = 0;
        for(int i = 0; i < M; i++){
	        int tar = rand() % M + 1;
		    //…
		    if(seqsearch(data, N, tar, tsc)) seqfind++;
		    if(binsearch(sortdata, N, tar, tbc)) binfind++;
            //…
        }

        printf("--- Sequential Search ---\n");
        printf("The number of successful searches: %d\n", seqfind);
        printf("The percentage of successful searches: %.3lf%%\n", 100.*seqfind/M );
        printf("The average number of the search is %lg\n", 1.0*tsc/M );
        printf("\n--- Binary Search ---\n");
        printf("The number of successful searches: %d\n", binfind );
        printf("The percentage of successful searches: %.3lf%%\n", 100.*binfind/M );
        printf("The average number of the search is %lg\n", 1.0*tbc/M );
        printf("\n\n");
    }
    return 0;
}
