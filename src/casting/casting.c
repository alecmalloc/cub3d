#include "cubed.h"

void	calc_focal_len(t_cubed *cubed)
{
    int fov = 90;
    double fov_r = fov * (M_PI / 180.0); // Convert degrees to radians

    cubed->casting->focal_len = (cubed->casting->resolution_w / 2.0) / tan(fov_r / 2.0);
}

double		get_ray_angle(t_cubed *cubed, int column)
{
	double angle_d;
	double angle_r;
	double normalized_x;

	normalized_x =  (double)column / cubed->casting->resolution_w - 0.5;
	printf("Normalized x: %f\n", normalized_x);
	angle_r = atan2(normalized_x, (double)cubed->casting->focal_len);
	printf("angle_r: %f\n", angle_r);
	angle_d = angle_r * (180 / M_PI);
	printf("angle_d: %f\n", angle_d);
	return (angle_d);
}

void	casting(t_cubed *cubed)
{
	double angle;

	calc_focal_len(cubed);
	angle = get_ray_angle(cubed, 0);
	printf("ray angle = %f\n", angle);
}