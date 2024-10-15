#include <stdio.h>

void calculate_next_fibonacci(int *current,int *previous){
    int next = *current+*previous;
    *previous = *current;
    *current = next;
}

int main(){
    int n;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);

    int previous = 0;
    int current = 1;
    
    if (n >= 1) printf("%d ",previous);
    if (n >= 2) printf("%d ",current);

    for (int i = 2; i < n; i++){
        calculate_next_fibonacci(&current,&previous);
        printf("%d ",current);
    }
    
    printf("\n");
    return 0;
}