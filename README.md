# Compte Rendu

Compte Rendu du projet d'inf203.

Toutes les sources sont disponibles (*ici dans le compte rendu, mais aussi dans le repo git*).

``Arnaud ALET``  &  ``Abdelkader Al Akoum``.

# Shell

## cow_kindergarten.sh

```shell
for i in `seq 1 9`
do
    clear
    cowsay $i
    sleep 1
done
clear
cowsay -T U. 10
```

#### Commentaire

- Itération simple de 1 à 9.
- Puis affichage de 10 avec la langue.

#### Exécution

- `./cow_kindergarten.sh`
```text
...
 ___
< 5 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 6 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 7 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 8 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
...
```
___
## cow_primaryshcool.sh

```shell
if [ $# -lt 1 ]
then
    echo "Vous devez donner un nombre"
    exit -1
fi

for i in `seq 1 $(expr $1 - 1)`
do
    clear
    cowsay $i
    sleep 1
done
clear
cowsay -T U. $1
```

#### Commentaire :

- Vérification de l'existence de l'argument.
- Puis itération de 1 à n-1.
- Puis affichage de n avec la langue.


#### Exécution

- `./cow_primaryshcool.sh 4`
```text
< 1 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 2 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 3 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 4 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             U. ||----w |
                ||     ||
```
___
## cow_highschool.sh

```shell
if [ $# -lt 1 ]
then
    echo "Vous devez donner un nombre"
    exit -1
fi

for i in `seq 1 $(expr $1 - 1)`
do
    clear
    cowsay $(expr $i '*' $i)
    sleep 1
done
clear
cowsay -T U. $(expr $1 '*' $1)
```

#### Commentaire

- Vérification de l'existence de l'argument.
- Itération de 1 à n-1 avec affichage du carré de la valeur.
- Puis affichage de n² avec la langue.


#### Exécution

- `./cow_highschool.sh 4`
```text
 ___
< 1 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 4 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 9 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ____
< 16 >
 ----
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             U. ||----w |
                ||     ||
```
___
## cow_college.sh


```shell
if [ $# -lt 1 ]
then
    echo "Vous devez donner un nombre"
    exit -1
fi


u0=0
u1=1
for i in `seq 1 $(expr $1 - 1)`
do
    clear
    temp=$u1
    u1=$(expr $u0 + $u1)
    u0=$temp
    cowsay $u1
    sleep 1
done
clear
cowsay -T U. $(expr $u0 + $u1)
```

#### Commentaire

- Verification de l'argument.
- Puis création de u0 et u1.
- Utilisation d'une boucle while, calculer jusqu'à ce que `u(n+1) < n`.

#### Exécution

- `./cow_college.sh 15`

```text
 ___
< 1 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 2 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 3 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 5 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ___
< 8 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ____
< 13 >
 ----
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             U. ||----w |
                ||     ||
```
___
## cow_university.sh

```shell
if [ $# -lt 1 ]
then
    echo "Vous devez donner un nombre"
    exit -1
fi

for i in `seq 2 $(expr $1)`
do

    flag=1
    for div in `seq 2 $(expr $i - 1)`
    do
        if [ $(expr $i % $div) -eq 0 ]
        then
            flag=0
        fi
    done
    if [ $flag -eq 1 ]
    then
        clear
        cowsay $i
        sleep 1
    fi
done
```

#### Commentaire

- Verification de l'argument.
- Boucle for i de 1 à n-1. 
  - Vérification pour chaque i si i est divisible par un nombre (plus petit que lui).
  - S'il n'est pas divisible l'afficher.


#### Exécution

- `./cow_university.sh 15`
```text
...
 ___
< 7 >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ____
< 11 >
 ----
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ____
< 13 >
 ----
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```
___
## smart_cow.sh

```shell
if [ $# -lt 1 ]
then
    echo "Ecrivez un calcul par exemple 3+11"
    exit -1
fi

operator='empty'

if [[ "$1" == *'+'* ]]
then
    operator='+'
elif [[ "$1" == *'-'* ]]
then
    operator='-'
elif [[ "$1" == *'*'* ]]
then
    operator='*'
elif [[ "$1" == *'/'* ]]
then
    operator='/'
fi

if [ "$operator" == "empty" ]
then
    echo "Operateur non trouvé !"
    exit -1
fi

first=$(echo "$1" | cut -d "$operator" -f 1)
second=$(echo "$1" | cut -d "$operator" -f 2)

cowsay -T U. -e $(expr $first "$operator" $second) "$1"
```

