#include <stdio.h>

int main() {
    int a[3][3], transpose[3][3];
    int cofactor[3][3], adjoint[3][3];
    int i, j, k, det = 0;
    double inverse[3][3];

    printf("Enter the elements of the 3x3 matrix:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Display original matrix
    printf("\nOriginal Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    // 1. Transpose
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            transpose[i][j] = a[j][i];
        }
    }

    printf("\nTranspose Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%5d", transpose[i][j]);
        }
        printf("\n");
    }

    // 2. Cofactor matrix
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            int minor[4], n = 0;

            // Collect elements after removing row i and column j
            for (k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    if (k != i && l != j) {
                        minor[n++] = a[k][l];
                    }
                }
            }

            int sign = ((i + j) % 2 == 0) ? 1 : -1;

            cofactor[i][j] = sign *
                (minor[0] * minor[3] -
                 minor[1] * minor[2]);
        }
    }

    printf("\nCofactor Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%5d", cofactor[i][j]);
        }
        printf("\n");
    }

    // 3. Determinant using first-row expansion
    for (j = 0; j < 3; j++) {
        det += a[0][j] * cofactor[0][j];
    }

    printf("\nDeterminant = %d\n", det);

    // 4. Adjoint = transpose of cofactor matrix
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            adjoint[i][j] = cofactor[j][i];
        }
    }

    printf("\nAdjoint Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%5d", adjoint[i][j]);
        }
        printf("\n");
    }

    // 5. Inverse = adjoint / determinant
    if (det == 0) {
        printf("\nInverse does not exist because determinant is zero.\n");
    } else {
        printf("\nInverse Matrix:\n");

        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                inverse[i][j] =
                    (double) adjoint[i][j] / det;

                printf("%8.3f", inverse[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}