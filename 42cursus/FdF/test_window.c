/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vamologl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:29:22 by vamologl          #+#    #+#             */
/*   Updated: 2023/09/18 09:29:24 by vamologl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

int		close_win(t_fdf *data)
{
	mlx_destroy_display(data->mlx_ptr);
	free(data);
	exit (2);
	return (2);
}

void	img_pix_put(t_fdf *data, int x, int y, int color)
{
    char    *pixel;
    int		i;

    i = data->bpp - 8;
    pixel = data->img_buffer + (y * data->line_len + x * (data->bpp / 8));
    while (i >= 0)
    {
        if (data->endian != 0)
            *pixel++ = (color >> i) & 0xFF;
        else
            *pixel++ = (color >> (data->bpp - 8 - i)) & 0xFF;
        i -= 8;
    }
}

void	better_render(t_fdf *data)
{
	int	x = 0;
	int	y = 0;

	data->img_ptr = mlx_new_image(data->mlx_ptr, data->size_win_x, data->size_win_y);
	data->img_buffer = mlx_get_data_addr(data->img_ptr, &data->bpp, &data->line_len, &data->endian);

	while (x < data->size_win_x)
	{
		y = 0;
		while (y < data->size_win_y)
		{
			img_pix_put(data, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}

	if (data->xtest < data->size_win_x && data->ytest < data->size_win_y)
	{
		if (data->xtest >= 0 && data->ytest >= 0)
		{
			img_pix_put(data, data->xtest, data->ytest, 0x000000);
			img_pix_put(data, data->xtest + 1, data->ytest, 0x000000);
			img_pix_put(data, data->xtest, data->ytest + 1, 0x000000);
			img_pix_put(data, data->xtest + 1, data->ytest + 1, 0x000000);
		}
	}

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
}

int		deal_key(int key, t_fdf *data)
{
	if (key == moins)
	{
		if (data->zoom >= 0 && (data->zoom - 2) >= 0)
			data->zoom -= 2;
	}
	if (key == plus)
		data->zoom += 2;
	if (key == down)
		data->ytest -= 10;
	if (key == up)
		data->ytest += 10;
	if (key == left)
		data->xtest -= 10;
	if (key == right)
		data->xtest += 10;
	if (key == etoile)
		data->angle += 0.1;
	if (key == barre)
		data->angle -= 0.1;
	if (key == echap)
		close_win(data);
//	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	better_render(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_fdf		*data;
	(void)ac;
	(void)av;
	char *img_data;
	(void)img_data;
	int i = 0;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->color = 0xffffff;
	data->size_win_x = 960;
	data->size_win_y = 540;
	data->xtest = 10;
	data->ytest = 10;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->size_win_x , data->size_win_y, "FdF");

	while(i < 1)
	{
		better_render(data);

		printf("Bits per pixel: %d\n", data->bpp);
		printf("Endian: %s-endian\n", data->endian == 0 ? "Little" : "Big");
		printf("Size of each line: %d bytes\n", data->line_len);
		
		i++;
	}

	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_hook(data->win_ptr, 17, 1L<<17, close_win, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
