// What is Gauss Elimination Method? Gauss Elimination is a method for solving a system of linear equations. The system is represented in an augmented matrix form, and through a series of row operations, the matrix is transformed into an upper triangular form. After that, back substitution is used to find the unknown variables.

#include <stdio.h>
#define SIZE 10

// The matrix is transformed into an upper triangular form by eliminating the elements below the main diagonal (i.e., making them zero). This is done by subtracting multiples of the current row from the rows below it.
void gaussElimination(float matrix[SIZE][SIZE], int n) {
    int i, j, k;
    float ratio;

    for (i = 0; i < n - 1; i++) { // col traversal
        for (j = i + 1; j < n; j++) { // row traversal
            if (matrix[i][i] == 0) {
                printf("Mathematical Error: Division by zero.\n");
                return;
            }

            // Finding the ratio to eliminate the element in column i, row j
            ratio = matrix[j][i] / matrix[i][i];

            // Applying the row operations
            for (k = 0; k <= n; k++) {
                matrix[j][k] = matrix[j][k] - ratio * matrix[i][k];
            }
        }
    }

    // Back Substitution to find the solution
    float solution[SIZE];
    for (i = n - 1; i >= 0; i--) { // row 
        solution[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    // Displaying the solution
    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %.2f\n", i + 1, solution[i]);
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

    // Performing Gauss Elimination
    gaussElimination(matrix, n);

    return 0;
}


