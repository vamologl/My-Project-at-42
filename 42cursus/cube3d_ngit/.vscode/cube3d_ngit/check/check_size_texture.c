/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:53:08 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/16 11:12:27 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

int	check_height_texture(t_cube *cube)
{
	if (cube->texture->height != 64 || cube->texture1->height != 64
		|| cube->texture3->height != 64 || cube->texture2->height != 64)
	{
		printf("Error - Texture height incorrect, should be 64px\n");
		return (ERROR);
	}
	if (cube->check_door == 1)
	{
		if (cube->texture4->height != 64)
		{
			printf("Error - Texture height incorrect, should be 64px\n");
			return (ERROR);
		}
	}
	return (VALID);
}

void	check_texture_while(bool *tx, bool *tx1, t_cube *cube, int div)
{
	if (cube->texture->width % div == 0)
		(*tx) = true;
	if (cube->texture1->width % div == 0)
		(*tx1) = true;
}

int	check_length_texture(t_cube *cube)
{
	int		div;
	bool	tx;
	bool	tx1;
	bool	tx2;
	bool	tx3;

	tx = false;
	tx1 = false;
	tx2 = false;
	tx3 = false;
	div = 64;
	while (div <= 512)
	{
		check_texture_while(&tx, &tx1, cube, div);
		if (cube->texture2->width % div == 0)
			tx2 = true;
		if (cube->texture3->width % div == 0)
			tx3 = true;
		div += 64;
	}
	if (tx == false || tx1 == false || tx2 == false || tx3 == false)
		return (ERROR);
	return (VALID);
}

int	check_length_texture_door(t_cube *cube)
{
	int		div;
	bool	tx;

	tx = false;
	div = 64;
	while (div <= 512)
	{
		if (cube->texture4 && cube->texture4->width % div == 0)
			tx = true;
		div += 64;
	}
	if (tx == false)
		return (ERROR);
	return (VALID);
}

int	check_texture_size(t_cube *cube)
{
	if (check_height_texture(cube) != VALID)
		return (ERROR);
	if (check_length_texture(cube) != VALID)
	{
		printf("Error - Textures lenght should be 64px max ");
		printf("and should have 8 frames max\n");
		return (ERROR);
	}
	if (cube->check_door == 1)
	{
		if (check_length_texture_door(cube) != VALID)
		{
			printf("Error - The door texture lenght should be 64px");
			printf(" max and should have 8 frames max\n");
			return (ERROR);
		}
	}
	return (VALID);
}
