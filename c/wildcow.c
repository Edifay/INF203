#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

typedef struct {
    char eyes[3];
    char langue[3];
    char *default_text;
    unsigned short lineSize;
} config;

/*FONCTION AJOUTÉES/ÉDITÉES DE NEWCOW*/
void affiche_vache(config *conf, int x, int y);
/*FIN FONCTION AJOUTÉES/ÉDITÉES DE NEWCOW*/

/*FONCTION IDENTIQUE AUX FONCTIONS NEWCOW*/
int affiche_default_text(config *conf);
config *loadDefaultConfig(int argc, char *args[]);
config *extract_params(int argc, char *args[]);
int paramDispatcher(config *conf, char *args[], int argc, int cursor);
int totalStringSize(int argc, char *args[]);
int eyes(config *conf, char *args[], int argc, int cursor);
int langue(config *conf, char *args[], int argc, int cursor);
int lineSize(config *conf, char *args[], int argc, int cursor);
/*FIN FONCTION IDENTIQUE AUX FONCTIONS NEWCOW*/

/**
 * Image une vache complètement folle qui charge en faisant de la fumé derrière elle.
 */
int main(int argc, char *args[]) {
    time_t t;
    srand((unsigned) time(&t));

    config *conf = extract_params(argc, args);
    for (int i = 100; i > 0; i--) {
        affiche_vache(conf, i, i);
        usleep(50000);
    }
}

/**
 * Generation aléatoire de la fume et des pates à l'aide de rand().
 */
void affiche_vache(config *conf, int x, int y) {
    printf("\033[H\033[J");
    int current_y = affiche_default_text(conf);

    char pates[3] = "";
    for (int i = 0; i < 2; i++)
        if (rand() % 2)
            strcpy(pates, "//");
        else
            strcpy(pates, "\\\\");

    char fume[5] = "";
    for (int i = 0; i < 4; i++)
        if (rand() % 2)
            strcat(fume, "@");
        else
            strcat(fume, " ");


    printf(""
           "\033[%d;%dH        \\  \\__\\\n"
           "\033[%d;%dH         \\  (%s)\\_______\n"
           "\033[%d;%dH            (__)\\       )\\/\\\n"
           "\033[%d;%dH             %s ||----w |\n"
           "\033[%d;%dH                %s     %s    %s\n"
           "",
           current_y + 2, x, current_y + 3, x, conf->eyes, current_y + 4, x,
           current_y + 5, x, conf->langue, current_y + 6, x, pates, pates, fume);
}







/*FONCTIONS INCHANGÉES PAS BESOIN DE RELIRE CELLES-CI. IDENTIQUE A NEWCOW*/







int affiche_default_text(config *conf) {
    int textLenght = strlen(conf->default_text);
    int lineCount = ceil(textLenght / (float) conf->lineSize);

    if (lineCount == 1 || lineCount == 0)
        conf->lineSize = strlen(conf->default_text);
    if (conf->lineSize == 0)
        return 0;

    printf(" ");
    for (int i = 0; i < conf->lineSize + 2; i++)
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

        for (int i = 0; i < conf->lineSize; i++)
            if (cursor < textLenght)
                printf("%c", conf->default_text[cursor++]);
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
    for (int i = 0; i < conf->lineSize + 2; i++)
        printf("-");
    printf("\n");

    return 1 + lineCount;
}

config *extract_params(int argc, char *args[]) {
    config *conf = loadDefaultConfig(argc, args);

    int cursor = 1;
    while (cursor < argc) {
        if (args[cursor][0] == '-')
            cursor += paramDispatcher(conf, args, argc, cursor);
        else {
            strcat(conf->default_text, args[cursor]);
            cursor++;
            if (cursor != argc)
                strcat(conf->default_text, " ");
        }
    }
    printf("Default text : %s\n", conf->default_text);
    return conf;
}

int paramDispatcher(config *conf, char *args[], int argc, int cursor) {
    char *param = args[cursor];

    if (!strcmp(param, "-e") || !strcmp(param, "--eyes"))
        return 1 + eyes(conf, args, argc, cursor + 1);
    else if (!strcmp(param, "-T"))
        return 1 + langue(conf, args, argc, cursor + 1);
    else if (!strcmp(param, "-W"))
        return 1 + lineSize(conf, args, argc, cursor + 1);

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
    conf->eyes[0] = '@';
    conf->eyes[1] = '@';
    conf->eyes[2] = '\0';

    conf->langue[0] = 'U';
    conf->langue[1] = ' ';
    conf->langue[2] = '\0';

    conf->default_text = malloc(totalStringSize(argc, args));
    strcpy(conf->default_text, "Chargez !");

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