#### Commentaire

- Verification de l'existence de l'argument.
- Determination de l'opérateur en détectant lequel est contenu dans l'argument à l'aide de `*operateur*`.
- Verification de l'existence de l'opérateur.
- Utilisation de cut pour extraire les 2 parties du calcul (à droite, et à gauche de l'opérateur).
- Puis affichage de cowsay en effectuant le calcul.

#### Exécution

- `./smart_cow.sh '4 * 12'`
```text
 ________
< 4 * 12 >
 --------
        \   ^__^
         \  (48)\_______
            (__)\       )\/\
             U. ||----w |
                ||     ||

```
- `./smart_cow.sh 4+12`
```text
 ______
< 4+12 >
------
        \   ^__^
         \  (16)\_______
            (__)\       )\/\
             U. ||----w |
                ||     ||
```


## crazy_cow.sh

```shell
if  [ $# -ne 3 ]
then
  echo "Vous devez rentrez les 3 coefficients de votre polynome : a b c."
  exit 10
fi

delta=$(bc <<< "scale=4; ($2*$2)-(4*$1*$3)")

if [ "$delta" -lt 0 ]
then
  cowsay "Le polynome $1x² + $2x + $3 n'as pas de racines !"
elif [ "$delta" -gt 0 ]
then
  echo "Le polynome $1x² + $2x + $3 a 2 racines."
  delta=$(bc <<< "scale=4; sqrt($delta)")
  cowsay "r1 = $(bc <<< "scale=4; ((-($2))+$delta)/(2*$1)")  et    r2 = $(bc <<< "scale=4; ((-($2))-$delta)/(2*$1)")"
else
  echo "Le polynome $1x² + $2x + $3 a 1 racines."
  cowsay "r = $(bc <<< "scale=4; (-($2))/(2*$1)")"
fi
```

#### Commentaire :

Ce code vise à déterminer les racines d'un polynome du second degrès ax² + bx + c.

- Verification des 3 arguments.
- Calcul du delta.
- 3 cas exhaustif en fonction de la valeur de delta :
  - delta < 0 : pas de solutions.
  - delta = 0 : 1 solution.
    - calcul de la solution
  - delta > 0 : 2 solutions.
    - calcul des 2 solutions.




#### Exécution :


- `./crazy_cow.sh 4 -4 1` (*1 racine*)

```text
Le polynome 4x² + -4x + 1 a 1 racines.
 ___________
< r = .5000 >
 -----------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

- `./crazy_cow.sh -1 -5 -3` (*2 racines*)

```text
Le polynome -1x² + -5x + -3 a 2 racines.
 _____________________________
< r1 = -4.3027 et r2 = -.6972 >
 -----------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

- `./crazy_cow.sh 1 0 5` (*sans racine*)
```text
 ______________________________________
/ Le polynome 1x² + 0x + 5 n'as pas de \
\ racines !                            /
 --------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```



# C


Les fichiers `.c` ont été compilé avec `clang`. Avec l'option `-lm` pour inclure la fonction `ceil()` durant la compilation.

Exemple : `clang new_cow.c -lm -o newcow`


## new_cow.c
```c
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
```

#### Commentaire :

Reproduction de cowsay de façon assez similaire. Nous avons ajouté plusieurs options du man de `cowsay`.

Pour l'option à ajouter, nous avons pris le choix "techniquement élaboré". Nous avons implémenté une gestion complète des options, qui peuvent être utilisé toutes en même temps et n'importe où dans la commande. 

Concernant le message de `cowsay` nous avons essayé de se rapprocher le plus possible de l'original. Le cadre du message s'adapte en fonction du message à afficher (longueur). Mais aussi à la taille maximum de la ligne choisie, `40` par default, modifiable avec l'option `-W`.

Les options implémentées :
 - `-e` & `--eyes` -> change les yeux de la vache
 - `-T`               -> change la langue de la vache.
 - `-W`               -> change la taille de la ligne du message.
 - `-d` & `--dead`      -> change les yeux et la langue pour représenter une vache morte.
 - `-s` & `--sick`      -> change les yeux et la langue pour représenter une vache malade.
 - `-ha` & `-- happy`   -> change les yeux pour représenter une vache heureuse.

Tout le code est commenté. Pour plus d'informations sur le fonctionnement de chaque fonction se référer aux commentaires.


#### Exécution

- `./newcow -T 'U ' Bonjour ! -e ^^`
```text
 ___________
< Bonjour ! >
 -----------
        \   ^__^
         \  (^^)\_______
            (__)\       )\/\
             U  ||----w |
                ||     ||
```
- `./newcow -d Je suis morte !`
```text
 _________________
< Je suis morte ! >
 -----------------
        \   ^__^
         \  (XX)\_______
            (__)\       )\/\
             U  ||----w |
                ||     ||

```

- `./newcow Ouai '!!!' --happy`
```text
 __________
< Ouai !!! >
----------
        \   ^__^
         \  (OO)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```

- `./newcow -s Urrggg...`
```text
 ___________
< Urrggg... >
 -----------
        \   ^__^
         \  (**)\_______
            (__)\       )\/\
             u  ||----w |
                ||     ||

```

- `./newcow Les options peuvent etre mises nimporte ou ! -W 30 ! dans le message elles ! -d ! seront bien detecte.` (*changement de la taille de la ligne*)
```text
 ________________________________
/ Les options peuvent etre mises \
|  nimporte ou ! ! dans le messa |
| ge elles ! ! seront bien detec |
\ te.                            /
 --------------------------------
        \   ^__^
         \  (XX)\_______
            (__)\       )\/\
             U  ||----w |
                ||     ||
```

- `./newcow Les options peuvent etre mises importe ou ! -W 150 ! dans le message elles ! -ha ! seront bien detecte.` (*changement de la taille de la ligne*)
```text
 ______________________________________________________________________________________________
< Les options peuvent etre mises importe ou ! ! dans le message elles ! ! seront bien detecte. >
 ----------------------------------------------------------------------------------------------
        \   ^__^
         \  (OO)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```
___
## reading_cow.c

Il est **préférable** d'avoir lu `new_cow.c` avant ce fichier, car il réutilise la plupart des fonctions de celui-ci.

```c
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
 * Si l'extraction du fichier de lecture n'as pas fonctionné. Alors le programme
 * s'arrête avec un message d'erreur.
 *
 * Si l'extraction du fichier de lecture as fonction avec succès nous rentrons
 * dans la boucle de la lecture.
 *
 * La contenu de la boucle ne se charge que de l'affichage. Mais la condition dans
 * la boucle appellant animateRead(conf). Va modifier la configuration pour changer l'affichage.
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
 * Récupère le fichier de lecture de la config, lit un nouveau caractère et déplace
 * tout les caractères de leur place à la suivante.
 * Suivant ce protocole :
 *
 *  Ficher -> Langue[0] -> displayText(happened)
 *
 * Le caractère '\n' est transformé en ' '.
 *
 * @param conf
 * @return false si le fichier est vide, ou que le caractère lu est le caractère terminal.
 * true sinon. Le caractère terminal est '&'.
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
 * Si après avoir extrait toutes les options le fichier de lecture n'as pas été défini
 * (à l'aide de -default).
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
```

#### Commentaire

Ce code réutilise en majorité le code de `newcow.c`.

La logique principale `main()` est un peu plus complexe. Les **commentaire** des fonctions `main()`, `animateRead()`, `extract_params()`, `stdinOption()` expliquent le fonctionnement du programme.

La vache accepte l'option :
- `-default` -> définit le fichier de lecture sur **stdin**.

Le caractère `&` permet de sortir de la lecture du fichier (*condition de sortie pour **sdtin***).

Le texte (*hors options*) est utilisé pour ouvrir un fichier de lecture.

#### Exécution

- `./a.out lefichiernexistepas.txt`
```text
Le fichier de lecture n'as pas pu être ouvert !
```
- `./a.out read.txt`
```text
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             L  ||----w |
                ||     ||
 ___
< L >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             o  ||----w |
                ||     ||
 ____
< Lo >
 ----
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             r  ||----w |
                ||     ||
 _____
< Lor >
 -----
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             e  ||----w |
                ||     ||
 ______
< Lore >
 ------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             m  ||----w |
                ||     ||
 _______
< Lorem >
 -------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
 ________
< Lorem  >
 --------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             i  ||----w |
                ||     ||
 _________
< Lorem i >
 ---------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             p  ||----w |
                ||     ||
 __________
< Lorem ip >
 ----------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             s  ||----w |
                ||     ||


...


 __________________________________________
/ Lorem ipsum dolor sit amet, consectetur  \
| adipiscing elit. Sed rhoncus, massa conv |
| allis ultrices euismod, urna dolor rhonc |
| us velit, sed tincidunt magna ipsum eu a |
| nte. Interdum et malesuada fames ac ante |
|  ipsum primis in faucibus. Sed interdum, |
|  tellus a fringilla rhoncus, elit diam e |
| uismod urna, auctor porta urna lorem ac  |
| odio. Proin vehicula tortor et nibh ferm |
| entum mollis eget sit amet nulla. Vestib |
| ulum placerat quam purus, blandit egesta |
| s quam rhoncus at. Sed nec dapibus dui,  |
| ut fermentum nibh. Aliquam sit amet temp |
| or quam. Sed sed cursus metus. Vestibulu |
| m eu efficitur nisl. Aenean varius sit a |
| met magna pharetra pellentesque. Sed mat |
| tis sagittis consequat. Maecenas venenat |
| is faucibus nunc et vulputate. Quisque i |
| n mattis dui. Mauris porttitor euismod r |
| utrum. Vivamus pharetra a dui sit amet c |
| onvallis. Donec egestas sit amet lectus  |
\ fringilla ultrices                       /
 ------------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             .  ||----w |
                ||     ||
 __________________________________________
/ Lorem ipsum dolor sit amet, consectetur  \
| adipiscing elit. Sed rhoncus, massa conv |
| allis ultrices euismod, urna dolor rhonc |
| us velit, sed tincidunt magna ipsum eu a |
| nte. Interdum et malesuada fames ac ante |
|  ipsum primis in faucibus. Sed interdum, |
|  tellus a fringilla rhoncus, elit diam e |
| uismod urna, auctor porta urna lorem ac  |
| odio. Proin vehicula tortor et nibh ferm |
| entum mollis eget sit amet nulla. Vestib |
| ulum placerat quam purus, blandit egesta |
| s quam rhoncus at. Sed nec dapibus dui,  |
| ut fermentum nibh. Aliquam sit amet temp |
| or quam. Sed sed cursus metus. Vestibulu |
| m eu efficitur nisl. Aenean varius sit a |
| met magna pharetra pellentesque. Sed mat |
| tis sagittis consequat. Maecenas venenat |
| is faucibus nunc et vulputate. Quisque i |
| n mattis dui. Mauris porttitor euismod r |
| utrum. Vivamus pharetra a dui sit amet c |
| onvallis. Donec egestas sit amet lectus  |
\ fringilla ultrices.                      /
 ------------------------------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```
- `./a.out read.txt -W 100 -e $$` (*il est toujours possible d'utiliser des options*)
```text
...

 ______________________________________________________________________________________________________
/ Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed rhoncus, massa convallis ultrices euism \
| od, urna dolor rhoncus velit, sed tincidunt magna ipsum eu ante. Interdum et malesuada fames ac ante |
|  ipsum primis in faucibus. Sed interdum, tellus a fringilla rhoncus, elit diam euismod urna, auctor  |
| porta urna lorem ac odio. Proin vehicula tortor et nibh fermentum mollis eget sit amet nulla. Vestib |
| ulum placerat quam purus, blandit egestas quam rhoncus at. Sed nec dapibus dui, ut fermentum nibh. A |
| liquam sit amet tempor quam. Sed sed cursus metus. Vestibulum eu efficitur nisl. Aenean varius sit a |
| met magna pharetra pellentesque. Sed mattis sagittis consequat. Maecenas venenatis faucibus nunc et  |
| vulputate. Quisque in mattis dui. Mauris porttitor euismod rutrum. Vivamus pharetra a dui sit amet c |
\ onvallis. Donec egestas sit amet lectus fringilla ultrices.                                          /
 ------------------------------------------------------------------------------------------------------
        \   ^__^
         \  ($$)\_______
            (__)\       )\/\
                ||----w |
                ||     ||

```
- `./a.out -default` (*utilisation de l'option **-default***)
```text
> Bonjour !

        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             B  ||----w |
                ||     ||
 ___
< B >
 ---
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             o  ||----w |
                ||     ||
 ____
< Bo >
 ----
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             n  ||----w |
                ||     ||
 _____
< Bon >
 -----
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             j  ||----w |
                ||     ||

...

 __________
< Bonjour  >
 ----------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             !  ||----w |
                ||     ||
 ___________
< Bonjour ! >
 -----------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
> Ca va ?
 ____________
< Bonjour !  >
 ------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             C  ||----w |
                ||     ||
 _____________
< Bonjour ! C >
 -------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
             a  ||----w |
                ||     ||
 ______________
< Bonjour ! Ca >
 --------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||

...

 ___________________
< Bonjour ! Ca va ? >
 -------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
> &
 ____________________
< Bonjour ! Ca va ?  >
 --------------------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
```
___
## wildcow.c

Il est **préférable** d'avoir lu `new_cow.c` avant ce fichier, car il réutilise la plupart des fonctions de celui-ci.


```c
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
```

#### Commentaire

Affichage d'une vache folle qui charge cornes en avant en faisant de la fumée.

#### Exécution

- `./a.out` (*difficile de montrer le résultat d'une animation. Le mieux est de tester le code.*)
```text
 ___________
< Chargez ! >
 -----------
        \  \__\
         \  (@@)\_______
            (__)\       )\/\
             U  ||----w |
                //     //    @ @@
```

# Automate (*tamagoshi*)

Le programme tamagoshi a besoin du programme compilé de `newcow.c` sous le nom de `newcow` en dépendance.

#### Structure :

- `automate`
  - `newcow` (*fichier compilé de newcow.c*)
  - `tamagoshi` (*fichier compilé de tamagoshi.c*)
  - `tamagoshi.c` (*fichier source, optionel*)

## tamagoshi.c


```c
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
```

#### Commentaire


Code principal contenu dans la fonction `main()`.

L'affichage de la vache fonctionne en utilisant le programme `newcow.c` avec les options :

- `--happy` : en bonne santé
- `--sick` : malade
- `--dead` : morte

#### Exécution

- `./tamagoshi`
```text
 ___________
< Meuuuu !! >
 -----------
        \   ^__^
         \  (OO)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
Vous avez 5 rations en stock. Combien voulez-vous en utiliser : 2 
 ________
< Meu... >
 --------
        \   ^__^
         \  (**)\_______
            (__)\       )\/\
             u  ||----w |
                ||     ||
Vous avez 4 rations en stock. Combien voulez-vous en utiliser : 10
La valeur de rations à utiliser n'est pas valide réassayez : 10
La valeur de rations à utiliser n'est pas valide réassayez : 3
 _____
< ... >
 -----
        \   ^__^
         \  (XX)\_______
            (__)\       )\/\
             U  ||----w |
                ||     ||
Vous avez survécu 2 jours.
```
- `./tamagoshi` (*Notre meilleur score ^^*)
```text
 ___________
< Meuuuu !! >
 -----------
        \   ^__^
         \  (OO)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
Vous avez 5 rations en stock. Combien voulez-vous en utiliser : 0
 ___________
< Meuuuu !! >
 -----------
        \   ^__^
         \  (OO)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
Vous avez 7 rations en stock. Combien voulez-vous en utiliser : 2

...

Vous avez 4 rations en stock. Combien voulez-vous en utiliser : 0
 ___________
< Meuuuu !! >
 -----------
        \   ^__^
         \  (OO)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
Vous avez 6 rations en stock. Combien voulez-vous en utiliser : 3
 ________
< Meu... >
 --------
        \   ^__^
         \  (**)\_______
            (__)\       )\/\
             u  ||----w |
                ||     ||
Vous avez 3 rations en stock. Combien voulez-vous en utiliser : 3
 _____
< ... >
 -----
        \   ^__^
         \  (XX)\_______
            (__)\       )\/\
             U  ||----w |
                ||     ||
Vous avez survécu 63 jours.
```
# FIN

Merci de nous avoir lu !

Toutes les sources sont disponibles (*ici dans le compte rendu, mais aussi dans le repo git*).

Arnaud ALET et Abdelkader Al Akoum - IMA-04 - INF203 - 2023 - UGA
