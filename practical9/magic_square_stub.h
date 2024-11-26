#include <stdio.h>
#include <stdlib.h>

// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//

int isMagicSquare(int **square, const int n) {
    // Eliminate the case where 'n' is negative or zero
    if (n <= 0) {
        return 0;
    }

    // Calculate the expected sum for rows, columns, and diagonals
    int M = (n * (n * n + 1)) / 2;

    int i, j;

    // Check each row sum
    for (i = 0; i < n; i++) {
        int rowSum = 0;
        for (j = 0; j < n; j++) {
            rowSum += square[i][j];
        }
        if (rowSum != M) {
            return 0; // Not a magic square if any row sum is not equal to M
        }
    }

    // Check each column sum
    for (j = 0; j < n; j++) {
        int colSum = 0;
        for (i = 0; i < n; i++) {
            colSum += square[i][j];
        }
        if (colSum != M) {
            return 0; // Not a magic square if any column sum is not equal to M
        }
    }

    // Check main diagonal sum
    int mainDiagSum = 0;
    for (i = 0; i < n; i++) {
        mainDiagSum += square[i][i];
    }
    if (mainDiagSum != M) {
        return 0; // Not a magic square if main diagonal sum is not equal to M
    }

    // Check secondary diagonal sum
    int secDiagSum = 0;
    for (i = 0; i < n; i++) {
        secDiagSum += square[i][n - 1 - i];
    }
    if (secDiagSum != M) {
        return 0; // Not a magic square if secondary diagonal sum is not equal to M
    }

    // If all checks are passed, it's a magic square
    return 1;
}

