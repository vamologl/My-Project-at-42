# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    note.txt                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spagliar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/24 07:35:59 by spagliar          #+#    #+#              #
#    Updated: 2023/07/24 07:36:00 by spagliar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

processus server

pid : processus identifier 
-> utilisee pour designer l'identifiant de processus, 
nombres entiers positifs. Ils commencent généralement à partir de 1 et augmentent de manière séquentielle pour chaque nouveau processus créé. 
commande pour avoir id : ps -ef | grep 
pid_t getpid(void);
pid_t getppid(void);
Ces fonctions sont toujours réussies

signal : 
#include <signal.h>
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);

utilisée pour changer le comportement d'un programme lorsqu'il reçoit un signal spécifique. 
-> Lorsqu'un signal est reçu, le système d'exploitation interrompt le programme en cours d'exécution et exécute une fonction spécifique, appelée gestionnaire de signaux ou signal handler. 
->La fonction signal permet de spécifier quel gestionnaire de signaux doit être exécuté lorsqu'un signal spécifique est reçu en.c


kill : envoi des signaux sorte de messages qui peuvent être utilisés pour demander à un processus de terminer, de se suspendre ou de reprendre son exécution, entre autres choses.
Pour utiliser la fonction kill en C, vous devez d'abord connaître le PID (identifiant de processus) du processus que vous souhaitez cibler. Le PID est un nombre entier unique attribué à chaque processus en cours d'exécution sur le système. Vous pouvez trouver le PID d'un processus en utilisant la commande ps -ef | grep nom_processus.

sleep : sleep(1) met sur pause le programme 1sec sleep(2) idem pour 2sec

macro pré-définie : fait référence à une macro qui est définie par le compilateur lui-même et qui est disponible pour être utilisée dans votre programme sans nécessiter une déclaration ou une définition supplémentaire.

