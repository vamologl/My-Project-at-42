/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 11:22:17 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/12 14:45:59 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

void	anim_door(t_cube *cube)
{
	static int	swap;

	if (swap == cube->texture4->width / 64 - 1)
	{
		swap = 0;
		cube->door_animation_frame = swap;
	}
	else
	{
		swap++;
		cube->door_animation_frame = swap;
	}
}

void	anim_west(t_cube *cube)
{
	static int	swap;

	if (swap == cube->texture->width / 64 - 1)
	{
		swap = 0;
		cube->west_animation_frame = swap;
	}
	else
	{
		swap++;
		cube->west_animation_frame = swap;
	}
}

void	anim_east(t_cube *cube)
{
	static int	swap;

	if (swap == cube->texture2->width / 64 - 1)
	{
		swap = 0;
		cube->east_animation_frame = swap;
	}
	else
	{
		swap++;
		cube->east_animation_frame = swap;
	}
}

void	anim_north(t_cube *cube)
{
	static int	swap;

	if (swap == cube->texture1->width / 64 - 1)
	{
		swap = 0;
		cube->north_animation_frame = swap;
	}
	else
	{
		swap++;
		cube->north_animation_frame = swap;
	}
}

void	anim_south(t_cube *cube)
{
	static int	index;

	if (index == cube->texture3->width / 64 - 1)
	{
		index = 0;
		cube->south_animation_frame = index;
	}
	else
	{
		index++;
		cube->south_animation_frame = index;
	}
}
