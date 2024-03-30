#include<stdio.h>
#include<iostream>
#include<iomanip>

using namespace std;

int **generateMat(int M, int N){
    int** a = new int* [M];
    for(int i = 0; i < M; i++){
        a[i] = new int [N];
    }

   for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++)
            a[i][j] = 0;
   }
   return a;
}

void inputMat(int** a,int M, int N){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    return;
}

void printMat(int **Mat, int M, int N){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cout << setw(4) << Mat[i][j];
        }
        cout << endl;
    }
} //which prints the matrix data with dimension MxN

int **multiplyMat(int **Mat1, int **Mat2, int M, int N, int K){
    int **ans = new int *[M];
    for(int i = 0; i < M; i++){
        ans[i] = new int [K];
    }
    for(int  i = 0; i < M; i++){
        for(int j = 0; j < K; j++){
            ans[i][j] = 0;
        }
    }
    for(int m = 0; m < M; m++){
        for(int k = 0; k < K; k++){
            for(int n = 0; n < N; n++){
                ans[m][k] += Mat1[m][n] * Mat2[n][k];
            }
        }
    }
    return ans;
} //which multiplies Mat1( MxN )by Mat2 (NxK) and returns the result.

int **toeplitzMat(int **Mat, int M, int N){
    int** toe = new int *[M];
    for(int i = 0; i < M; i++){
        toe[i] = new int [N];
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){ 
            toe[i][j] = (i == 0 || j == 0)? Mat[i][j] : toe[i - 1][j - 1];
        }
    }
    return toe;
} //which use the first row and the first column from Mat to create a Toeplitz matrix.


int main(){
    int M,N,K;
	int **Mat1,**Mat2,**ans,**toep;
	printf("input row,column of 1st matrix and column of 2nd matrix (m n k)): ");
	while(scanf("%d %d %d",&M,&N,&K)){

		Mat1=generateMat(M,N);
		printf("input data of a matrix: ");
		inputMat(Mat1,M,N);

		Mat2=generateMat(N,K);
		printf("input data of a matrix: ");
		inputMat(Mat2,N,K);

		ans=multiplyMat(Mat1,Mat2,M,N,K);

		printf("\nMatrix1:\n");
		printMat(Mat1,M,N);
		printf("\nMatrix2:\n");
		printMat(Mat2,N,K);
		printf("\nAnswer:\n");
		printMat(ans,M,K);

		toep = toeplitzMat(ans,M,K);
		printf("\nToeplitzMatrix:\n");
		printMat(toep,M,K);


		printf("\ninput row,column of 1st matrix and column of 2nd matrix (m n k)): ");
	}
    return 0;
}
