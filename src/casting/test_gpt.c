#include "cubed.h"

void CastRay(t_cubed *cubed, t_ray *ray) 
{
    // Calculate the initial position of the ray
    int mapX = (int)ray->org_x;
    int mapY = (int)ray->org_y;
	printf("-----------------\n");
	printf("mapx: %d, mapy: %d\n", mapX, mapY);

    // Length of ray from one x or y-side to next x or y-side
    float sideDistX;
    float sideDistY;

    // Length of ray from current position to next x or y-side
    float deltaDistX = (ray->step_x == 0) ? 1e30 : fabs(1 / (float)ray->step_x);
    float deltaDistY = (ray->step_y == 0) ? 1e30 : fabs(1 / (float)ray->step_y);
	printf("dx: %f, dy: %f\n", deltaDistX, deltaDistY);
    float perpWallDist;

    // What direction to step in x or y-direction (either +1 or -1)
    int stepX;
    int stepY;

    int hit = 0; // Was there a wall hit?
    int side; // Was a NS or a EW wall hit?

    // Calculate step and initial sideDist
    if (ray->step_x < 0) {
        stepX = -1;
        sideDistX = (ray->org_x - mapX) * deltaDistX;
    } else {
        stepX = 1;
        sideDistX = (mapX + 1.0 - ray->org_x) * deltaDistX;
    }
    if (ray->step_y < 0) {
        stepY = -1;
        sideDistY = (ray->org_y - mapY) * deltaDistY;
    } else {
        stepY = 1;
        sideDistY = (mapY + 1.0 - ray->org_y) * deltaDistY;
    }

    // Perform DDA
    while (hit == 0) {
        // Jump to next map square, in x-direction or in y-direction
        if (sideDistX < sideDistY) {
            sideDistX += deltaDistX;
            mapX += stepX;
            side = 0;
        } else {
            sideDistY += deltaDistY;
            mapY += stepY;
            side = 1;
        }
        // Check if ray has hit a wall
        if (ray_check_hit(cubed, ray) > 0) hit = 1;
    }

    // Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!)
    if (side == 0) perpWallDist = (mapX - ray->org_x + (1 - stepX) / 2) / ray->step_x;
    else perpWallDist = (mapY - ray->org_y + (1 - stepY) / 2) / ray->step_y;

	printf("perpwall gpt = %f\n", perpWallDist);

    // Now perpWallDist can be used to calculate the height of the wall slice to draw on screen
}