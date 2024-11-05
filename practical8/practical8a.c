#include <stdio.h>

// Function to find GCD using an iterative approach
int gcd_iterative(int a, int b) {
    int temp;

    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main() {
    int a, b;

    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    int result = gcd_iterative(a, b);
    printf("GCD of %d and %d is: %d\n", a, b, result);

    return 0;
}
