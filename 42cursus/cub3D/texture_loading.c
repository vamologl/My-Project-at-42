/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_loading.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 15:39:21 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/12 13:29:45 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

t_texture	*load_xpm_texture(const char *filepath, t_cube *cube)
{
	cube->texture = gc_alloc(sizeof(t_texture) * 4, 2);
	if (!cube->texture)
	{
		printf("Failed to allocate memory for texture.\n");
		return (NULL);
	}
	cube->texture->img = mlx_xpm_file_to_image(cube->mlx,
			(char *)filepath, &cube->texture->width, &cube->texture->height);
	if (!cube->texture->img)
	{
		printf("Failed to load XPM texture: %s\n", filepath);
		free(cube->texture);
		return (NULL);
	}
	cube->texture->data = (int *)mlx_get_data_addr(cube->texture->img,
			&(int){0}, &(int){0}, &(int){0});
	return (cube->texture);
}

t_texture	*load_xpm_texture2(const char *filepath, t_cube *cube)
{
	cube->texture2 = gc_alloc(sizeof(t_texture) * 4, 2);
	if (!cube->texture2)
	{
		printf("Failed to allocate memory for texture.\n");
		return (NULL);
	}
	cube->texture2->img = mlx_xpm_file_to_image(cube->mlx,
			(char *)filepath, &cube->texture2->width, &cube->texture2->height);
	if (!cube->texture2->img)
	{
		printf("Failed to load XPM texture: %s\n", filepath);
		free(cube->texture2);
		return (NULL);
	}
	cube->texture2->data = (int *)mlx_get_data_addr(cube->texture2->img,
			&(int){0}, &(int){0}, &(int){0});
	return (cube->texture2);
}

t_texture	*load_xpm_texture1(const char *filepath, t_cube *cube)
{
	cube->texture1 = gc_alloc(sizeof(t_texture) * 4, 2);
	if (!cube->texture1)
	{
		printf("Failed to allocate memory for texture.\n");
		return (NULL);
	}
	cube->texture1->img = mlx_xpm_file_to_image(cube->mlx,
			(char *)filepath, &cube->texture1->width, &cube->texture1->height);
	if (!cube->texture1->img)
	{
		printf("Failed to load XPM texture: %s\n", filepath);
		free(cube->texture1);
		return (NULL);
	}
	cube->texture1->data = (int *)mlx_get_data_addr(cube->texture1->img,
			&(int){0}, &(int){0}, &(int){0});
	return (cube->texture1);
}

t_texture	*load_xpm_texture3(const char *filepath, t_cube *cube)
{
	cube->texture3 = gc_alloc(sizeof(t_texture) * 4, 2);
	if (!cube->texture3)
	{
		printf("Failed to allocate memory for texture.\n");
		return (NULL);
	}
	cube->texture3->img = mlx_xpm_file_to_image(cube->mlx,
			(char *)filepath, &cube->texture3->width, &cube->texture3->height);
	if (!cube->texture3->img)
	{
		printf("Failed to load XPM texture: %s\n", filepath);
		free(cube->texture3);
		return (NULL);
	}
	cube->texture3->data = (int *)mlx_get_data_addr(cube->texture3->img,
			&(int){0}, &(int){0}, &(int){0});
	return (cube->texture3);
}

t_texture	*load_xpm_texture4(const char *filepath, t_cube *cube)
{
	cube->texture4 = gc_alloc(sizeof(t_texture) * 4, 2);
	if (!cube->texture4)
	{
		printf("Failed to allocate memory for texture.\n");
		return (NULL);
	}
	cube->texture4->img = mlx_xpm_file_to_image(cube->mlx,
			(char *)filepath, &cube->texture4->width, &cube->texture4->height);
	if (!cube->texture4->img)
	{
		printf("Failed to load XPM texture: %s\n", filepath);
		free(cube->texture4);
		return (NULL);
	}
	cube->texture4->data = (int *)mlx_get_data_addr(cube->texture4->img,
			&(int){0}, &(int){0}, &(int){0});
	return (cube->texture4);
}
