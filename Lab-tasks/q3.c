#include <stdio.h>

int main() {
    int row1, col1;

    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &row1, &col1);

    int matrix1[row1][col1];
	int i, j;
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("Enter first matrix value at row %d and column %d: ",
                   i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    int row2, col2;

    printf("\nEnter rows and columns of second matrix: ");
    scanf("%d %d", &row2, &col2);

    int matrix2[row2][col2];
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("Enter second matrix value at row %d and column %d: ",
                   i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }
    int k;
    if(col1==row2) {
    	int result[row1][col2];
    	for(i = 0; i<row1; i++) {
    		for(j = 0; j<col2; j++) {
    			result[i][j]=0;
    			for(k = 0; k <col1; k++) {
    				result[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
		}
		printf("\nResult: \n");
		for(i=0; i<row1; i++) {
			for(j=0; j<col2; j++) {
				printf("%d ", result[i][j]);
			}
			printf("\n");
		}
	} else {
		printf("Sorry not possible");
	}
    
    
}
