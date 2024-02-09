/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:20:50 by vamologl          #+#    #+#             */
/*   Updated: 2023/05/25 16:21:28 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
// to remove
int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}
/* =========================================== */
static char	*ft_zero(void) 
// pour le cas ou le nombre entier = 0
// creer une chaine de char qui contient uniquement"0" 
{
	char	*ret;
	
	ret = malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}
static char	*ft_return(char buff[]) 
// utilisée pour renvoyer une copie du tableau buff avec les chiffres stockés dans l'ordre correct (de gauche à droite) afin de former la chaîne de caractères représentant la valeur de n.
// Stocker dans une memoire tampon pour eviter un encombrement
{
	char	*ret;	// stock la chaine de car renvoyee
	int		i; // l indice de la position actuelle
	int		len; // pour calculer la longueur de la chaine de car
	
	i = 0;
	len = ft_strlen(buff);
	ret = malloc(sizeof(char) * len + 1); // alloue de la memoire
	if (!ret)
		return (NULL);
	while (--len >= 0) // pour inverser les chiffres stockés dans le tableau buff, en commençant par le dernier chiffre et en continuant jusqu'au premier. Pour ce faire, la variable len est décrémentée
		ret[i++] = buff[len];
	ret[i] = '\0';
	return (ret);
}
char	*ft_itoa_autre(int n)
// initialise des variables "buff" pour stocker la chaine de car representant le nombre
// nb : pour stocker la valeur de n
// i ; parcourir le buff
// negatif : pour indiquer si n est negatif
{
	char	buff[12]; // 12 --> max character == 11
	long	nb;
	int		i;
	int		negatif;
	
	i = 0;
	nb = (long)n; // pour ne pas avoir de probleme avec int min & nbres neg
	negatif = 0;
	if (!nb)
		return (ft_zero());
	if (nb < 0)
	{
		negatif = 1;
		nb = -nb;
	}
	while (nb)
	{
		buff[i++] = (nb % 10) + 48;
		nb /= 10;
	}
	if (negatif)
		buff[i++] = '-';
	buff[i] = '\0';
	return (ft_return(buff));
}
// 1-si n=o --> on appel la fonction ft_zero pour retourner la chaine de car "0"
// 2-si n est '-' donc < 0
//	--> modifie le int negatif et le long nb : pour prendre en compte le signe negatif
// 3-si nb est un autrenombre que 0
//	--> boucle while permet de remplir le tableau buff avec les chiffres de nb en partant des unites et en allant vers les dizaines, centaines etc...
// Si n etait negatif, ajoute le signe - au buffer.
// La fonction renvoie alors la chaîne de caractères représentant le nombre entier.
//	--> appel la fonction ft_return() avec buff comme argument. 
//	--> recopie les caractères de buff en les inversant pour obtenir l'ordre correct des chiffres
//	--> retourne la chaîne de caractères résultante.
int	main(void)
{
	char	*test = ft_itoa_autre(42564);
	
	printf("%s\n", test);
	free(test);
	return (0);
}
/*
En cas de pointeur (char *, int *, ...)
si ret est egale a une adresse --> (ret)
si ret == NULL --> (!ret)
En cas de int, char, long, ...
si n est un nombre autre que zero--> (n)
si n == 0 --> (!n)
*/
/*
si i = 4
i++ --> pour la ligne = 4 // apres = 5
++i --> pour la ligne = 5 // apres = 5
*/
