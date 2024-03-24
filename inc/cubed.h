#ifndef CUBED_H
# define CUBED_H

// c lib includes
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <stdio.h>

// include libft
# include "../libft/includes/libft.h"

// include MLX42
# include "../MLX42/include/MLX42/MLX42.h"

// include cub3d headers
# include "parser_cub.h"
# include "error_cub.h"
# include "game_cub.h"

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

#endif
