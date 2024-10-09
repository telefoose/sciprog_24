#include <stdio.h>
#include <math.h> 
#define M_PI 3.14

int main() {
    // So a=0and b=π/3.
    double a = 0.0;
    double b = M_PI/3.0;
    
    // Number of intervals
    int N = 12;
    
    // Compute the width of each interval
    double h = (b-a)/N;
    
    // Initialize the sum for the trapezoidal rule
    double sum = 0.0;
    
    // First part of the sum: tan(0) + tan(π/3)
    sum = tan(a)+tan(b);
    
    // Loop to add 2 * tan(xi) for each of the 11 intermediate points
    for (int i = 1; i < N; i++) {
        double xi = a+i*h;
        sum += 2*tan(xi);
    }
    
    // Multiply the result by h/2 to complete the trapezoidal rule
    double integral = (h/2)*sum;
    
    // Output the result
    printf("The approximate integral of tan(x) from 0 to π/3 is: %f\n", integral);
    printf("The actual value (log(2)) is: %f\n", log(2));
    
    return 0;
}