sigaction (alternative a signal)
int sigaction(int signum, const struct sigaction *act,
struct sigaction *oldact);
Elle prend trois arguments : 
1 -> le signal à gérer
2 -> une structure sigaction qui définit le comportement à adopter lors de la réception du signal
3 -> une structure sigaction qui sera remplie avec le comportement précédent associé au signal (si elle n'est pas NULL) 

signum -> indique le signal concerné, à l'exception de SIGKILL et SIGSTOP. 

 sert à modifier l'action effectuée par un processus à la réception d'un signal spécifique. 
fonction utilisee pour gerer les signaux dans les systemes d"exploitation de type unix
-> peut spécifier des gestionnaires de signaux qui reçoivent des arguments supplémentaires
->bloquer certains signaux pendant l'exécution du gestionnaire de signaux 



getpid() pour obtenir l'ID du processus en cours d'exécution
fonction qui ne prend aucun argument et renvoie l"ID du processus appelant

sa.sa_handler : définit le gestionnaire de signaux pour la structure sigaction 
sigemptyset() est une fonction standard en C définie dans la bibliothèque <signal.h>
sa.sa_flags  ensemble d'options pour le comportement du gestionnaire de signaux. En le définissant à 0, aucune option n'est activée.
https://www.lri.fr/~mandel/systeme/systeme-06.pdf

OPERATION OR :
L'opération OR (|) est un opérateur binaire utilisé en programmation pour effectuer une opération logique sur des bits individuels.

L'opération OR est appliquée à deux bits, et le résultat est déterminé selon la table de vérité suivante :

    Si l'un des bits est égal à 1, le résultat est 1.
    Si les deux bits sont égaux à 0, le résultat est 0.

Par exemple, voici quelques exemples d'opérations OR :

    0 | 0 = 0
    0 | 1 = 1
    1 | 0 = 1
    1 | 1 = 1

L'opération OR peut également être utilisée sur des nombres entiers. 
Dans ce cas, chaque bit des deux nombres est comparé et l'opération OR est appliquée à chaque paire de bits correspondants. 
Le résultat est un nombre entier dont chaque bit est le résultat de l'opération OR correspondante.

Par exemple, si nous avons les nombres binaires suivants :

    1010
    1100

L'opération OR entre ces deux nombres donnerait le résultat suivant :

    1110

Cela signifie que chaque bit du résultat est le résultat de l'opération OR entre les bits correspondants des deux nombres d'origine.

En résumé, l'opération OR est utilisée pour combiner des bits individuels ou des nombres entiers en utilisant la logique OR.

ecrire : 
L'utilisation de "../" dans le chemin signifie "remonter d'un niveau dans l'arborescence des répertoires". Donc, "./../minitalk.h" indique au compilateur de remonter d'un niveau dans l'arborescence des répertoires à partir du répertoire contenant le fichier source, puis de chercher le fichier "minitalk.h" dans ce répertoire parent.

Cela peut être utile lorsque le fichier d'en-tête est situé dans un répertoire différent de celui du fichier source, mais se trouve dans le répertoire parent ou dans un autre répertoire relatif.

L'opérateur logique ET (&) est utilisé pour effectuer une opération logique entre deux valeurs binaires.
En utilisant l'opérateur logique ET avec 1, on peut extraire le bit le plus à droite d'une valeur binaire. Si le résultat est 1, cela signifie que le bit est vrai, sinon il est faux.


La ligne usleep(100) met en pause l'exécution du programme pendant 100 microsecondes. Cette pause est ajoutée dans le code pour introduire un délai entre l'envoi de chaque bit.

Il peut être nécessaire d'ajouter un délai entre l'envoi de chaque bit pour différentes raisons, notamment :

    Synchronisation : Si le processus qui reçoit les signaux a besoin d'un certain temps pour traiter chaque bit, il est important de lui laisser suffisamment de temps pour effectuer les opérations nécessaires avant de recevoir le bit suivant. La pause permet de synchroniser l'envoi des bits avec la capacité de traitement du processus récepteur.

    Stabilité du signal : Dans certains cas, il peut être nécessaire de garantir que le signal envoyé est stable pendant une certaine durée. En ajoutant une pause, on s'assure que le signal reste actif pendant la durée spécifiée, ce qui peut être important pour la détection précise du signal par le processus récepteur.

    Limitation de la vitesse de transmission : Dans certains protocoles de communication, il peut être nécessaire de limiter la vitesse de transmission des données pour des raisons de compatibilité ou de contraintes matérielles. En ajoutant une pause, on ralentit la transmission des bits, ce qui peut être nécessaire pour respecter ces limitations.

Il est important de noter que la durée de la pause (100 dans ce cas) peut varier en fonction des besoins spécifiques du système ou du protocole de communication utilisé. Dans ce code, une pause de 100 microsecondes est utilisée à titre d'exemple, mais elle peut être ajustée en fonction des exigences du système.

En résumé, la fonction kill est utilisée pour envoyer des signaux à d'autres processus en utilisant leur identifiant de processus (PID). Les signaux peuvent être utilisés pour communiquer avec d'autres processus ou pour déclencher des actions spécifiques. Dans le code que vous avez fourni, kill est utilisé pour envoyer des signaux personnalisés (SIGUSR1 ou SIGUSR2) en fonction de la valeur du bit.

En résumé, l'utilisation de ./../ dans l'instruction #include "./../minitalk.h" permet de spécifier un chemin relatif vers le fichier d'en-tête minitalk.h, en remontant d'un niveau dans la structure des répertoires. Cela offre de la flexibilité et permet de maintenir la validité du chemin relatif même si le fichier source est déplacé.


La structure sigaction est utilisée en C pour modifier l'action effectuée par un processus à la réception d'un signal spécifique. Voici quelques points clés sur la structure de sigaction et pourquoi elle est utilisée :

    La structure sigaction est définie comme suit :

  struct sigaction {
      void (*sa_handler)(int);
      void (*sa_sigaction)(int, siginfo_t *, void *);
      sigset_t sa_mask;
      int sa_flags;
      void (*sa_restorer)(void);
  };





