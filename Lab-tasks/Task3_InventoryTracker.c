#include <stdio.h>

int main()
{
    int stock[3][4];
    int i, j;
    int total;
    int grandTotal = 0;
    int bestAisle = 1;
    int bestTotal = 0;
    int empty = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Enter units for Aisle %d, Position %d: ", i + 1, j + 1);
            scanf("%d", &stock[i][j]);
        }
    }

    printf("\nOriginal stock:\n");
    for (i = 0; i < 3; i++)
    {
        printf("Aisle %d: ", i + 1);
        for (j = 0; j < 4; j++)
        {
            printf("%d ", stock[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        total = 0;
        for (j = 0; j < 4; j++)
        {
            total = total + stock[i][j];
        }

        if (total > bestTotal)
        {
            bestTotal = total;
            bestAisle = i + 1;
        }
    }

    printf("\nAisle with most stock: Aisle %d (%d units)\n", bestAisle, bestTotal);

    printf("\nLow stock alerts:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (stock[i][j] < 5)
            {
                printf("Aisle %d, Position %d -> %d units\n", i + 1, j + 1, stock[i][j]);
            }

            if (stock[i][j] == 0)
            {
                empty++;
            }
        }
    }

    printf("\nEmpty shelves: %d\n", empty);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (stock[i][j] < 5)
            {
                stock[i][j] = stock[i][j] + 10;
            }
        }
    }

    printf("\nStock after restocking:\n");
    for (i = 0; i < 3; i++)
    {
        printf("Aisle %d: ", i + 1);
        for (j = 0; j < 4; j++)
        {
            printf("%d ", stock[i][j]);
            grandTotal = grandTotal + stock[i][j];
        }
        printf("\n");
    }

    printf("\nNew grand total: %d units\n", grandTotal);

    return 0;
}
