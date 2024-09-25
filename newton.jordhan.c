// The Gauss-Jordan Method is an extension of the Gauss Elimination Method. Instead of just making the matrix upper triangular, this method reduces the matrix to a diagonal form where all the diagonal elements are 1, and all the other elements are 0. This method is used to solve a system of linear equations


#include <stdio.h>

#define SIZE 10

void gaussJordan(float matrix[SIZE][SIZE], int n) {
    int i, j, k;
    float ratio;

    // Performing Gauss-Jordan Elimination
    for (i = 0; i < n; i++) {
        // Make the diagonal element 1
        if (matrix[i][i] == 0) {
            printf("Mathematical Error: Division by zero.\n");
            return;
        }
        
        // Normalize the pivot row
        float pivot = matrix[i][i];
        for (j = 0; j <= n; j++) {
            matrix[i][j] /= pivot;
        }

        // Make all elements in the current column 0, except for the pivot element
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = matrix[j][i];
                for (k = 0; k <= n; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }

    // Displaying the solution
    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, matrix[i][n]);
    }
}

int main() {
    int n, i, j;
    float matrix[SIZE][SIZE];

    // Input: number of unknowns
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    // Input: Augmented matrix
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Performing Gauss-Jordan Elimination
    gaussJordan(matrix, n);

    return 0;
}


