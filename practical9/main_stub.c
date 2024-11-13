#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square_stub.h"

int getlines(char filename[MAX_FILE_NAME]);

int main(){  
    //define our file variable
    FILE *f;  
    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // ##! n function which gets the number of lines
    int n = getlines(filename);

    // TODO: Open the file 
    f = fopen(filename, "r");
    if (f == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    // TODO: Allocating a matrix for storing the magic square
    // as an array of pointers, where each pointer is a row 
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL) {
        printf("Memory allocation failed\n");
        fclose(f);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Memory allocation failed for row %d\n", i);
            // Free previously allocated rows
            for (int j = 0; j < i; j++) {
                free(matrix[j]);
            }
            free(matrix);
            fclose(f);
            return 1;
        }
    }

    // TODO: Inputting integer data into the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (fscanf(f, "%d", &matrix[i][j]) != 1) {
                printf("Error reading data from file\n");
                // Free the allocated memory before returning
                for (int k = 0; k < n; k++) {
                    free(matrix[k]);
                }
                free(matrix);
                fclose(f);
                return 1;
            }
        }
    }

    // Check if the matrix is a magic square using the function from magic_square.h
    if (isMagicSquare(matrix, n)) {
        printf("The matrix is a magic square.\n");
    } else {
        printf("The matrix is NOT a magic square.\n");
    }

    // TODO: Freeing each row separately before freeing the array of pointers
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    // TODO: Close the file
    fclose(f);

    return 0;
}  

//##!

int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return -1;
    }
    
    int ch_read;
    int count = 0;

    while( (ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n'){
            count++;
        }
    }

    printf("No. lines, %d\n", count);
    fclose(fp); 
    return count;
}
