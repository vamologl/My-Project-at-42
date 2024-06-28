#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define screenWidth 640
#define screenHeight 480
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24

typedef struct {
    void *mlx;
    void *win;
    void *img;
    char *img_data;
    int bpp;
    int size_line;
    int endian;
    int **texture;
    double posX, posY; // player position
    double dirX, dirY; // direction vector
    double planeX, planeY; // camera plane
} t_game;

int worldMap[mapWidth][mapHeight]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

void loadTexture(t_game *game, char *file, int texture_num) {
    int width, height;
    void *img = mlx_xpm_file_to_image(game->mlx, file, &width, &height);
    int *texture = (int *)mlx_get_data_addr(img, &game->bpp, &game->size_line, &game->endian);
    game->texture[texture_num] = (int *)malloc(texWidth * texHeight * sizeof(int));
    for (int y = 0; y < texHeight; y++) {
        for (int x = 0; x < texWidth; x++) {
            game->texture[texture_num][texWidth * y + x] = texture[y * width + x];
        }
    }
    mlx_destroy_image(game->mlx, img);
}

void loadTextures(t_game *game) {
    loadTexture(game, "eagle.xpm", 0);
    loadTexture(game, "redbrick.xpm", 1);
    loadTexture(game, "purplestone.xpm", 2);
    loadTexture(game, "greystone.xpm", 3);
    loadTexture(game, "bluestone.xpm", 4);
    loadTexture(game, "mossy.xpm", 5);
    loadTexture(game, "wood.xpm", 6);
    loadTexture(game, "colorstone.xpm", 7);
}

void drawBuffer(t_game *game, int buffer[screenHeight][screenWidth]) {
    for (int y = 0; y < screenHeight; y++) {
        for (int x = 0; x < screenWidth; x++) {
            int color = buffer[y][x];
            int pixel = (y * game->size_line) + (x * (game->bpp / 8));
            game->img_data[pixel] = color;
            game->img_data[pixel + 1] = color >> 8;
            game->img_data[pixel + 2] = color >> 16;
        }
    }
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int keyPress(int key, t_game *game) {
    if (key == 65307) // ESC key
        exit(0);

    double moveSpeed = 0.1; // adjust accordingly
    double rotSpeed = 0.1;  // adjust accordingly

    if (key == 119) // W key
    {
        if (worldMap[(int)(game->posX + game->dirX * moveSpeed)][(int)game->posY] == 0) game->posX += game->dirX * moveSpeed;
        if (worldMap[(int)game->posX][(int)(game->posY + game->dirY * moveSpeed)] == 0) game->posY += game->dirY * moveSpeed;
    }
    if (key == 115) // S key
    {
        if (worldMap[(int)(game->posX - game->dirX * moveSpeed)][(int)game->posY] == 0) game->posX -= game->dirX * moveSpeed;
        if (worldMap[(int)game->posX][(int)(game->posY - game->dirY * moveSpeed)] == 0) game->posY -= game->dirY * moveSpeed;
    }
    if (key == 100) // D key
    {
        double oldDirX = game->dirX;
        game->dirX = game->dirX * cos(-rotSpeed) - game->dirY * sin(-rotSpeed);
        game->dirY = oldDirX * sin(-rotSpeed) + game->dirY * cos(-rotSpeed);
        double oldPlaneX = game->planeX;
        game->planeX = game->planeX * cos(-rotSpeed) - game->planeY * sin(-rotSpeed);
        game->planeY = oldPlaneX * sin(-rotSpeed) + game->planeY * cos(-rotSpeed);
    }
    if (key == 97) // A key
    {
        double oldDirX = game->dirX;
        game->dirX = game->dirX * cos(rotSpeed) - game->dirY * sin(rotSpeed);
        game->dirY = oldDirX * sin(rotSpeed) + game->dirY * cos(rotSpeed);
        double oldPlaneX = game->planeX;
        game->planeX = game->planeX * cos(rotSpeed) - game->planeY * sin(rotSpeed);
        game->planeY = oldPlaneX * sin(rotSpeed) + game->planeY * cos(rotSpeed);
    }

    return 0;
}

void raycast(t_game *game) {
    int buffer[screenHeight][screenWidth];

    for (int x = 0; x < screenWidth; x++) {
        double cameraX = 2 * x / (double)screenWidth - 1;
        double rayDirX = game->dirX + game->planeX * cameraX;
        double rayDirY = game->dirY + game->planeY * cameraX;

        int mapX = (int)game->posX;
        int mapY = (int)game->posY;

        double sideDistX;
        double sideDistY;

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        int stepX;
        int stepY;

        int hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (game->posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->posX) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (game->posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->posY) * deltaDistY;
        }

        while (hit == 0) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (worldMap[mapX][mapY] > 0) hit = 1;
        }

        if (side == 0) perpWallDist = (mapX - game->posX + (1 - stepX) / 2) / rayDirX;
        else perpWallDist = (mapY - game->posY + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(screenHeight / perpWallDist);

        int drawStart = -lineHeight / 2 + screenHeight / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + screenHeight / 2;
        if (drawEnd >= screenHeight) drawEnd = screenHeight - 1;

        int texNum = worldMap[mapX][mapY] - 1;

        double wallX;
        if (side == 0) wallX = game->posY + perpWallDist * rayDirY;
        else wallX = game->posX + perpWallDist * rayDirX;
        wallX -= floor((wallX));

        int texX = (int)(wallX * (double)texWidth);
        if (side == 0 && rayDirX > 0) texX = texWidth - texX - 1;
        if (side == 1 && rayDirY < 0) texX = texWidth - texX - 1;

        double step = 1.0 * texHeight / lineHeight;
        double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;

        for (int y = drawStart; y < drawEnd; y++) {
            int texY = (int)texPos & (texHeight - 1);
            texPos += step;
            int color = game->texture[texNum][texHeight * texY + texX];
            if (side == 1) color = (color >> 1) & 8355711;
            buffer[y][x] = color;
        }
    }
    drawBuffer(game, buffer);
}

int main() {
    t_game game;

    game.posX = 22.0;
    game.posY = 11.5;
    game.dirX = -1.0;
    game.dirY = 0.0;
    game.planeX = 0.0;
    game.planeY = 0.66;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, screenWidth, screenHeight, "Raycaster");

    game.img = mlx_new_image(game.mlx, screenWidth, screenHeight);
    game.img_data = mlx_get_data_addr(game.img, &game.bpp, &game.size_line, &game.endian);

    game.texture = (int **)malloc(8 * sizeof(int *));
    loadTextures(&game);

    mlx_hook(game.win, 2, 1L << 0, keyPress, &game);
    while (1) {
        raycast(&game);
        mlx_loop(game.mlx);
    }

    return 0;
}
