#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*CONFIGURATION DE LA VACHES*/
typedef struct {
    char eyes[3];
    char langue[3];
    char *displayText;
    unsigned short lineSize;
} config;

/*FONCTIONS PRINCIPALES*/
config *loadDefaultConfig(int argc, char *args[]);
config *extract_params(int argc, char *args[]);
int paramDispatcher(config *conf, char *args[], int argc, int cursor);
int totalStringSize(int argc, char *args[]);
void affiche_vache(config *conf);
void affiche_display_text(config *conf);
/*FIN FONCTIONS PRINCIPALES*/

/*FONCTIONS OPTIONS*/
int eyes(config *conf, char *args[], int argc, int cursor);
int langue(config *conf, char *args[], int argc, int cursor);
int lineSize(config *conf, char *args[], int argc, int cursor);
int deadCow(config *conf, char *args[], int argc, int cursor);
int sickCow(config *conf, char *args[], int argc, int cursor);
int happyCow(config *conf, char *args[], int argc, int cursor);
/*FIN FONCTIONS OPTIONS*/

/**
 * Fonction principale génère la configuration de la vache à partir des arguments passé à la commande. Puis affiche la vache.
 *
 *
 * @param argc le nombre d'arguments donné.
 * @param args les arguments.
 */
int main(int argc, char *args[]) {
    config *conf = extract_params(argc, args);
    affiche_vache(conf);
    return 0;
}

/*CORE IMPLEMENTATION*/
/**
 * Cette fonction alloue de l'espace mémoire pour stocker une configuration. Et initialise cette configuration avec les valeurs par default.
 *
 * Utilises les arguments pour estimé la taille du text à afficher par la vache.
 *
 * @return retourne la configuration par default.
 */
config *loadDefaultConfig(int argc, char *args[]) {
    config *conf = malloc(sizeof(config));
    conf->eyes[0] = 'o';
    conf->eyes[1] = 'o';
    conf->eyes[2] = '\0';

    conf->langue[0] = ' ';
    conf->langue[1] = ' ';
    conf->langue[2] = '\0';

    conf->displayText = malloc(totalStringSize(argc, args));
    conf->displayText[0] = '\0';

    conf->lineSize = 40;
    return conf;
}

/**
 *  Cette fonction appelle la fonction loadDefaultConfig et récupère donc la configuration par default.
 *  Elle va ensuite à partir des arguments extraires les données et modifier la configuration en fonctions de ceux ci.
 *
 *  Le système d'option est très solide et permet pas mal de choses.
 *  Nous avons considéré les arguments comme un flux de mot. Nous avons créé une variable "cursor" qui enregistre
 *  la position actuelle de notre lecture du flux.
 *
 *  Si un argument commence par un '-' il est considéré comme une option. L'argument est donc passé à la fonction
 *  "paramDispatcher" qui va se charger d'exécuter la fonction associé à l'option courante.
 *  Une option peu consumer un/plusieurs arguments dont il est suivis. Par exemple : "-e 'xx'", ici l'option "-e"
 *  consume l'argument 'xx' en ajoutant 1 au cursor.
 *
 *  Si un argument ne commence pas par un '-' il est considéré comme le text à afficher par la vache. Il est directement
 *  ajouté à la variable "displayText" de la config.
 *
 * @return la configuration customisé à l'aide des arguments.
 */
config *extract_params(int argc, char *args[]) {
    config *conf = loadDefaultConfig(argc, args);

    int cursor = 1;
    int space = 0;
    while (cursor < argc) {
        if (args[cursor][0] == '-')
            cursor += paramDispatcher(conf, args, argc, cursor);
        else {
            if (!space)
                space = 1;
            else
                strcat(conf->displayText, " ");
            strcat(conf->displayText, args[cursor]);
            cursor++;
        }
    }
    return conf;
}

/**
 * Distribue l'option courante (args[cursor]) à sa fonction associée.
 *
 * Si aucune fonction n'est associé à cette option alors le programme s'arrête avec un message d'erreur.
 *
 * @param conf la config à modifier.
 * @param args args.
 * @param argc argc.
 * @param cursor l'index au quel l'option a été détecté. Par exemple : args[cursor] = "--eyes".
 *
 * @return le nombre d'argument consumé par l'option.
 */
int paramDispatcher(config *conf, char *args[], int argc, int cursor) {
    char *param = args[cursor++];

    if (!strcmp(param, "-e") || !strcmp(param, "--eyes"))
        return 1 + eyes(conf, args, argc, cursor);
    else if (!strcmp(param, "-T"))
        return 1 + langue(conf, args, argc, cursor);
    else if (!strcmp(param, "-W"))
        return 1 + lineSize(conf, args, argc, cursor);
    else if (!strcmp(param, "-d") || !strcmp(param, "--dead"))
        return 1 + deadCow(conf, args, argc, cursor);
    else if (!strcmp(param, "-s") || !strcmp(param, "--sick"))
        return 1 + sickCow(conf, args, argc, cursor);
    else if (!strcmp(param, "-ha") || !strcmp(param, "--happy"))
        return 1 + happyCow(conf, args, argc, cursor);


    printf("Paramètre %s inconnu !\n", args[cursor]);
    exit(-1);
}

