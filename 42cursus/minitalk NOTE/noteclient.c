/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spagliar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:08:30 by spagliar          #+#    #+#             */
/*   Updated: 2023/08/07 11:08:32 by spagliar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 0)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

/*Explication fction:
La fonction prend en paranetre :
-> le pid : identifiant du processus
-> un int = un bit
SIGURS1 -> 0
SIGUSR2 -> 1
Objectif :  envoie un signal personnalisé (SIGUSR1 ou SIGUSR2) au processus identifié par pid, 
en fonction de la valeur du bit. 
Met en pause l'exécution du programme pendant 100 microsecondes avant de continuer.
- synchro et stabilite de l"envoi bit et signal
Kill -> pour l"envoi du signal au processus
*/


void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		send_bit(pid, (c >> i) & 1);
		i++;
	}
}

/*Explication fction:
La fonction prend en parametre :
-> le pid : identifiant du processus
-> un caractere c 
Objectif : Envoyer chaque bit tant que i < 8 bits
La boucle while itère sur les 8 bits du caractère en augmentant la valeur de i à chaque itération. 
Chaque bit est envoyé séparément au processus.
lE & logique permet d"extraire le i eme bit + decalage vers la droite pour le placer a la position plus a droite
On utilise un pour conserver uniquement ce bit.

		   i>>&1
char c -> |_|_|_|_|_|_|_|_|
	   	   0 1 2 3 4 5 6 7  -> 8 bits
*/

void	send_message(int pid, char *message)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		send_char(pid, message[i]);
		//printf("%c", message[i]);//
		i++;
	}
	send_char(pid, '\0');
}

/*Explication fction :
La fonction prend en parametre :
-> le pid : identifiant du processus
-> une chaine de car : le message
Objectif : Envoyer un message carcatere par caractere a un processus identifie par son pid.
Le message est passe en parametre sous forme d"une chaine de caractere.
La fonction utilise send_char pour l'envoi de chaque carcatere.*/


int	main(int arg_count, char **arg_value)
{
	char	*message;
	int		pid_server;

	if (arg_count != 3)
	{
		printf("Usage: %s <PID du serveur> <message>\n", arg_value[0]);
		return (1);
	}
	pid_server = ft_atoi(arg_value[1]);
	message = arg_value[2];
	printf("%d\n%s", pid_server, message);
	send_message(pid_server, message);
	return (0);
}

/*Explication main :
argc != 3
argv[0] ./a.out 		-> nom du progr
argv[1] var pid_server	-> atoi pour convertir argv[1] en int et assigne au pid
argv[2] message      	-> assigner simplement au deuxieme argu 

Deux printf pour verifier comment marche le progr :
1- Si le nombre d'arguments n'est pas égal à 3, elle affiche un message d'utilisation et retourne 1.
2- Elle affiche la valeur de pid_server et la chaîne message.*/



