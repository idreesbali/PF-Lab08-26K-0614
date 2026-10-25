#include <stdio.h>

int main()
{
    int marks[4][3];
    int i, j;
    int total[4];
    float avg[4];
    int high[3];
    int low[3];
    float subAvg[3];
    int sum;
    int topStudent = 0;
    int worstSubject = 0;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter mark for Student %d, Subject %d: ", i + 1, j + 1);
            scanf("%d", &marks[i][j]);

            while (marks[i][j] < 0 || marks[i][j] > 100)
            {
                printf("Invalid mark! Enter a value between 0 and 100.\n");
                printf("Enter mark for Student %d, Subject %d: ", i + 1, j + 1);
                scanf("%d", &marks[i][j]);
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        total[i] = 0;
        for (j = 0; j < 3; j++)
        {
            total[i] = total[i] + marks[i][j];
        }
        avg[i] = total[i] / 3.0;
    }

    printf("\nStudent    Prog  Calc  Phys  Total  Average  Grade\n");

    for (i = 0; i < 4; i++)
    {
        printf("Student %d  ", i + 1);

        for (j = 0; j < 3; j++)
        {
            printf("%4d  ", marks[i][j]);
        }

        printf("%5d  %7.2f  ", total[i], avg[i]);

        if (avg[i] >= 80)
        {
            printf("A\n");
        }
        else if (avg[i] >= 65)
        {
            printf("B\n");
        }
        else if (avg[i] >= 50)
        {
            printf("C\n");
        }
        else
        {
            printf("F\n");
        }
    }

    for (j = 0; j < 3; j++)
    {
        high[j] = marks[0][j];
        low[j] = marks[0][j];
        sum = 0;

        for (i = 0; i < 4; i++)
        {
            if (marks[i][j] > high[j])
            {
                high[j] = marks[i][j];
            }
            if (marks[i][j] < low[j])
            {
                low[j] = marks[i][j];
            }
            sum = sum + marks[i][j];
        }

        subAvg[j] = sum / 4.0;
    }

    printf("\nSubject statistics:\n");
    printf("Subject      Highest  Lowest  Average\n");
    printf("Programming  %7d  %6d  %7.2f\n", high[0], low[0], subAvg[0]);
    printf("Calculus     %7d  %6d  %7.2f\n", high[1], low[1], subAvg[1]);
    printf("Physics      %7d  %6d  %7.2f\n", high[2], low[2], subAvg[2]);

    for (i = 1; i < 4; i++)
    {
        if (avg[i] > avg[topStudent])
        {
            topStudent = i;
        }
    }

    for (j = 1; j < 3; j++)
    {
        if (subAvg[j] < subAvg[worstSubject])
        {
            worstSubject = j;
        }
    }

    printf("\nTop student: Student %d (Average %.2f)\n", topStudent + 1, avg[topStudent]);

    if (worstSubject == 0)
    {
        printf("Worst subject: Programming (Average %.2f)\n", subAvg[0]);
    }
    else if (worstSubject == 1)
    {
        printf("Worst subject: Calculus (Average %.2f)\n", subAvg[1]);
    }
    else
    {
        printf("Worst subject: Physics (Average %.2f)\n", subAvg[2]);
    }

    return 0;
}
