#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 13

// Global array to store tan values from 0 to 60 degrees
double tan_values[ARRAY_SIZE];

double degrees_to_radians(double degrees) {
    return degrees * (M_PI / 180.0);
}

void calculate_tan_values() {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        double degree = i * 5;
        tan_values[i] = tan(degrees_to_radians(degree));
    }
}

void print_tan_values() {
    printf("Tan values from 0 to 60 degrees (every 5 degrees):\n");
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("tan(%d degrees) = %lf\n", i * 5, tan_values[i]);
    }
}

double calculate_area(int num_points) {
    double start = 0.0;
    double end = M_PI / 3.0;
    double step = (end - start) / (num_points - 1);
    double sum = tan(start) + tan(end);

    for (int i = 1; i < num_points - 1; ++i) {
        double x = start + i * step;
        sum += 2 * tan(x);
    }

    return (step / 2.0) * sum;
}

int main() {
    // Calculate and print tan values
    calculate_tan_values();
    print_tan_values();

    // Calculate the area under tan(x) from 0 to π/3
    int num_points = ARRAY_SIZE;
    double area = calculate_area(num_points);
    printf("\nThe approximate integral of tan(x) from 0 to π/3 is: %lf\n", area);
    printf("The actual value (log(2)) is: %lf\n", log(2));

    return 0;
}