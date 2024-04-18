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
# include "mimimap_cub.h"

# define WIDTH 1920
# define HIGHT 1080

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
	mlx_image_t	*img;
	t_f_img		*ceiling;
	t_f_img		*floor;
	t_game		*game;
	t_minimap	*map;
	t_casting	*casting;
}	t_cubed;

// /mlx
int		init_window(t_cubed **cubed);

// /graphics
void	put_backdrop(mlx_image_t *img, t_cubed *cubed);
void	put_pixel_cubed(mlx_image_t *img, uint32_t x, uint32_t y, \
		uint32_t color);

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

#endif
