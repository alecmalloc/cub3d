#include "cubed.h"

void	calc_focal_len(t_cubed *cubed)
{
    double fov = 72.0;
    double fov_r = fov * (M_PI / 180.0); // Convert degrees to radians

    cubed->casting->focal_len = (cubed->casting->resolution_w / 2.0) / tan(fov_r / 2.0);
	printf("focal len: %f\n", cubed->casting->focal_len);
}

double		get_ray_angle(t_cubed *cubed, int column)
{
	double angle_r;
	double normalized_x;

	normalized_x =  (double)column / cubed->casting->resolution_w - 0.5;
	angle_r = atan2(normalized_x, (double)cubed->casting->focal_len);
	return (angle_r);
}

void	casting(t_cubed *cubed)
{
	double angle;

	calc_focal_len(cubed);
	angle = get_ray_angle(cubed, 0);
	printf("ray angle = %f\n", angle);
	angle = get_ray_angle(cubed, 800);
	printf("ray angle = %f\n", angle);
}