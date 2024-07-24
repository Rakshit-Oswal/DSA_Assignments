#include <stdio.h>

void findSaddlePoint(int mat[4][4], int n) {
    for (int i = 0; i < n; i++) {
        // Find the minimum element in the row
        int min_row = mat[i][0];
        int col_index = 0;
        for (int j = 1; j < n; j++) {
            if (mat[i][j] < min_row) {
                min_row = mat[i][j];
                col_index = j;
            }
        }

        // Check if the minimum element is also the maximum in its column
        int k;
        for (k = 0; k < n; k++) {
            if (mat[k][col_index] > min_row) {
                break;
            }
        }

        // If min_row is maximum in its column
        if (k == n) {
            printf("Saddle point found at matrix cell (%d, %d): %d\n", i + 1, col_index +1, min_row);
            return;
        }
    }

    printf("No saddle point found\n");
}

int main() {
    int mat[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int matDimensions = 4;

    findSaddlePoint(mat, matDimensions);

    return 0;
}
