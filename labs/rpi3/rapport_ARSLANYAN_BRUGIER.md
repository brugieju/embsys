ARSLANYAN Antony
BRUGIER Juliette

## PARTIE 1

# Question 1
`configs/embsys_defconfig` et `busybox.config` sont codés en language KConfig. Ces fichiers de configuration sont utilisés au moment de la compilation.
Le fichier `users.table` est une table qui permet de permet de répertorier tous les utilisateurs présents sur le système. Ici il n'y en a qu'un seul qui s'appelle user1.

# Question 2
raspberrypi3_defconfig

# Question 3
Ce répertoire contient les règles de compilations des packages installables sur le système.

# Question 4
`package/openssh` est un dossier contenant les règles de compilation du package openssh.
Les 4 premiers fichiers sont des patchs correspondant aux mises à jour faites sur le code.
Le fichier `Config.in` permet de définir les options de compilation pour le make.
`S50sshd` permet de gérer le service associé sshd. Au lancement, il va lancer tous les scripts et lancer le serveur ssh.
`openssh.hash` permet de vérifier que notre Makefile est conforme.
`openssh.mk` est un makefile.
`sshd.service` permet de gérer le service de ssh au démarrage.

# Question 5
Permet d'avoir les différentes configurations pour les différents type de rasperry permet de générer les images qui seront flashées sur la carte.
Une fois que  l'image est compilé, `post-build.sh` permet de chercher le canal tty où afficher la console.
`post-image.sh` gère les liaisons séries de la rasperry selon les paramètres au moment du lancement du shell et les paramètres de l'architecture d ela carte. Puis cela supprime tous les fichiers temporaire avant de construire l'image.
`readme.md` explique comment compiler la rasperry pi et écrire sur une carte sd.

# Question 6
Cette commande permet de compiler selon les règles définies par embsys_defconfig.

# Question 7
## architecture matérielle ciblecd
ARM (little endian)
## CPU ciblé
ARM cortex-A53
## ABI:
EABIhf
L'ABI est l'interface com entre les briques logicielles.
## Librairie C utilisée
uClibc-ng
## Version cross-compilateur
gcc 6.x
## Version du Kernel:
Kernel version (Custom Git repository)
https://github.com/raspberrypi/linux.git

# Question 8
Le paquet *openssh* est en :y, donc intégrer au kernel. Il sera donc compilé et disponible dans l'OS cible.
On peut retrouver cette information dans package/openssh/Config.in

# Question 9
*busybox* est un binaire fournissant les
commandes grâce à un jeu de liens symboliques.
*make busybox-menuconfig* permet d'ouvrir le menu de configuration de busybox avant de compiler.

# Question 10
Le répertoire *output/host* contient les fichiers de cross-compilation.
*output/host/usr/bin/arm-linux-gcc* est le fichier de cross-compilation avec le processus cible arm, le kernel cible linux et le compilateur gcc.

# Question 11
La commande *file* donne les informations sur le binaire hw et nous permet de vérifier que notre fichier a été compilé de la manière souhaitée.
En exécutant *./hw*, le binaire générer par la compilation du fichier helloworld.c est lancé. On voit donc s'afficher "Hello Wordl!" dans la console.

# Question 12
On obtient:
hw: ELF 32-bit LSB executable, ARM, EABI5 version 1 (SYSV), dynamically linked, interpreter /lib/ld-uClibc.so.0, not stripped

Le fichier binaire est codé sur 32 bits au lieu de 64. De plus, il utilise l'ABI, l'interpréteur et la librairie C définient dans buildroot précedemment.

En lançant *./hw*, on obtient une erreur de format. C'est normal car le binaire n'est compilé selon l'architecture utilisée pour le lancer.

# Question 13
*rootfs.tar* est la tarball qui constitue le système complet installé sur la carte qui sera utilisé après le démarrage du bootloader puis de Linux.
*zImage* est l'image du noyau à redémarrer.
*sdcard.img* est l'image de la carte SD de la rasperry.

# Question 14
zImage: Linux kernel ARM boot executable zImage (little-endian)

sdcard.img: DOS/MBR boot sector; partition 1 : ID=0xc, active, start-CHS (0x0,0,2), end-CHS (0x4,20,17), startsector 1, 65536 sectors; partition 2 : ID=0x83, start-CHS (0x4,20,18), end-CHS (0x1d,146,54), startsector 65537, 409600 sectors

# Question 15
*/tmp/rootfs* contient notre cross compiler.


## PARTIE 2

# Question 1
Donne les droits sur le conteneur docker.

# Question 2
*chroot* permet de changer le répertoire racine d'un processus de la machine hôte.
Cela exécute une commande ou un shell interactif avec un répertoire racine spécial

# Question 3
En lançant le fichier binaire *hw* dans l'environnement chroot on lance le programme.
Dans le terminal on voit:
Hello Worlds!

## PARTIE 3

# Question 1
Connaître le nombre de partition: *sudo fdisk /dev/sdb* ou *lsblk*
Renvoie:
Device     Boot Start    End Sectors  Size Id Type
/dev/sdb1  *        1  65536   65536   32M  c W95 FAT32 (LBA)
/dev/sdb2       65537 475136  409600  200M 83 Linux

Il y a donc 2 partitions sur la carte sd.
La première partition contient toutes les configurations et les images nécessaire au lancement du système.
*config.txt* choix du kernel à lancer zImage est l'image du Kernel dans notre cas.
*cdmline.txt* paramètres que prend le kernel en se lançant
.dtb
Dans le dossier *overlays* les *.dtbo* permettent de gérer le matériel réel de la carte (i2c, gpio,...)
La deuxième partition de 200Mo contient le système de fichier de la rasperry (ROOTDIR je crois).

# Question 2
Les ports TX/RX font partie du pin group COMMUNICATION INTERFACE.
PIN NAME: UART Interface(RXD, TXD)  [(GPIO15,GPIO14)]

# Question 3
La configuration permettant la communication avec la rpi3 est:
Port:/dev/ttyUSB0
Baud Rate: 115200
Parity: none
Bits: 8
Stopbits: 1
Flow control: none

# Question 4
Il faut se connecter en *user* avec le login *user1**
Puis on utilise ifconfig pour trouver l'IP de la rpi3:
inet addr:172.20.21.164

# Question 5
Connexion en *user* ok.
Connexion en *root* pas autorisé par le daemon ssh.
La configuration est faite dans le sshd_config.

# Question 6








 
