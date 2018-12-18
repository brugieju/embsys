ARSLANYAN Antony
BRUGIER Juliette

# Partie 1

## Question 1
Un makefile est un fichier qui contient les paramètres de compilaion avec gcc.
La commande make permet de compiler le fichier Makefile.

## Question 2
Le compilateur utilisé est gcc.

## Question 3
Une librairie partagée est une librairie utilisable par tous les programmes. Initialement elle n'est pas chargée sur la RAM. Elle est chargée lorsqu'un programme cherhce à y accéder.

## Question 4
Cette ligne de commande créé un fichier binaire hello exécutable.

gcc hello.c -o hello

## Question 5
On a créé un fichier librairie.c puis:

gcc -c -fPIC librairie.c
gcc -shared -Wall librairie.o -o libtest.so

# Partie 2

## Exercice 1

### Question 1
Au bout de quelques secondes, on observe une erreur de segmentation:
Segmentation fault (core dumped)
On en déduit donc qu'il y a une erreur d'accès mémoire.

### Question 2
Pour connaître le numéro de l'erreur on utilise:
echo $?
Puis on soustrait 128 à ce nombre ce qui donne: 139-128 = 11
Puis on utilise la commande kill -l pour obtenir la liste des erreurs.

### Question 3
Comme il ne faut pas tenir compte de la dernière erreur qui est sur un .S, on lit que l'erreur est sur la fonction knot_to_kmh_str() du fichier nmea.c.

### Question 4
Quand on lance GDB en mode interactif sur le binaire gps, on obtient une erreur:
error while loading shared libraries: libptmx.so
Le simulateur ne peut pas être lancé car la librairie n'est pas trouvé.

### Question 5
La commande ldd sert à afficher les librairies partagées dont à besoin le porgramme.
Cela nous apprend que deux librairies ne sont pas trouvées: libptmx.so et libnmea.so.

### Question 6
Il faut changer le PATH librairy:
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$PWD/lib

### Question 7
La commande *s* permet de débuger en rentrant en détail dans les fonctions appelées (ligne à ligne).
La commande *n* débuge ligne à ligne sans rentrer en détail dans les fonctions appelées dans les lignes.

### Question 8
Gdb peut être intéressant pour faire du débugage.

## Exercice 2

### Question 4
On utlise la commande man man.
Puis on détermine la section voulue, ici Library calls donc section.
pour cela on lance la commande:
man 3 printf
On trouve:
int printf(const char *format, ...);
Cela signifie que la fonction printf accepte un nombre variable de paramètre, c'est ce que l'on appelle une fonction variadique.

### Question 7
On peut utliser CTRL-Z. Sinon on kill le processus depuis un autre terminal: on détermine le numéro du processus avec la commande ps puis le nom du processus "gps".

### Question 8
En compilant avec la règle ok, toute la compilation se fait de la même manière sauf celle de libnmea. Celle-ci se compile avec la règle ok. En regardant le makefile présent dans src/lib/nmea, la règle ok permet de compiler sans débug.

# Partie 3

## Exercice 1

### Question 1
C'est un dossier virtuel dans lequel sont créées les consoles des utilisateurs se connectant à la machine. Tout protocole ayant besoin d'une console se verra alouer un numéro dans /dev/pts.

On lance le gps_reader en indiquant le bon port:

./gps_reader -p /dev/pts/11

### Question 2
Le code reader.c est très peu commenté donc compliqué à relire.

### Question 3
On trouve l'heure dans la trame GPGLL en position 5.
Par exemple:
GPGLL,4841.04,N,00745.44,E,103026,A
ici l'heure vaut 00745.44 UTC.

### Question 4
Pour ouvrir le port virtuel du simulateur, on utilise la fonction:
open()
Pour fermer le port virtuel du simulateur, on utilise la fonction:
close()
Pour lire le port virtuel du simulateur, on utilise la fonction:
read()
Pour écouter le port virtuel du simulateur, on utilise la fonction:
FD_SET

Ce type de programmation s'appelle UDP car il n'y a pas de vérification de bonne réception des sockets.

### Question 5
Voir fichier reader.c

### Question 6
On va dans le dossier /var/log pour avoir accès au fichier syslog.
Nous n'avons pas réussi à l'afficher dans la console.

### Question 7
Nous avons voulu changer les paramètre de configuration dans le fichier rsyslog mais le fichier est en lecture seule.
Nous n'avons pas trouvé demoyen de contourner le problème.










 






