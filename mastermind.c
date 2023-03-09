#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define LIST_SIZE 6

int list[LIST_SIZE] = {1, 2, 3, 4, 5, 6};

// On génère une liste de 4 nombres aléatoires à partir d'une liste de 6 nombres.
void generer(){
    int i, j, temp;
    for (i = 0; i < LIST_SIZE - 1; i++) { // Browse list
        j = rand() % (LIST_SIZE - i) + i; // Random number between i and LIST_SIZE
        temp = list[i]; // Swap
        list[i] = list[j]; // Swap
        list[j] = temp; // Swap
    }
}


void afficher(char lettre[4]) {
    int i;
    printf("\nCe qu'il faut deviner : \n");
    printf("+---+---+---+---+\n");

    for (i = 0; i < 4; i++) {
        switch (list[i]) {
            case 1:
                lettre[i] = 'P';
                break;
            case 2:
                lettre[i] = 'B';
                break;
            case 3:
                lettre[i] = 'M';
                break;
            case 4:
                lettre[i] = 'Y';
                break;
            case 5:
                lettre[i] = 'O';
                break;
            case 6:
                lettre[i] = 'G';
                break;
        }
        printf("| %c ", lettre[i]);
    }
    printf("|\n");
    printf("+---+---+---+---+\n");
}


void saisir(char lettre2[4]){
    int i;
    for (i = 0; i < 4; i++) {
        printf("\nEntrez une lettre entre P - B - M - Y - O - G:");
        scanf("%c", &lettre2[i]);
        getchar();
    }
    printf("\n+---+---+---+---+");
    printf("\n| %c | %c | %c | %c |\n", lettre2[0], lettre2[1], lettre2[2], lettre2[3]);
    printf("+---+---+---+---+\n");
}


//fonction qui affiche le nombre de case bien pkacé et le nombre de case mal place
void verifier(char lettre[4], char lettre2[4]){
    int i, j, bien_place = 0, mal_place = 0;
    for (i = 0; i < 4; i++) {
        if (lettre[i] == lettre2[i]) {
            bien_place++;
        } else {
            for (j = 0; j < 4; j++) {
                if (lettre[i] == lettre2[j]) {
                    mal_place++;
                }
            }
        }
    }
    printf("\nNombre de case bien place : %d", bien_place);
    printf("\nNombre de case mal place : %d", mal_place);
}

// Fonction principale
int main(){

    char lettre2[4];
    char lettre[4];
    int count = 0;
    srand(time(NULL)); // Random seed
    generer();
    afficher(lettre);
    do{
        //afficher(lettre);
        saisir(lettre2);
        verifier(lettre, lettre2);
        if(lettre[0] != lettre2[0] || lettre[1] != lettre2[1] || lettre[2] != lettre2[2] || lettre[3] != lettre2[3]) {
            printf("\n\nCe n'est pas la bonne combinaison !\n\n");
        } else {
            printf("\nBravo ! Vous avez gagne !\n");
        }
        count ++;
    }while(count < 10 && (lettre[0] != lettre2[0] || lettre[1] != lettre2[1] || lettre[2] != lettre2[2] || lettre[3] != lettre2[3]));

    system("pause");
    return 0;
}
