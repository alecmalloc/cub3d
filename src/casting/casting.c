#include "cubed.h"

void	set_steps_x_y(int *step_x, int *step_y, double angle)
{
	*step_x = 0;
	*step_y = 0;
	if (angle > 90 && angle < 270)
		*step_x = -1;
	if (angle > 270 || angle < 90)
		*step_x = 1;
	if (angle > 180 && angle < 360)
		*step_y = -1;
	if (angle < 180 && angle > 0)
		*step_y = 1;
}

void	ray_calc_steps(double pos_x, double pos_y, double angle)
{
	int step_x;
	int	step_y;
	(void)pos_x;
	(void)pos_y;

	set_steps_x_y(&step_x, &step_y, angle);
	printf("stepx: %d stepy: %d\n", step_x, step_y);
}

void	casting(t_cubed *cubed)
{
	double angle;
	(void)cubed;

	angle = 360;
	ray_calc_steps(3.5, 3.5, angle);
}