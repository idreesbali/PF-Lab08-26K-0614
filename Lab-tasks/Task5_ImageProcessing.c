#include <stdio.h>

int main()
{
    int image[4][4];
    int result[4][4];
    int i, j, x, y;
    int amount, threshold;
    int pixel;
    int sum;

    printf("Enter 16 pixel values:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }

    printf("Enter brightness amount: ");
    scanf("%d", &amount);
    printf("Enter threshold: ");
    scanf("%d", &threshold);

    printf("\nOriginal image:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    printf("\nBrightness (%d):\n", amount);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            pixel = image[i][j] + amount;

            if (pixel > 255)
            {
                pixel = 255;
            }
            if (pixel < 0)
            {
                pixel = 0;
            }

            printf("%d ", pixel);
        }
        printf("\n");
    }

    printf("\nBlack and white (threshold %d):\n", threshold);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (image[i][j] >= threshold)
            {
                printf("255 ");
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

    printf("\nFlipped horizontally:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 3; j >= 0; j--)
        {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            result[i][j] = image[i][j];
        }
    }

    for (i = 1; i <= 2; i++)
    {
        for (j = 1; j <= 2; j++)
        {
            sum = 0;

            for (x = i - 1; x <= i + 1; x++)
            {
                for (y = j - 1; y <= j + 1; y++)
                {
                    sum = sum + image[x][y];
                }
            }

            result[i][j] = sum / 9;
        }
    }

    printf("\nSmoothed image:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
