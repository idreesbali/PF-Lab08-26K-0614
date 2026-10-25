#include <stdio.h>
int main()
{
    int seats[5][6] = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}};
    int row;
    do
    {
        int col;
        printf("Row(1-5) and Column(1-6):");
        scanf("%d %d", &row, &col);
        if (row == -1)
        {
            break;
        }
        if (row < 1 || row > 5 || col < 1 || col > 6)
        {
            printf("Error: Invalid row or column!\n");
        }
        else if (seats[row - 1][col - 1] == 1)
        {
            printf("Error: Seat already booked!\n");
            continue;
        }
        else
        {
            seats[row - 1][col - 1] = 1;
            printf("Seat booked succesfully.\n");
        }
    } while (row != -1);
    printf("\nSeating Chart:\n");
    printf("     ");
    printf("  1\t2\t3\t4\t5\t6\n");
    int maxRow = 0, empty = 0, booked = 0;
    int index = 1;
    for (int j = 0; j < 5; j++)
    {
        int rowBooking = 0;
        printf("Row %d  ", j + 1);
        for (int k = 0; k < 6; k++)
        {
            if (seats[j][k] == 0)
            {
                printf("O\t");
                empty++;
            }
            else
            {
                printf("X\t");
                booked++;
                rowBooking++;
            }
        }
        printf("\n");
        if (rowBooking > maxRow)
        {
            maxRow = rowBooking;
            index = j + 1;
        }
    }
    printf("Total booked seats: %d\n", booked);
    printf("Total empty seats: %d\n", empty);
    printf("Row with the most bookings: Row %d (%d bookings)\n",
           index, maxRow);
}