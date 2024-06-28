#include "../include.h"

int	gest_key_press(int keycode, t_cube *cube)
{
	if (keycode == 65307)
	{
		gc_free_all();
		exit(1);
	}
	if(keycode == 65362 || keycode == 'w') // Up arrow key
		cube->player->forward = 1;
	if (keycode == 'd') // strafe right
		cube->player->side = 1;
	if (keycode == 'a') // 
		cube->player->side = -1;
	if(keycode == 65364 || keycode == 's') // Down arrow key
		cube->player->forward = -1;
	if(keycode == 65363 || keycode == 'e') // Right arrow key
		cube->player->rot = 1;
	if(keycode == 65361 || keycode == 'q') // left arrow key
		cube->player->rot = -1;
	if(keycode == 65505) // sprint | shift
	{
		cube->player->moveSpeed *= 2;
		cube->player->rotSpeed *= 2;
	}
	return (0);
}
int	gest_key_relase(int keycode, t_cube *cube)
{
	if (keycode == 65307)
		exit(1);
	if(keycode == 65362 || keycode == 'w') // Up arrow key
		cube->player->forward = 0;
	if (keycode == 'd') // strafe right
		cube->player->side = 0;
	if (keycode == 'a') // 
		cube->player->side = 0;
	if(keycode == 65364 || keycode == 's') // Down arrow key
		cube->player->forward = 0;
	if(keycode == 65363 || keycode == 'e') // Right arrow key
		cube->player->rot = 0;
	if(keycode == 65361 || keycode == 'q') // left arrow key
		cube->player->rot = 0;
	if(keycode == 65505) // sprint | shift
	{
		cube->player->moveSpeed /= 2;
		cube->player->rotSpeed /= 2;
	}
	return (0);
}

int	movement(t_cube *cube)
{
	double oldDirX = cube->player->dirX;
	double oldPlaneX = cube->player->planeX;

	if(cube->player->forward == 1) // Up arrow key
	{
		if(cube->worldMap[(int)(cube->player->posX + cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == '0'
			|| cube->worldMap[(int)(cube->player->posX + cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == 'N'
			|| cube->worldMap[(int)(cube->player->posX + cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == 'E'
			|| cube->worldMap[(int)(cube->player->posX + cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == 'S'
			|| cube->worldMap[(int)(cube->player->posX + cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == 'W')
			cube->player->posX += cube->player->dirX * cube->player->moveSpeed;
		if(cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirY * cube->player->moveSpeed)] == '0'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirY * cube->player->moveSpeed)] == 'N'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirY * cube->player->moveSpeed)] == 'E'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirY * cube->player->moveSpeed)] == 'S'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirY * cube->player->moveSpeed)] == 'W')
			cube->player->posY += cube->player->dirY * cube->player->moveSpeed;
	}
	if (cube->player->side == 1)
	{
		if(cube->worldMap[(int)(cube->player->posX + cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == '0'
			|| cube->worldMap[(int)(cube->player->posX + cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == 'N'
			|| cube->worldMap[(int)(cube->player->posX + cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == 'E'
			|| cube->worldMap[(int)(cube->player->posX + cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == 'S'
			|| cube->worldMap[(int)(cube->player->posX + cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == 'W')
			
			cube->player->posX += cube->player->dirY * cube->player->moveSpeed;
		
		if(cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirX * cube->player->moveSpeed)] == '0'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirX * cube->player->moveSpeed)] == 'N'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirX * cube->player->moveSpeed)] == 'E'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirX * cube->player->moveSpeed)] == 'S'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirX * cube->player->moveSpeed)] == 'W')

			cube->player->posY -= cube->player->dirX * cube->player->moveSpeed;
	}
	if (cube->player->side == -1)
	{
		if(cube->worldMap[(int)(cube->player->posX - cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == '0'
			|| cube->worldMap[(int)(cube->player->posX - cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == 'N'
			|| cube->worldMap[(int)(cube->player->posX - cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == 'E'
			|| cube->worldMap[(int)(cube->player->posX - cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == 'S'
			|| cube->worldMap[(int)(cube->player->posX - cube->player->dirY * cube->player->moveSpeed)][(int)cube->player->posY] == 'W')
			cube->player->posX -= cube->player->dirY * cube->player->moveSpeed;
	
		if(cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirX * cube->player->moveSpeed)] == '0'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirX * cube->player->moveSpeed)] == 'N'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirX * cube->player->moveSpeed)] == 'E'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirX * cube->player->moveSpeed)] == 'S'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY + cube->player->dirX * cube->player->moveSpeed)] == 'W')
			cube->player->posY += cube->player->dirX * cube->player->moveSpeed;
	}
	if(cube->player->forward == -1) // Down arrow key
	{
		if(cube->worldMap[(int)(cube->player->posX - cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == '0'
			|| cube->worldMap[(int)(cube->player->posX - cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == 'N' 
			|| cube->worldMap[(int)(cube->player->posX - cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == 'E' 
			|| cube->worldMap[(int)(cube->player->posX - cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == 'S' 
			|| cube->worldMap[(int)(cube->player->posX - cube->player->dirX * cube->player->moveSpeed)][(int)cube->player->posY] == 'W') 
			cube->player->posX -= cube->player->dirX * cube->player->moveSpeed;
		if(cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * cube->player->moveSpeed)] == '0'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * cube->player->moveSpeed)] == 'N'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * cube->player->moveSpeed)] == 'E'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * cube->player->moveSpeed)] == 'S'
			|| cube->worldMap[(int)cube->player->posX][(int)(cube->player->posY - cube->player->dirY * cube->player->moveSpeed)] == 'W')
			cube->player->posY -= cube->player->dirY * cube->player->moveSpeed;
	}
	if(cube->player->rot == 1) // Right arrow key
	{
		cube->player->dirX = cube->player->dirX * cos(-cube->player->rotSpeed) - cube->player->dirY * sin(-cube->player->rotSpeed);
		cube->player->dirY = oldDirX * sin(-cube->player->rotSpeed) + cube->player->dirY * cos(-cube->player->rotSpeed);
		cube->player->planeX = cube->player->planeX * cos(-cube->player->rotSpeed) - cube->player->planeY * sin(-cube->player->rotSpeed);
		cube->player->planeY = oldPlaneX * sin(-cube->player->rotSpeed) + cube->player->planeY * cos(-cube->player->rotSpeed);
	}
	if(cube->player->rot == -1) // left arrow key
	{

		cube->player->dirX = cube->player->dirX * cos(cube->player->rotSpeed) - cube->player->dirY * sin(cube->player->rotSpeed);
		cube->player->dirY = oldDirX * sin(cube->player->rotSpeed) + cube->player->dirY * cos(cube->player->rotSpeed);
		cube->player->planeX = cube->player->planeX * cos(cube->player->rotSpeed) - cube->player->planeY * sin(cube->player->rotSpeed);
		cube->player->planeY = oldPlaneX * sin(cube->player->rotSpeed) + cube->player->planeY * cos(cube->player->rotSpeed);
	}
	return (0);
}
