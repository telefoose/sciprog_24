#include <stdio.h>

// Function to find GCD using a recursive approach
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd_recursive(b, a % b);
    }
}

int main() {
    int a, b;

    printf("a: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);

    int result = gcd_recursive(a, b);
    printf("GCD of %d and %d is: %d\n", a, b, result);

    return 0;
}
