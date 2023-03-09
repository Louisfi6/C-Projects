#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void copyArray(int tab[9][9], int copy[9][9] ){ // Function to copy an array
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            copy[i][j] = tab[i][j];
        }
    }
}

void display(int tab[9][9]){ // Function to display the array
    printf("| Y\\X  "); // Display the X axis
    for(int i = 0; i < 9; i++){ // Display the Y axis
        printf("| %d ", i);
    }
    printf("|\n");

    for(int i = 0; i < 10; i++){ // Display the line separator
        printf("----");
    }

    for(int i = 0; i < 9; i++){ // Display the array
        printf("\n");
        printf("| %d >  ", i);
        for(int j = 0; j < 9; j++){
            printf("| %d ", tab[i][j]);
        }
        printf("|\n");
    }

    printf("\n");
}

int verifyRowColumn(int tab[9][9], int line, int lineOrCol ){ // Function to verify if a row or a column is correct

    int choices[9] = {0,0,0, 0,0,0, 0,0,0}; // Array to store the number of times a number appears in a row or a column
    int result = 0;
    if(lineOrCol){ // If lineOrCol is true, we verify the row
        for(int i = 0; i < 9; i++){ // We verify the row
            if(tab[i][line] > 0){ // If the number is not 0, we add 1 to the array
                int num = tab[i][line]; // We store the number in a variable
                choices[num - 1] = choices[num - 1] + 1 ;  // We add 1 to the array
            }
        }
    } else { // If lineOrCol is false, we verify the column
        for(int i = 0; i < 9; i++){ // We verify the column
            if(tab[line][i]){ // If the number is not 0, we add 1 to the array
                int num = tab[line][i]; // We store the number in a variable
                choices[num - 1] = choices[num - 1] + 1 ; // We add 1 to the array
            }
        }
    }
    for(int i = 0; i < 9; i++){ // We verify if a number appears more than once
        if(choices[i] > 1){ // If a number appears more than once, we return 1
            result = 1;
        }
    }
    return result;
}

int verifyRegion(int tab[9][9], int k, int l){ // Function to verify if a region is correct

    int choices[9] = {0,0,0, 0,0,0, 0,0,0}; // Array to store the number of times a number appears in a region
    int result = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tab[i + k*3][j + l*3] > 0){ // If the number is not 0, we add 1 to the array
                int num = tab[i + k*3][j + l*3]; // We store the number in a variable
                choices[num - 1] = choices[num - 1] + 1 ; // We add 1 to the array
            }
        }
    }
    for(int i = 0; i < 9; i++){ // We verify if a number appears more than once
        if(choices[i] > 1){ // If a number appears more than once, we return 0
            result = 0;
        }
    }
    return result;
}

void generate(int tab[9][9], int copyTableau[9][9]){ // Function to generate a sudoku

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(!(rand() % 2)){
                copyTableau[i][j] = tab[i][j]; // If the number is less than 97, we copy the number in the copy array
            }
        }
    }

}

int verifyGrid(int tab[9][9]){ // Function to verify if the sudoku is correct

    int isCorrect = 1;
    for(int i = 0; i < 9; i++ ){ // We verify if the rows and the columns are correct
        int verifLine = verifyRowColumn(tab, i, 1);
        int verifCol = verifyRowColumn(tab, i, 0);
        if(verifCol || verifLine){ // If a row or a column is incorrect, we return 0
            printf("\n\nIt seems that your solution does not correspond to the rules, try again!\n\n");
            isCorrect = 0;
        }
    }
    for(int i = 0; i < 3; i++){ // We verify if the regions are correct
        for(int j = 0; j < 3; j++){
            if(verifyRegion(tab, i, j ) == 0){  // If a region is incorrect, we return 0
                isCorrect = 0;
            }
        }
    }
    return isCorrect;
}

int enter(int tab[9][9]){ // Function to enter a number in the sudoku

    int result = 0;

    while (result == 0){ // While the number is not correct, we ask the user to enter a number
        printf("Enter the number you want to enter: ");
        scanf("%d", &result);
        if(result < 0 || result > 9){ // If the number is not between 0 and 9, we ask the user to enter a number again
            printf("Please enter a number between 0 and 9\n");
            result = 0;
        }
    }
    {
        int tableauTest[9][9] = { // Array to store the sudoku
                {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0},

                {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0},

                {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0},
                {0,0,0,0,0,0,0,0,0}
        };
        copyArray(tab, tableauTest); // We copy the sudoku in the array
        int saisie = 0;

        printf("Veuillez saisir un Y\n");
        scanf("%d", &saisie);
        int saisieX = saisie; // We store the number in a variable

        printf("Veuillez saisir un X\n");
        scanf("%d", &saisie);
        int saisieY = saisie; // We store the number in a variable

        if(tab[saisieX][saisieY]){ // If the case is not empty, we ask the user to enter a number again
            printf("Cette case est deja remplie Reessayez\n");
        } else { // If the case is empty, we ask the user to enter a number
            printf("Quelle valeur souhaitez vous inserer ?\n");
            scanf("%d", &saisie);
            int saisieVal = saisie; // We store the number in a variable
            tableauTest[saisieX][saisieY] = saisieVal; // We add the number in the array

            result = verifyGrid(tableauTest); // We verify if the sudoku is correct
            if(result == 1 ){ // If the sudoku is correct, we add the number in the sudoku
                tab[saisieX][saisieY] = saisieVal; // We add the number in the sudoku
            }
        }
    }
    return result;
}

int verifyContinue(int tab[9][9]){ // Function to verify if the sudoku is complete
    // If the sudoku is complete, we return 0
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(tab[i][j]){
                //return 0;
            }else{
                return 1;
            }
        }
    }
    return 0;
}

int main(){ // Main function

    srand( time( NULL ) ); // We initialize the random function

    int i, j;
    int solution[9][9];
    printf("SOLUTION");
    printf("\n");
    printf("---------------------------------");
    printf("\n");
    for(j=0;j<9; ++j)
    {
        for(i=0; i<9; ++i)
            solution[j][i] = (i + j*3 +j /3) %9 +1 ;
    }

    for(i=0;i<9; ++i)
    {
        for(j=0; j<9; ++j)
            printf("%d ", solution[i][j]);
        printf("\n");
    }
    printf("---------------------------------");
    printf("\n");

    int tableauJoueur[9][9] = { // Array to store the sudoku
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},

            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},

            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0,0}
    };

    // We display the sudoku
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d ", tableauJoueur[i][j]);
        }
        printf("\n");
    }
    int isTurning; // Variable to verify if the sudoku is complete
    generate(solution, tableauJoueur); // We generate the sudoku
    do{ // While the sudoku is not complete, we ask the user to enter a number
        display(tableauJoueur); // We display the sudoku
        enter(tableauJoueur); // We ask the user to enter a number
        isTurning = verifyContinue(tableauJoueur); // We verify if the sudoku is complete
    } while(isTurning); // While the sudoku is not complete, we ask the user to enter a number
    printf("Bravo, vous avez reussi l'epreuve du sudoku");
    system("pause");
    return 0;
}