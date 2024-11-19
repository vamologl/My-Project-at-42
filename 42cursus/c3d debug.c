#include "../include.h"

char* doubleToString(double value) // debug, to remove
{
	char *str = (char *)gc_alloc(32 * sizeof(char), 1);
	if (str == NULL)
	{
		printf("Memory allocation failed\n");
		exit(1);
	}
	snprintf(str, 32, "%lf", value);
	return str;
}

int print_texture(t_cube *cube)
{
	if (!cube->texture || !cube->texture2)
	{
		printf("texture did not load :(\n");
		return 1;
	}
	mlx_put_image_to_window(cube->mlx, cube->win, cube->texture->img,screenWidth
		/ 20 + 100, screenHeight / 12 + 150);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->texture2->img,screenWidth
		/ 20 + 100, screenHeight / 12 + 224);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->texture3->img,screenWidth
		/ 20 + 100, screenHeight / 12 + 298);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->texture1->img,screenWidth
		/ 20 + 100, screenHeight / 12 + 372);

	return 0;
}

void	debug_display_value(t_cube *cube)
{
	char *s;
	// THE DEBUG !

	// crosshair
	print_texture(cube);

	mlx_pixel_put(cube->mlx, cube->win, screenWidth
		/ 2, screenHeight / 2, 0xffffff);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth
		/ 2, screenHeight / 2 + 2, 0xff00bc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth
		/ 2, screenHeight / 2 + 1, 0xffbcbc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth
		/ 2, screenHeight / 2 - 1, 0xffbcbc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth
		/ 2, screenHeight / 2 - 2, 0xff00bc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth
		/ 2 + 2, screenHeight / 2, 0xff00bc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth
		/ 2 + 1, screenHeight / 2, 0xffbcbc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth
		/ 2 - 1, screenHeight / 2, 0xffbcbc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth
		/ 2 - 2, screenHeight / 2, 0xff00bc);
	// info

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 - 30, 0xffffff, "res Y = ");
	s = ft_itoa(screenHeight);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 - 30, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 - 15, 0xffffff, "res X = ");
	s = ft_itoa(screenWidth);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 - 15, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12, 0xffffff, "player posy = ");
	s = doubleToString(cube->player->posy);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 15, 0xffffff, "player posx = ");
	s = doubleToString(cube->player->posx);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 + 15, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 30, 0xffffff, "player diry = ");
	s = doubleToString(cube->player->diry);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 + 30, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 45, 0xffffff, "player dirx = ");
	s = doubleToString(cube->player->dirx);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 + 45, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 60, 0xffffff, "player planey = ");
	s = doubleToString(cube->player->planey);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 + 60, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 75, 0xffffff, "player planex = ");
	s = doubleToString(cube->player->planex);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 + 75, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 90, 0xffffff, "camera dirx = ");
	s = doubleToString(cube->player->dirx);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 + 90, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 105, 0xffffff, "camera diry = ");
	s = doubleToString(cube->player->diry);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 + 105, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 120, 0xffffff, "camera planex = ");
	s = doubleToString(cube->player->planex);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 + 120, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 135, 0xffffff, "camera planey = ");
	s = doubleToString(cube->player->planey);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20 + 100, screenHeight / 12 + 135, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 160, 0xffffff, "texture 0 = ");
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 234, 0xffffff, "texture 2 = ");
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 308, 0xffffff, "texture 1 = ");
	mlx_string_put(cube->mlx, cube->win, screenWidth / 20, screenHeight / 12 + 382, 0xffffff, "texture 3 = ");		
}