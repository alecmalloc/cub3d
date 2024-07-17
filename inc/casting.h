#ifndef CASTING_H
# define CASTING_H



# define OUT_ERR 501
# define HIT_WALL 502


typedef struct casting {
	char **map;
	int    x;
	double pos_x;
	double pos_y;
	double angle_d;
	double angle_r;
	double dir_x;
	double dir_y;
	double fov;
	double plane_len;

	double plane_x;
	double plane_y;

	int screen_w;
	int screen_h;

	double camera_x;
	double ray_dir_x; 
	double ray_dir_y;

	int map_x; 
	int map_y; 

	double side_dist_x;
	double side_dist_y;
	double delta_dist_x; 
	double delta_dist_y; 

	int step_x;
	int step_y;

	int side;

	double perp_wall_dist;
	int line_height;
	int draw_start;
	int draw_end;
} t_casting;

#endif
