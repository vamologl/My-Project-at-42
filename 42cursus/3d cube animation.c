
#include "include.h"
#include <math.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>

#define WIDTH 800
#define HEIGHT 600
#define CUBE_SIZE 100

typedef struct {
    double x;
    double y;
    double z;
} t_point3d;

typedef struct {
    int x;
    int y;
} t_point2d;

typedef struct {
    void *mlx;
    void *win;
    t_point3d cube[8];
    double angle_x;
    double angle_y;
    double angle_z;
} t_mlx;

t_point3d rotate_point(t_point3d point, double angle_x, double angle_y, double angle_z) {
    t_point3d result;
    double rad_x = angle_x * M_PI / 180;
    double rad_y = angle_y * M_PI / 180;
    double rad_z = angle_z * M_PI / 180;
    
	(void)rad_y;
	(void)rad_z;
    // Rotation around x-axis
    result.y = point.y * cos(rad_x) - point.z * sin(rad_x);
    result.z = point.y * sin(rad_x) + point.z * cos(rad_x);
    point.y = result.y;
    point.z = result.z;
    
    // // Rotation around y-axis
    result.x = point.x * cos(rad_y) + point.z * sin(rad_y);
    result.z = -point.x * sin(rad_y) + point.z * cos(rad_y);
    point.x = result.x;
    point.z = result.z;
    
    // Rotation around z-axis
    // result.x = point.x * cos(rad_z) - point.y * sin(rad_z);
    // result.y = point.x * sin(rad_z) + point.y * cos(rad_z);
    result.z = point.z;

    return result;
}

t_point2d project_point(t_point3d point, double distance) {
    t_point2d result;
    result.x = (int)((point.x * distance) / (point.z + distance) + WIDTH / 2);
    result.y = (int)((point.y * distance) / (point.z + distance) + HEIGHT / 2);
    return result;
}

void draw_line(void *mlx, void *win, t_point2d p1, t_point2d p2) {
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx = (p1.x < p2.x) ? 1 : -1;
    int sy = (p1.y < p2.y) ? 1 : -1;
    int err = dx - dy;
    
    while (1) {
        mlx_pixel_put(mlx, win, p1.x, p1.y, 0xFFFFFF);
        if (p1.x == p2.x && p1.y == p2.y) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; p1.x += sx; }
        if (e2 < dx) { err += dx; p1.y += sy; }
    }
}

void draw_cube(t_mlx *mlx) {
    int edges[12][2] = {
        {0, 1}, {1, 2}, {2, 3}, {3, 0},
        {4, 5}, {5, 6}, {6, 7}, {7, 4},
        {0, 4}, {1, 5}, {2, 6}, {3, 7}
    };
    t_point2d projected[8];
    double distance = 1000.0;
    
    for (int i = 0; i < 8; i++) {
        t_point3d rotated = rotate_point(mlx->cube[i], mlx->angle_x, mlx->angle_y, mlx->angle_z);
        projected[i] = project_point(rotated, distance);
    }
    
    for (int i = 0; i < 12; i++) {
        draw_line(mlx->mlx, mlx->win, projected[edges[i][0]], projected[edges[i][1]]);
    }
}

int render_frame(t_mlx *mlx) {
    mlx_clear_window(mlx->mlx, mlx->win);
    draw_cube(mlx);
    mlx->angle_x += 0.01;
    mlx->angle_y += 0.01;
    mlx->angle_z += 0.01;
    return 0;
}

int main() {
    t_mlx mlx;
    t_point3d initial_cube[8] = {
        {-CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE},
        { CUBE_SIZE, -CUBE_SIZE, -CUBE_SIZE},
        { CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE},
        {-CUBE_SIZE,  CUBE_SIZE, -CUBE_SIZE},
        {-CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE},
        { CUBE_SIZE, -CUBE_SIZE,  CUBE_SIZE},
        { CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE},
        {-CUBE_SIZE,  CUBE_SIZE,  CUBE_SIZE}
    };

    for (int i = 0; i < 8; i++) {
        mlx.cube[i] = initial_cube[i];
    }
    
    mlx.angle_x = 0.0;
    mlx.angle_y = 0.0;
    mlx.angle_z = 0.0;

    mlx.mlx = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx, WIDTH, HEIGHT, "3D Rotating Cube");

    mlx_loop_hook(mlx.mlx, render_frame, &mlx);
    mlx_loop(mlx.mlx);

    return 0;
}
