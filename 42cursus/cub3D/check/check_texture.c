/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <vamologl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 10:17:08 by vamologl          #+#    #+#             */
/*   Updated: 2024/09/11 11:22:40 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include.h"

bool	check_north(t_cube *cube, char *str)
{
	char	*tmp;

	tmp = ft_sstrndup(str, ft_strlen(str), 3, 3);
	cube->fd_no_tex = open(tmp, O_RDONLY);
	if (cube->fd_no_tex == -1)
		return (false);
	close(cube->fd_no_tex);
	cube->no_tex_name = ft_strdup_gc(tmp, 3);
	return (true);
}

bool	check_south(t_cube *cube, char *str)
{
	char	*tmp;

	tmp = ft_sstrndup(str, ft_strlen(str), 3, 3);
	cube->fd_so_tex = open(tmp, O_RDONLY);
	if (cube->fd_so_tex == -1)
		return (false);
	close(cube->fd_so_tex);
	cube->so_tex_name = ft_strdup_gc(tmp, 3);
	return (true);
}

bool	check_west(t_cube *cube, char *str)
{
	char	*tmp;

	tmp = ft_sstrndup(str, ft_strlen(str), 3, 3);
	cube->fd_we_tex = open(tmp, O_RDONLY);
	if (cube->fd_we_tex == -1)
		return (false);
	close(cube->fd_we_tex);
	cube->we_tex_name = ft_strdup_gc(tmp, 3);
	return (true);
}

bool	check_east(t_cube *cube, char *str)
{
	char	*tmp;

	tmp = ft_sstrndup(str, ft_strlen(str), 3, 3);
	cube->fd_ea_tex = open(tmp, O_RDONLY);
	if (cube->fd_ea_tex == -1)
		return (false);
	close(cube->fd_ea_tex);
	cube->ea_tex_name = ft_strdup_gc(tmp, 3);
	return (true);
}
