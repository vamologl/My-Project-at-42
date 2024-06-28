#include "../include.h"

void	init_raycast(t_raycast *ray, int x, t_cube *cube)
{
	ray->cameraX = 2 * x / (double)screenWidth - 1;
	ray->rayDirX = cube->player->dirX + cube->player->planeX * ray->cameraX;
	ray->rayDirY = cube->player->dirY + cube->player->planeY * ray->cameraX;
	ray->mapX = (int)cube->player->posX;
	ray->mapY = (int)cube->player->posY;
	if (ray->rayDirX == 0)
		ray->deltaDistX = INT_MAX;
	else
		ray->deltaDistX = fabs(1 / ray->rayDirX);
	if (ray->rayDirY == 0)
		ray->deltaDistY = INT_MAX;
	else
		ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
}

void	color(t_raycast *ray, t_cube *cube)
{
	if(cube->worldMap[ray->mapX][ray->mapY] == '1')
	{
		if (ray->side == 0 && ray->rayDirX < 0)
			ray->color = 0x6b00e6; // walls
		else if (ray->side == 0 && ray->rayDirX > 0)
			ray->color = 0xff00bc; // walls
		else if (ray->side == 1 && ray->rayDirY > 0)
			ray->color = 0x00bcff; // walls
		else if (ray->side == 1 && ray->rayDirY < 0)
			ray->color = 0xffffff; // walls

	}
	else
		ray->color = 0x00ff00; // unknown
}

void	draw_line(t_cube *cube, int x, int drawStart, int drawEnd, int color)
{
	int y;
	int pixel;
	y = drawStart;
	while (y < drawEnd)
	{
		y++;
		pixel = (y * cube->size_line) + (x * (cube->bits_per_pixel / 8));
		*(int *)(cube->data_addr + pixel) = color;
	}
}

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

void draw_background(t_cube *cube)
{
	int x;

	x = 0;
	while (x < screenWidth)
	{
		draw_line(cube, x, 0, screenHeight, cube->color_c);
		draw_line(cube, x, screenHeight / 2, screenHeight, cube->color_f);
		// draw_line(cube, x, screenHeight / 2, screenHeight, 0x808080);
		x++;
	}
}

void	cast_ray(t_cube *cube, int x) // N only, rest E S W not currently supported
{
	t_raycast   *ray;
	
	ray = malloc(sizeof(t_raycast));
	init_raycast(ray, x, cube);
	if(ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (cube->player->posX - ray->mapX) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - cube->player->posX) * ray->deltaDistX;
	}
	if(ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (cube->player->posY - ray->mapY) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - cube->player->posY) * ray->deltaDistY;
	}
	while(ray->hit == 0)
	{
		if(ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		if(cube->worldMap[ray->mapX] && cube->worldMap[ray->mapX][ray->mapY] != '0' && cube->worldMap[ray->mapX][ray->mapY] != 'N'
			&& cube->worldMap[ray->mapX][ray->mapY] != 'S' && cube->worldMap[ray->mapX][ray->mapY] != 'E'
				&& cube->worldMap[ray->mapX][ray->mapY] != 'W')
			ray->hit = 1;
	}


	if(ray->side == 0)
		ray->perpWallDist = (ray->sideDistX - ray->deltaDistX);	
	else         
		ray->perpWallDist = (ray->sideDistY - ray->deltaDistY);

	ray->lineHeight = (int)(screenHeight / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + screenHeight / 2;

	if(ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + screenHeight / 2;
	
	if(ray->drawEnd >= screenHeight)
		ray->drawEnd = screenHeight - 1;

	color(ray, cube);

	draw_line(cube, x, ray->drawStart , ray->drawEnd, ray->color);

	free(ray);
}

int	draw_loop(t_cube *cube)
{
	int x;
	char *s;

	x = 0;
	cube->img = mlx_new_image(cube->mlx, screenWidth, screenHeight);
	cube->data_addr = mlx_get_data_addr(cube->img, &cube->bits_per_pixel, &cube->size_line, &cube->endian);

	draw_background(cube);
	movement(cube);

	while (x < screenWidth)
	{
		cast_ray(cube, x);
		x++;
	}
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img);

	// crosshair
	mlx_pixel_put(cube->mlx, cube->win, screenWidth / 2, screenHeight / 2, 0xffffff);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth / 2, screenHeight / 2 + 2, 0xff00bc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth / 2, screenHeight / 2 + 1, 0xffbcbc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth / 2, screenHeight / 2 - 1, 0xffbcbc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth / 2, screenHeight / 2 - 2, 0xff00bc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth / 2 + 2, screenHeight / 2, 0xff00bc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth / 2 + 1, screenHeight / 2, 0xffbcbc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth / 2 - 1, screenHeight / 2, 0xffbcbc);
	mlx_pixel_put(cube->mlx, cube->win, screenWidth / 2 - 2, screenHeight / 2, 0xff00bc);


	// THE DEBUG !

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8, 0xffffff, "player posY = ");
	s = doubleToString(cube->player->posY);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8 + 15, 0xffffff, "player posX = ");
	s = doubleToString(cube->player->posX);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8 + 15, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8 + 30, 0xffffff, "player dirY = ");
	s = doubleToString(cube->player->dirY);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8 + 30, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8 + 45, 0xffffff, "player dirX = ");
	s = doubleToString(cube->player->dirX);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8 + 45, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8 + 60, 0xffffff, "player planeY = ");
	s = doubleToString(cube->player->planeY);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8 + 60, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8 + 75, 0xffffff, "player planeX = ");
	s = doubleToString(cube->player->planeX);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8 + 75, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8 + 90, 0xffffff, "camera dirX = ");
	s = doubleToString(cube->player->dirX);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8 + 90, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8 + 105, 0xffffff, "camera dirY = ");
	s = doubleToString(cube->player->dirY);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8 + 105, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8 + 120, 0xffffff, "camera planeX = ");
	s = doubleToString(cube->player->planeX);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8 + 120, 0xffffff, s);
	free(s);

	mlx_string_put(cube->mlx, cube->win, screenWidth / 10, screenHeight / 8 + 135, 0xffffff, "camera planeY = ");
	s = doubleToString(cube->player->planeY);
	mlx_string_put(cube->mlx, cube->win, screenWidth / 10 + 100, screenHeight / 8 + 135, 0xffffff, s);
	free(s);



	return (0);
}
