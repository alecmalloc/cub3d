#ifndef CUBED_H
# define CUBED_H

// c lib includes
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>
# include <math.h>

// include libft
# include "../libft/includes/libft.h"

// include MLX42
# include "../MLX42/include/MLX42/MLX42.h"

// include cub3d headers
# include "parser_cub.h"
# include "error_cub.h"
# include "game_cub.h"
# include "casting.h"

# define WIDTH 1800
# define HIGHT 800
// strucure for custom RBG filled images
typedef struct Fill_img
{
	mlx_image_t	*image;
	int			r;
	int			g;
	int			b;
}	t_f_img;

// cubed main struct to store most everything
typedef struct s_cubed
{
	t_parser	*parser;
	mlx_t		*mlx_inst;
	t_f_img		*ceiling;
	t_f_img		*floor;
	t_game		*game;
	t_casting	*casting;
}	t_cubed;

// /mlx
int		window_init(t_cubed	*cubed);

// /graphics
void	put_backdrop(t_cubed *cubed);

// /structs
void	*init_structs(t_cubed *cubed);
void	destroy_structs(t_cubed *cubed);
// /init
int		init_all(t_cubed **cubed);
// /free
void	free_all(t_cubed **cubed);
// /error
int		print_error(int err_code, t_cubed **cubed);
// /parser
int		parser(char *pathname, t_cubed *master);
//start game
int		start_game(t_cubed *master);

// / casting
int		casting(t_cubed *cubed);
double	conv_deg_rad(double deg);
double	conv_rad_deg(double rad);
void	print_ray(t_ray *ray);
void	print_map_c(t_cubed *cubed);
int		ray_check_hit_out(t_cubed *cubed, t_ray *ray);
int		ray_check_outside(t_cubed *cubed, t_ray *ray);
int		ray_check_hit(t_cubed *cubed, t_ray *ray);
int		init_ray(t_ray **ray, double angle, double org_x, double org_y);
int		init_spread_rays(t_cubed *cubed, double angle, double pos_x, double pos_y);
void	ray_calc_steps(t_cubed *cubed, t_ray *ray);
void	set_steps_x_y(t_ray *ray);
void	ray_vector_x(t_cubed *cubed, t_ray *ray);
void	ray_vector_y(t_cubed *cubed, t_ray *ray);
void	calc_step_x(t_cubed *cubed, t_ray *ray);
void	calc_step_y(t_cubed *cubed, t_ray *ray);

#endif
