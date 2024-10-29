#include <stdio.h>
#include <stdlib.h>

double approximate_e(int order){
    double *terms=(double *)malloc((order+1)*sizeof(double));
    terms[0]=1.0; 
    double result=terms[0];
    
    for (int i=1; i<=order; i++){
        terms[i]=1.0;
        for (int j=1; j<=i; j++){
            terms[i] /= j;}
        result += terms[i];}

    free(terms);
    return result;
}

int *allocatearray(int size){
    int *array = (int *)malloc(size*sizeof(int));
    return array;
}

void fillwithones(int *array, int size){
    for (int i=0; i<size; i++){
        array[i]=1;}
}

void printarray(int *array, int size){
    for (int i=0; i<size; i++){
        printf("%d ", array[i]);}
    printf("\n");
}

int main(){

    for (int order=1; order<=15; order++){
        double estimate = approximate_e(order);
        printf("Order %d: e ≈ %.5f\n", order, estimate);}

    int size;
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    int *array = allocatearray(size);
    fillwithones(array, size);
    printf("Array filled with ones: ");
    printarray(array, size);
    
    free(array);

    return 0;
}
