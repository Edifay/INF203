/*
 * Il est préférable d'avoir lu newcow.c avant ce fichier.
 * Il réutilise la plupart des fonctions de celui-ci.
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* CONFIGURATION MODIFIÉE */
typedef struct {
    char eyes[3];
    char langue[3];
    char *default_text;
    char *display;
    FILE *input;
    unsigned short lineSize;
} config;

/*FONCTION AJOUTÉES/ÉDITÉES DE NEWCOW*/
int animateRead(config *conf);

config *extract_params(int argc, char *args[]);

int stdinOption(config *conf, char *args[], int argc, int cursor);
/*FIN FONCTION AJOUTÉES/ÉDITÉES DE NEWCOW*/

/*FONCTION IDENTIQUE AUX FONCTIONS NEWCOW*/
void affiche_vache(config *conf);
void affiche_display_text(config *conf);
config *loadDefaultConfig(int argc, char *args[]); // added "conf->input = NULL;"
int paramDispatcher(config *conf, char *args[], int argc, int cursor); // just added stdinOption.
int totalStringSize(int argc, char *args[]);
int eyes(config *conf, char *args[], int argc, int cursor);
int langue(config *conf, char *args[], int argc, int cursor);
int lineSize(config *conf, char *args[], int argc, int cursor);
/*FIN FONCTION IDENTIQUE AUX FONCTIONS NEWCOW*/

/**
 * Fonction principale. Extrait la configuration des arguments.
 * L'extraction marche différemment, car elle extrait une struct FILE.
 *
 * Si l'extraction du fichier de lecture n'as pas fonctionné. Alors le programme s'arrête avec un message d'erreur.
 *
 * Si l'extraction du fichier de lecture as fonction avec succès nous rentrons dans la boucle de la lecture.
 *
 * La contenu de la boucle ne se charge que de l'affichage. Mais la condition dans la boucle appellant animateRead(conf). Va modifier la configuration pour changer l'affichage.
 *
 * animateRead(conf) retourne faux ou vrai selon si la lecture du fichier est terminée ou non.
 *
 */
int main(int argc, char *args[]) {
    config *conf = extract_params(argc, args);

    if (conf->input == NULL) {
        printf("Le fichier de lecture n'as pas pu être ouvert !\n");
        return -1;
    }

    do {
        printf("\033[H\033[J");
        affiche_vache(conf);
        usleep(30000);
    } while (animateRead(conf));

    printf("\033[H\033[J");
    conf->langue[0] = ' ';
    affiche_vache(conf);

    return 0;
}

/**
 *
 * Récupère le fichier de lecture de la config, lit un nouveau caractère et déplace tout les caractères de leur place à la suivante.
 * Suivant ce protocole :
 *
 *  Ficher -> Langue[0] -> displayText(happened)
 *
 * Le caractère '\n' est transformé en ' '.
 *
 * @param conf
 * @return false si le fichier est vide, ou que le caractère lu est le caractère terminal. true sinon. Le caractère terminal est '&'.
 */
int animateRead(config *conf) {
    unsigned long cursor = strlen(conf->display);

    conf->display[cursor] = conf->langue[0];
    conf->display[cursor + 1] = '\0';

    fscanf(conf->input, "%c", &conf->langue[0]);

    if (conf->langue[0] == '\n')
        conf->langue[0] = ' ';

    return !feof(conf->input) && conf->langue[0] != '&';
}

/**
 * Même fonctionnement que dans newcow.c.
 *
 * Sauf sur la gestion de conf->input.
 * L'option "-default" permet de choisir stdin comme fichier de lecture.
 *
 * Si après avoir extrait toutes les options le fichier de lecture n'as pas été défini (à l'aide de -default).
 * Alors il faut essayer d'ouvrir un fichier de lecture avec comme nom le default_text.
 *
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
                strcat(conf->default_text, " ");
            strcat(conf->default_text, args[cursor]);
            cursor++;
        }
    }

    if (conf->input == NULL)
        conf->input = fopen(conf->default_text, "r");

    if (conf->input != NULL)
        fscanf(conf->input, "%c", &conf->langue[0]);

    return conf;
}

/**
 * Défini le fichier de lecture sur stdin.
 *
 * @return 0. (nombre d'argument consommé)
 */
