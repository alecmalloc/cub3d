#ifndef CASTING_H
# define CASTING_H



# define OUT_ERR 501
# define HIT_WALL 502

typedef struct ray {
	int hit;
	double	step_x;
	double	step_y;
	double org_x;
	double org_y;
	double map_x;
	double map_y;
	double angle;
	double angle_r;
	double len_x;
	double len_y;
	double delta_x;
	double delta_y;
} t_ray;

typedef struct casting {
	double	resolution_w;
} t_casting;

#endif