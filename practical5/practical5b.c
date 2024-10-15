#include <stdio.h>
#include <math.h>

double arctanh_maclaurin(double x,double delta){
    double sum = 0.0;
    double term = x;
    int n = 0;

    while (fabs(term)>delta){
        sum += term;
        n++;
        term = pow(x,2*n+1)/(2*n+1);
    }

    return sum;
}

double arctanh_log(double x){
    return 0.5*(log(1+x)-log(1-x));
}

int main(){
    double delta;
    printf("Enter a real positive number(delta): ");
    scanf("%lf",&delta);

    double x;

    for (x =-0.9; x<=0.9; x+=0.01){
        
        double maclaurin_result = arctanh_maclaurin(x, delta);
        double log_result = arctanh_log(x);

        printf("\nx = %.2lf: \n Maclaurin approximation = %.10lf \n Logarithmic calculation = %.10lf\n", x, maclaurin_result, log_result);
    }

    return 0;
}