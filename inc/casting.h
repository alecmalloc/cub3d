#ifndef CASTING_H
# define CASTING_H



# define OUT_ERR 501
# define HIT_WALL 501

typedef struct ray {
	int step_x;
	int	step_y;
	double org_x;
	double org_y;
	double map_x;
	double map_y;
	double angle;
	double angle_r;
	double len_x;
	double len_y;
} t_ray;

typedef struct casting {
	double	resolution_w;
} t_casting;

#endif