#include <stdio.h>

#define MAX 5

int zeroMatrix(int a[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (a[i][j] != 0)
                return 0;
    return 1;
}

void multiply(int a[MAX][MAX], int b[MAX][MAX],
              int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
                result[i][j] += a[i][k] * b[k][j];
        }
    }
}

long long determinant(int a[MAX][MAX], int n) {
    if (n == 1)
        return a[0][0];

    if (n == 2)
        return (long long)a[0][0] * a[1][1]
             - (long long)a[0][1] * a[1][0];

    long long det = 0;
    int minor[MAX][MAX];

    for (int col = 0; col < n; col++) {
        int r = 0;

        for (int i = 1; i < n; i++) {
            int c = 0;

            for (int j = 0; j < n; j++) {
                if (j != col)
                    minor[r][c++] = a[i][j];
            }
            r++;
        }

        long long term = (long long)a[0][col]
                       * determinant(minor, n - 1);

        if (col % 2 == 0)
            det += term;
        else
            det -= term;
    }

    return det;
}

int main(void) {
    int a[MAX][MAX] = {0};
    int b[MAX][MAX] = {0};
    int a2[MAX][MAX] = {0};
    int power[MAX][MAX] = {0};
    int next[MAX][MAX] = {0};
    int r, c, choice;

    printf("Enter number of rows (1-5): ");
    scanf("%d", &r);

    printf("Enter number of columns (1-5): ");
    scanf("%d", &c);

    if (r < 1 || r > MAX || c < 1 || c > MAX) {
        printf("Invalid matrix size!\n");
        return 1;
    }

    printf("Enter matrix elements:\n");

    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            scanf("%d", &a[i][j]);

    printf("\nOriginal Matrix:\n");

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%5d", a[i][j]);
        printf("\n");
    }

    printf("\n===== MATRIX CLASSIFICATION =====\n");

    if (r == c)
        printf("1. Square Matrix\n");
    else
        printf("2. Rectangular Matrix\n");

    if (zeroMatrix(a, r, c)) {
        printf("3. Zero Matrix\n");
        printf("15. Null Matrix\n");
    }

    if (r == 1)
        printf("13. Row Matrix\n");

    if (c == 1)
        printf("14. Column Matrix\n");

    if (r == c) {
        int identity = 1, diagonal = 1, scalar = 1;
        int upper = 1, lower = 1, symmetric = 1, skew = 1;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (i == j) {
                    if (a[i][j] != 1)
                        identity = 0;

                    if (a[i][i] != a[0][0])
                        scalar = 0;

                    if (a[i][j] != 0)
                        skew = 0;
                } else {
                    if (a[i][j] != 0) {
                        diagonal = 0;
                        identity = 0;
                        scalar = 0;
                    }

                    if (a[i][j] != a[j][i])
                        symmetric = 0;

                    if (a[i][j] != -a[j][i])
                        skew = 0;
                }

                if (i > j && a[i][j] != 0)
                    upper = 0;

                if (i < j && a[i][j] != 0)
                    lower = 0;
            }
        }

        if (identity)
            printf("4. Identity Matrix\n");

        if (diagonal)
            printf("5. Diagonal Matrix\n");

        if (scalar)
            printf("6. Scalar Matrix\n");

        if (upper)
            printf("7. Upper Triangular Matrix\n");

        if (lower)
            printf("8. Lower Triangular Matrix\n");

        if (symmetric)
            printf("9. Symmetric Matrix\n");

        if (skew)
            printf("10. Skew-Symmetric Matrix\n");

        long long det = determinant(a, r);

        printf("Determinant = %lld\n", det);

        if (det == 0)
            printf("11. Singular Matrix\n");
        else
            printf("11. Non-Singular Matrix\n");

        multiply(a, a, a2, r);

        int idempotent = 1;

        for (int i = 0; i < r; i++)
            for (int j = 0; j < r; j++)
                if (a2[i][j] != a[i][j])
                    idempotent = 0;

        if (idempotent)
            printf("16. Idempotent Matrix\n");

        for (int i = 0; i < r; i++)
            for (int j = 0; j < r; j++)
                power[i][j] = a[i][j];

        int nilpotent = 0;

        for (int k = 1; k <= r; k++) {
            if (zeroMatrix(power, r, r)) {
                nilpotent = 1;
                break;
            }

            multiply(power, a, next, r);

            for (int i = 0; i < r; i++)
                for (int j = 0; j < r; j++)
                    power[i][j] = next[i][j];
        }

        if (nilpotent)
            printf("17. Nilpotent Matrix\n");
    }

    printf("\nCompare with another matrix? (1 = Yes, 0 = No): ");
    scanf("%d", &choice);

    if (choice == 1) {
        int r2, c2;

        printf("Enter second matrix rows and columns: ");
        scanf("%d %d", &r2, &c2);

        if (r2 < 1 || r2 > MAX || c2 < 1 || c2 > MAX) {
            printf("Invalid second matrix size!\n");
            return 1;
        }

        printf("Enter second matrix elements:\n");

        for (int i = 0; i < r2; i++)
            for (int j = 0; j < c2; j++)
                scanf("%d", &b[i][j]);

        int equal = (r == r2 && c == c2);

        if (equal) {
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    if (a[i][j] != b[i][j])
                        equal = 0;
        }

        if (equal)
            printf("12. Equal Matrices\n");
        else
            printf("12. Matrices are NOT equal\n");
    }

    return 0;
}