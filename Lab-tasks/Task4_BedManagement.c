#include <stdio.h>

int main()
{
    int beds[2][3][2];
    int f, w, b;
    int choice = 0;
    int floor, id;
    int done, found;
    int occupied, floorCount;
    int bestFloor, bestWard, bestOcc;
    float percent;

    for (f = 0; f < 2; f++)
    {
        for (w = 0; w < 3; w++)
        {
            for (b = 0; b < 2; b++)
            {
                beds[f][w][b] = 0;
            }
        }
    }

    while (choice != 4)
    {
        printf("\n--- Hospital Menu ---\n");
        printf("1. Admit\n");
        printf("2. Discharge\n");
        printf("3. Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter floor (1-2): ");
            scanf("%d", &floor);
            printf("Enter patient ID: ");
            scanf("%d", &id);

            if (floor < 1 || floor > 2)
            {
                printf("Invalid floor!\n");
            }
            else
            {
                done = 0;

                for (w = 0; w < 3; w++)
                {
                    for (b = 0; b < 2; b++)
                    {
                        if (done == 0 && beds[floor - 1][w][b] == 0)
                        {
                            beds[floor - 1][w][b] = id;
                            printf("Patient %d admitted: Floor %d, Ward %d, Bed %d.\n", id, floor, w + 1, b + 1);
                            done = 1;
                        }
                    }
                }

                if (done == 0)
                {
                    printf("Floor %d is full.\n", floor);
                }
            }
        }
        else if (choice == 2)
        {
            printf("Enter patient ID: ");
            scanf("%d", &id);

            found = 0;

            for (f = 0; f < 2; f++)
            {
                for (w = 0; w < 3; w++)
                {
                    for (b = 0; b < 2; b++)
                    {
                        if (found == 0 && beds[f][w][b] == id)
                        {
                            beds[f][w][b] = 0;
                            printf("Patient %d discharged from Floor %d, Ward %d, Bed %d.\n", id, f + 1, w + 1, b + 1);
                            found = 1;
                        }
                    }
                }
            }

            if (found == 0)
            {
                printf("Patient ID %d not found.\n", id);
            }
        }
        else if (choice == 3)
        {
            printf("\n--- Occupancy Report ---\n");
            bestOcc = -1;
            bestFloor = 1;
            bestWard = 1;

            for (f = 0; f < 2; f++)
            {
                printf("Floor %d\n", f + 1);
                floorCount = 0;

                for (w = 0; w < 3; w++)
                {
                    occupied = 0;

                    for (b = 0; b < 2; b++)
                    {
                        if (beds[f][w][b] != 0)
                        {
                            occupied++;
                        }
                    }

                    printf("Ward %d: Occupied %d, Vacant %d\n", w + 1, occupied, 2 - occupied);
                    floorCount = floorCount + occupied;

                    if (occupied > bestOcc)
                    {
                        bestOcc = occupied;
                        bestFloor = f + 1;
                        bestWard = w + 1;
                    }
                }

                percent = floorCount * 100.0 / 6;
                printf("Floor occupancy: %.1f%%\n", percent);

                if (percent > 80)
                {
                    printf("WARNING: Floor %d is more than 80%% full.\n", f + 1);
                }
            }

            printf("Highest occupancy: Floor %d, Ward %d (%d occupied)\n", bestFloor, bestWard, bestOcc);
        }
        else if (choice != 4)
        {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
