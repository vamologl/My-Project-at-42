/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main du server.txt                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 07:58:22 by spagliar          #+#    #+#             */
/*   Updated: 2023/08/10 07:58:25 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = receive_bit;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr(ft_itoa(getpid()));
	while (1)
		sleep(1);
	return (0);
}

Explication du main :

On choisit de renvoyer un int pour verifier le retour de l'execution du programme.

Dans la struct sigaction -> sa = var qui sert a gerer les signaux 

sa.sa_handler : (var de type struct sigaction)
--------------
est utilisée pour spécifier la fonction qui sera exécutée lorsque le signal est reçu.
En affectant la fonction receive_bit à sa.sa_handler, on indique que cette fonction sera appelée 
lorsque les signaux SIGUSR1 ou SIGUSR2 seront reçus. 
Ainsi, la ligne sa.sa_handler = receive_bit permet de gérer les signaux en exécutant la fonction receive_bit.
-> Pourquoi ces elements dans la structure sigaction : sa.sa_handler
on accède au champ sa_handler de la variable sa, qui contient le gestionnaire de signal spécifique pour 
le signal donné.

sigemptyset(&sa.sa_mask);: 
------------------------
Cela initialise l'ensemble de signaux (sa_mask) de la structure sa à vide
Le masque de signaux est un mécanisme utilisé pour contrôler le comportement des signaux dans un programme. 
Il permet de spécifier quels signaux doivent être bloqués ou ignorés pendant l'exécution d'une certaine partie du code
-> pourquoi on utilise l'adresse de sa dans cette fonction : 
permet de passer l'adresse de la variable sa.sa_mask à la fonction sigemptyset afin qu'elle puisse vider 
le masque de signaux en modifiant directement son contenu.

sa.sa_flags = 0 :
----------------
est utilisée pour initialiser les indicateurs de la structure sa à zéro
les champ sa_flags permet de spécifier des indicateurs ou des options pour la gestion des signaux.
En affectant la valeur zéro à sa.sa_flags, on indique que tous les indicateurs sont désactivés ou non spécifiés.
ex d'indicateur couramment utilisé dans la struct sigaction est SA_RESTART. cf doc

sigaction(SIGUSR1, &sa, NULL) & sigaction(SIGUSR2, &sa, NULL) :
-------------------------------------------------------------
sont utilisées pour associer le gestionnaire de signal spécifié par la structure sa aux signaux SIGUSR1 et SIGUSR2, 
ce qui permet d'exécuter le gestionnaire de signal lorsque ces signaux sont reçus.
Lorsque NULL est passé comme argument pour le paramètre sa_handler de la structure sigaction, cela signifie que le signal spécifié (SIGUSR1 et SIGUSR2 dans ce cas) sera ignoré.
Cela signifie que lorsque ces signaux sont reçus, aucune action spécifique ne sera effectuée.

ft_putstr(ft_itoa(getpid())) :
------------------------------
Cette ligne est utilisée pour afficher le PID (Process ID) du processus en cours.
La fonction ft_itoa est utilisée pour convertir le PID en une chaîne de caractères,
Elle est passée comme argument à la fonction ft_putstr. 
La fonction ft_putstr est utilisée pour afficher la chaîne de caractères à l'écran.

sleep(1) :
---------
met le processus en pause pendant 1 seconde à chaque itération de la boucle. 
Cela permet de ralentir l'exécution du programme et d'économiser des ressources du système.
