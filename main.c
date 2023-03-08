#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 9 // Grid size (9*9)
#define LIST_SIZE 9 // List size (1-9)

int list[LIST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void shuffleList(){ // List shuffle function
    int i, j, temp;
    for (i = 0; i < LIST_SIZE - 1; i++) { // Browse list
        j = rand() % (LIST_SIZE - i) + i; // Random number between i and LIST_SIZE
        temp = list[i]; // Swap
        list[i] = list[j]; // Swap
        list[j] = temp; // Swap
    }
}

int main(){ // Main function
    srand(time(NULL)); // Random seed
    shuffleList(); // Shuffle list

    int grid[GRID_SIZE][GRID_SIZE] = {0}; // Grid initialization
    int i, j, k;
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            k = (i * 3 + i / 3 + j) % LIST_SIZE; // Number placement
            grid[i][j] = list[k]; // Number placement
        }
    }

    int solvedGrid[GRID_SIZE][GRID_SIZE]; // Solved grid initialization

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            solvedGrid[i][j] = grid[i][j]; // Copy grid to solved grid
        }
    }

    int num_to_remove  = 1; // Number of numbers to remove

    while (num_to_remove > 0) { // While there are numbers to remove
        int row = rand() % 9; // Choose a row at random
        int col = rand() % 9; // Choose a column at random
        if (grid[row][col] != 0) { // If the case is not empty
            grid[row][col] = 0; // Empty the case
            num_to_remove--; // Decrease the number of numbers to remove
        }
    }

    for (i = 0; i < GRID_SIZE; i++) { // Display grid
        if(i % 3 == 0)
            printf("+-------+-------+-------+\n");
        for (j = 0; j < GRID_SIZE; j++) {
            if(j % 3 == 0)
                printf("| ");
            printf("%d ", grid[i][j]);
        }
        printf("| \n");
    }
    printf("+-------+-------+-------+\n");

    // TODO: Ask the user to fill the empty cells, if the cell is already filled, tell him and display the grid, if the cell is empty and the user

    int row, col, num;
    int count = 0;
    while (count < 1) {
        printf("Enter the row: ");
        scanf("%d", &row);
        printf("Enter the col: ");
        scanf("%d",&col);
        printf("Enter the number: ");
        scanf("%d",&num);
        if (grid[row][col] != 0) {
            printf("This cell is already filled.\n");
            printf("Here is the current grid:\n");
            for (i = 0; i < GRID_SIZE; i++) {
                if(i % 3 == 0)
                    printf("+-------+-------+-------+\n");
                for (j = 0; j < GRID_SIZE; j++) {
                    if(j % 3 == 0)
                        printf("| ");
                    printf("%d ", grid[i][j]);
                }
                printf("| \n");
            }
            printf("+-------+-------+-------+\n");
        } else if (num != solvedGrid[row][col]) {
            printf("Wrong number.\n");
            printf("Here is the current grid:\n");
            for (i = 0; i < GRID_SIZE; i++) {
                if(i % 3 == 0)
                    printf("+-------+-------+-------+\n");
                for (j = 0; j < GRID_SIZE; j++) {
                    if(j % 3 == 0)
                        printf("| ");
                    printf("%d ", grid[i][j]);
                }
                printf("| \n");
            }
            printf("+-------+-------+-------+\n");
        } else {
            grid[row][col] = num;
            count++;
            printf("Here is the current grid:\n");
            for (i = 0; i < GRID_SIZE; i++) {
                if(i % 3 == 0)
                    printf("+-------+-------+-------+\n");
                for (j = 0; j < GRID_SIZE; j++) {
                    if(j % 3 == 0)
                        printf("| ");
                    printf("%d ", grid[i][j]);
                }
                printf("| \n");
            }
            printf("+-------+-------+-------+\n");
        }
    }
    printf("Congrats! You solved the puzzle.\n");

    system("pause");
    return 0;
}