int stdinOption(config *conf, char *args[], int argc, int cursor) {
    conf->input = stdin;
    return 0;
}




/*FONCTIONS INCHANGÉES PAS BESOIN DE RELIRE CELLES-CI. IDENTIQUE A NEWCOW*/





int paramDispatcher(config *conf, char *args[], int argc, int cursor) {
    char *param = args[cursor];

    if (!strcmp(param, "-e") || !strcmp(param, "--eyes"))
        return 1 + eyes(conf, args, argc, cursor + 1);
    else if (!strcmp(param, "-T"))
        return 1 + langue(conf, args, argc, cursor + 1);
    else if (!strcmp(param, "-W"))
        return 1 + lineSize(conf, args, argc, cursor + 1);
    else if (!strcmp(param, "-default"))
        return 1 + stdinOption(conf, args, argc, cursor + 1);

    printf("Parametre %s inconnu !\n", args[cursor]);
    exit(-1);
}

int eyes(config *conf, char *args[], int argc, int cursor) {
    int i;
    for (i = 0; i < 2 && args[cursor][i] != '\0'; i++) {
        conf->eyes[i] = args[cursor][i];
    }
    conf->eyes[i] = '\0';
    return 1;
}

int langue(config *conf, char *args[], int argc, int cursor) {
    int i;
    for (i = 0; i < 2 && args[cursor][i] != '\0'; i++) {
        conf->langue[i] = args[cursor][i];
    }
    conf->langue[i] = '\0';
    return 1;
}

int lineSize(config *conf, char *args[], int argc, int cursor) {
    short value;
    sscanf(args[cursor], "%hu", &value);
    conf->lineSize = value;
    return 1;
}

config *loadDefaultConfig(int argc, char *args[]) {
    config *conf = malloc(sizeof(config));
    conf->eyes[0] = 'o';
    conf->eyes[1] = 'o';
    conf->eyes[2] = '\0';

    conf->langue[0] = ' ';
    conf->langue[1] = ' ';
    conf->langue[2] = '\0';

    conf->default_text = malloc(totalStringSize(argc, args));
    conf->default_text[0] = '\0';

    conf->display = malloc(sizeof(char[1000]));
    conf->display[0] = '\0';

    conf->input = NULL;

    conf->lineSize = 40;
    return conf;
}

int totalStringSize(int argc, char *args[]) {
    int count = 0;
    for (int i = 1; i < argc; i++) {
        for (int j = 0; args[i][j] != '\0'; j++)
            count++;
        count++;
    }
    return count;
}


void affiche_vache(config *conf) {
    affiche_display_text(conf);

    printf("        \\   ^__^\n");
    printf("         \\  (%s)\\_______\n", conf->eyes);
    printf("            (__)\\       )\\/\\\n");
    printf("             %s ||----w |\n", conf->langue);
    printf("                ||     ||\n");
}


void affiche_display_text(config *conf) {
    int textLenght = (int) strlen(conf->display);
    int lineCount = (int) ceilf((float) textLenght / (float) conf->lineSize);
    int lineSize = conf->lineSize;

    if (lineCount == 1 || lineCount == 0)
        lineSize = textLenght;
    if (lineSize == 0)
        return;

    printf(" ");
    for (int i = 0; i < lineSize + 2; i++)
        printf("_");
    printf("\n");

    int cursor = 0;
    for (int i = 0; i < lineCount; i++) {
        if (lineCount == 1)
            printf("< ");
        else if (i == 0)
            printf("/ ");
        else if (i == lineCount - 1)
            printf("\\ ");
        else
            printf("| ");

        for (int j = 0; j < lineSize; j++)
            if (cursor < textLenght)
                printf("%c", conf->display[cursor++]);
            else
                printf(" ");

        if (lineCount == 1)
            printf(" >\n");
        else if (i == 0)
            printf(" \\\n");
        else if (i == lineCount - 1)
            printf(" /\n");
        else
            printf(" |\n");
    }

    printf(" ");
    for (int i = 0; i < lineSize + 2; i++)
        printf("-");
    printf("\n");
}