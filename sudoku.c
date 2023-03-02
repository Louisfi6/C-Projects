#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 9 //taille de la grille (9 par 9)
#define LIST_SIZE 9 //taille de la liste

int list[LIST_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void shuffleList() //FONCTION QUI VA MÉLANGER LA SUITE DE NOMBRE
{
    int i, j, temp;
    for (i = 0; i < LIST_SIZE - 1; i++) { //parcourir la liste des nombres à mélanger
        j = rand() % (LIST_SIZE - i) + i;
        //algo de fisher yates pour mélanger les nombres
        temp = list[i];
        list[i] = list[j];
        list[j] = temp;
    }
}

int main() { //FONCTION PRINCIPALE QUI VA SUPPRIMER DES CASES, AFFICHER LA GRILLE DE BASE PUIS LA SOLUTION
    srand(time(NULL));
    shuffleList();

    int grid[GRID_SIZE][GRID_SIZE] = {0}; //création du tableau en 2D
    int i, j, k; //variables pour les itérations
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            k = (i * 3 + i / 3 + j) % LIST_SIZE; // Calcul de la position du prochain numéro à placer
            grid[i][j] = list[k]; // Placement du numéro dans la grille
        }
    }

    int solvedGrid[GRID_SIZE][GRID_SIZE]; //on copie la grid dans solvedGrid

    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            solvedGrid[i][j] = grid[i][j]; //on parcourt la grid puis on copie les éléments dans solvedGrid. Au final on
                                           //va venir compléter les cases = 0 par les chiffres manquants
        }
    }

    int num_to_remove  = 30; //30 nombres doivent être supprimés

    while (num_to_remove > 0) {
        int row = rand() % 9; //choisir une ligne au hasard
        int col = rand() % 9; //choisir une colone au hasard
        if (grid[row][col] != 0) { //si la grille avec la colone + ligne choisies est différent de 0
            grid[row][col] = 0; // on met la case à 0
            num_to_remove--; //décrémentation pour arriver enfin à 30 nombres supprimés
        }
    }

    for (i = 0; i < GRID_SIZE; i++) { // boucle for qui va afficher la grid
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

    printf("\n\n Here is the solution :\n");

    for (i = 0; i < GRID_SIZE; i++) { // boucle for qui va afficher la solvedGrid
        if(i % 3 == 0)
            printf("+-------+-------+-------+\n");
        for (j = 0; j < GRID_SIZE; j++) {
            if(j % 3 == 0)
                printf("| ");
            printf("%d ", solvedGrid[i][j]);
        }
        printf("| \n");
    }
    printf("+-------+-------+-------+\n");

    system("pause");

    return 0;
}