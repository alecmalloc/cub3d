#ifndef CASTING_H
# define CASTING_H

typedef struct ray {
	int step_x;
	int	step_y;
	double org_x;
	double org_y;
	double angle;
	double angle_r;
	double ray_len_x;
	double ray_len_y;
} t_ray;

typedef struct casting {
	double	resolution_w;
} t_casting;

#endif