#include <stdlib.h>
#include <time.h>
#include <stdio.h>

/*Variables globales*/
int global_stock = 5;
int global_fitness = 5;
int duree_de_vie = 0;

/*Fonctions utilitaires*/
void afficheVache(int fitness);
void stockUpdate(int food);
void lifeUpdate(int food);
int askLunchFood();

/**
 *
 * return la nouvelle valeur comprise dans l'intervalle 0-10.
 */
int getIn0To10(int number) {
    if (number > 10) return 10;
    if (number < 0) return 0;
    return number;
}

/*Boucle du jeu et logique principale.*/
int main(int argc, char *args[]) {
    time_t t;
    srand((unsigned) time(&t));

    int food;
    while (global_fitness != 0 && global_fitness != 10) {
        system("clear");
        afficheVache(global_fitness);
        // printf("fitness : %d\n", global_fitness); // Ligne de triche !
        printf("Vous avez %d rations en stock. Combien voulez-vous en utiliser : ", global_stock);
        food = askLunchFood();
        stockUpdate(food);
        lifeUpdate(food);
        duree_de_vie++;
    }

    system("clear");
    afficheVache(global_fitness);
    printf("Vous avez survécu %d jours.\n", duree_de_vie);

    return 0;
}

/**
 * Fonction qui demande le nombre de ration à consommer, et fait en sorte que la valeur soit juste.
 *
 * @return le nombre de ration à consommer.
 */
int askLunchFood() {
    int food = -1;
    do {
        if (food != -1)
            printf("La valeur de rations à utiliser n'est pas valide réassayez : ");
        scanf("%d", &food);
    } while (food < 0 || food > global_stock);
    return food;
}

/**
 * Calcule le nouveau stock à partir du nombre de ration consommé.
 */
void stockUpdate(int food) {
    global_stock -= food + (rand() % 6) - 3;
    global_stock = getIn0To10(global_stock);
}

/**
 * Calcule la nouvelle vie de la vache à partir de la consommation de nourriture.
 */
void lifeUpdate(int food) {
    global_fitness += food - (rand() % 3);
    global_fitness = getIn0To10(global_fitness);
}

/**
 * Affiche la vache selon le param fitness.
 *
 * 0,10 -> dead
 * 1-3, 7-9 -> sick
 * 4-6 -> happy
 *
 * @param fitness
 */
void afficheVache(int fitness) {
    switch (fitness) {
        case 0:
        case 10:
            system("./newcow --dead ...");
            break;
        case 1:
        case 2:
        case 3:
        case 7:
        case 8:
        case 9:
            system("./newcow --sick Meu...");
            break;
        case 4:
        case 5:
        case 6:
            system("./newcow --happy Meuuuu !!");
            break;
    }
}