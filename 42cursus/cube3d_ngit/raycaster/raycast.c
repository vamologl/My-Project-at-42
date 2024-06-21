#include "../include.h"

void	init_raycast(t_raycast *ray, int x, t_cube *cube)
{
	ray->cameraX = 2 * x / (double)screenWidth - 1;
	ray->rayDirX = cube->player->dirX + cube->player->planeX * ray->cameraX;
	ray->rayDirY = cube->player->dirY + cube->player->planeY * ray->cameraX;
	ray->mapX = (int)cube->player->posX;
	ray->mapY = (int)cube->player->posY;
	ray->deltaDistX = (ray->rayDirX == 0) ? 2147 : fabs(1 / ray->rayDirX); // to change
	ray->deltaDistY = (ray->rayDirY == 0) ? 2147 : fabs(1 / ray->rayDirY); // to change
	ray->hit = 0;
}

void	color(t_raycast *ray, t_cube *cube)
{
	if(cube->worldMap[ray->mapX][ray->mapY] == '1')
		ray->color = 0x6b6b6b;
	else if(cube->worldMap[ray->mapX][ray->mapY] == '2') 
		ray->color = 0x8a8a8a;
	else if(cube->worldMap[ray->mapX][ray->mapY] == '3')
		ray->color = 0x424242;
	else if(cube->worldMap[ray->mapX][ray->mapY] == '4')
		ray->color = 0xFFFFFF;
	else
		ray->color = 0x6b00e6;
	if(ray->side == 1)
		ray->color = ray->color / 2;	
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

void draw_background(t_cube *cube)
{
	int x;

	x = 0;
	while (x < screenWidth)
	{
		draw_line(cube, x, 0, screenHeight, 0x00dfff);
		draw_line(cube, x, screenHeight / 2, screenHeight, 0x00ab00);
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
		if(cube->worldMap[ray->mapX] && cube->worldMap[ray->mapX][ray->mapY] > '0')
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

	draw_line(cube, x, ray->drawStart, ray->drawEnd, ray->color);
	free(ray);
}

int	main_loop(t_cube *cube)
{
	int x;

	x = 0;
	cube->img = mlx_new_image(cube->mlx, screenWidth, screenHeight);
	cube->data_addr = mlx_get_data_addr(cube->img, &cube->bits_per_pixel, &cube->size_line, &cube->endian);

	printf("player posY = %f\n", cube->player->posY);
	printf("player posX = %f\n", cube->player->posX);
	printf("player dirY = %f\n", cube->player->dirY);
	printf("player dirX = %f\n", cube->player->dirX);
	printf("player planeY = %f\n", cube->player->planeY);
	printf("player planeX = %f\n", cube->player->planeX);
	draw_background(cube);
	while (x < screenWidth)
	{
		cast_ray(cube, x);
		x++;
	}
	mlx_put_image_to_window(cube->mlx, cube->win, cube->img, 0, 0);
	mlx_destroy_image(cube->mlx, cube->img);
	return 0;
}