/**
 * Estime la taille du texte par default maximale utilisé pour créer la config de bonne taille.
 *
 * @return the estimated size of displayText.
 */
int totalStringSize(int argc, char *args[]) {
    int count = 0;
    for (int i = 1; i < argc; i++) {
        for (int j = 0; args[i][j] != '\0'; j++)
            count++;
        count++;
    }
    return count;
}

/**
 * La fonction qui affiche une vache à partir d'une configuration donné en paramètre.
 *
 * Appelle la fonction affiche_display_text(conf), pour afficher le message.
 *
 * Puis affiche la vache.
 *
 * @param conf the configuration of the cow at display.
 */
void affiche_vache(config *conf) {
    affiche_display_text(conf);

    printf("        \\   ^__^\n");
    printf("         \\  (%s)\\_______\n", conf->eyes);
    printf("            (__)\\       )\\/\\\n");
    printf("             %s ||----w |\n", conf->langue);
    printf("                ||     ||\n");
}

/**
 * Créer l'encadrement du message, et affiche le message de la vache.
 *
 * @param conf la configuration utilisé pour afficher le message.
 */
void affiche_display_text(config *conf) {
    int textLenght = (int) strlen(conf->displayText);
    // precalculate the line count.
    int lineCount = (int) ceilf((float) textLenght / (float) conf->lineSize);
    // create a copy of the lineSize, to edit it and keeping the config unchanged.
    int lineSize = conf->lineSize;

    // Resize the box width if it contains only 1 line.
    if (lineCount == 1)
        lineSize = (int) strlen(conf->displayText);
    if (lineSize == 0 || lineCount == 0) // return if the message is empty.
        return;

    // top border
    printf(" ");
    for (int i = 0; i < lineSize + 2; i++)
        printf("_");
    printf("\n");

    int cursor = 0;
    for (int i = 0; i < lineCount; i++) {
        if (lineCount == 1) // left border
            printf("< ");
        else if (i == 0)
            printf("/ ");
        else if (i == lineCount - 1)
            printf("\\ ");
        else
            printf("| ");

        for (int j = 0; j < lineSize; j++) // message
            if (cursor < textLenght)
                printf("%c", conf->displayText[cursor++]);
            else
                printf(" ");

        if (lineCount == 1) // right border
            printf(" >\n");
        else if (i == 0)
            printf(" \\\n");
        else if (i == lineCount - 1)
            printf(" /\n");
        else
            printf(" |\n");
    }

    printf(" "); // bottom border
    for (int i = 0; i < lineSize + 2; i++)
        printf("-");
    printf("\n");
}
/*END CORE IMPLEMENTATION*/

/*OPTIONS FUNCTION IMPLEMENTATION*/
/**
 * Edit the eyes text.
 * @return 1. (nombre d'argument consommé)
 */
int eyes(config *conf, char *args[], int argc, int cursor) {
    int i;
    for (i = 0; i < 2 && args[cursor][i] != '\0'; i++) {
        conf->eyes[i] = args[cursor][i];
    }
    conf->eyes[i] = '\0';
    return 1;
}

/**
 * Edit the langue text.
 * @return 1. (nombre d'argument consommé)
 */
int langue(config *conf, char *args[], int argc, int cursor) {
    int i;
    for (i = 0; i < 2 && args[cursor][i] != '\0'; i++)
        conf->langue[i] = args[cursor][i];
    conf->langue[i] = '\0';
    return 1;
}

/**
 * Edit the conf with specified lineSize.
 * @return 1. (nombre d'argument consommé)
 */
int lineSize(config *conf, char *args[], int argc, int cursor) {
    short value;
    sscanf(args[cursor], "%hu", &value);
    conf->lineSize = value;
    return 1;
}

/**
 * Edit the conf with eyes and langue text to represent a dead cow.
 * @return 0. (nombre d'argument consommé)
 */
int deadCow(config *conf, char *args[], int argc, int cursor) {
    conf->eyes[0] = 'X';
    conf->eyes[1] = 'X';

    conf->langue[0] = 'U';
    return 0;
}

/**
 * Edit the conf with eyes and langue text to represent a sick cow.
 * @return 0. (nombre d'argument consommé)
 */
int sickCow(config *conf, char *args[], int argc, int cursor) {
    conf->eyes[0] = '*';
    conf->eyes[1] = '*';

    conf->langue[0] = 'u';
    return 0;
}

/**
 * Edit the conf with eyes text to represent an happy cow.
 * @return 0. (nombre d'argument consommé)
 */
int happyCow(config *conf, char *args[], int argc, int cursor) {
    conf->eyes[0] = 'O';
    conf->eyes[1] = 'O';
    return 0;
}
/*END OPTIONS FUNCTION IMPLEMENTATION*/