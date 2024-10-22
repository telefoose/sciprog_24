#include <stdio.h>

#define N 5
#define P 3
#define Q 4

void initialize_matrices(double A[N][P],double B[P][Q],double C[N][Q]){
    for (int i=0;i<N;i++){
        for (int j=0;j<P;j++){
            A[i][j]=i+j;
        }
    }

    for (int i=0;i<P;i++){
        for (int j=0;j<Q;j++){
            B[i][j]=i-j;
        }
    }

    for (int i=0;i<N;i++){
        for (int j=0;j<Q;j++){
            C[i][j]=0;
        }
    }
}

void multiply_matrices(double A[N][P],double B[P][Q],double C[N][Q]){
    for (int i=0;i<N;i++){
        for (int j=0;j<Q;j++){
            for (int k=0;k<P;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}


void print_matrix(double *matrix,int rows,int cols){
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            printf("%6.2f ",*(matrix+i*cols+j));
        }
        printf("\n");
    }
}

int main(){
    double A[N][P];
    double B[P][Q];
    double C[N][Q];

    initialize_matrices(A,B,C);
    multiply_matrices(A,B,C);

    printf("Matrix A:\n");
    print_matrix(&A[0][0],N,P);

    printf("\nMatrix B:\n");
    print_matrix(&B[0][0],P,Q);

    printf("\nMatrix C (Result):\n");
    print_matrix(&C[0][0],N,Q);

    return 0;
}
