#ifndef TEXTURES_CUB_H
# define TEXTURES_CUB_H

# define DOOR_TEX "./textures/door.png"
# define SPRITE_TEX "./textures/sprite.png"
# define OPENDOOR_TEX "./textures/opendoor.png"

# define WIDTH 480
# define HIGHT 320
# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3
# define DOOR 4
# define OPENDOOR 5
# define SPRITE 6


struct s_cubed;

typedef struct s_textures{
	mlx_image_t	*img[7];
        mlx_texture_t   *n_texture;
        mlx_texture_t   *s_texture;
        mlx_texture_t   *e_texture;
        mlx_texture_t   *w_texture;
        mlx_texture_t   *d_texture;
	mlx_texture_t	*od_texture;
        mlx_texture_t   *sp_texture;
}	t_tex;

typedef struct	s_draw{
	double			dist_to_wall;
	int			line_height;
	int			start_drawing;
	int			end_drawing;
	int			tex;
	int			texx;
	int			texy;
	double			wallx;
	double			step;
	double			texpos;
	uint32_t		draw_buffer[WIDTH][HIGHT];
}	t_draw;

int	init_tex(struct s_cubed **master);
int	load_textures(struct s_cubed *master);
void	put_rays(int x, t_casting *cast, struct s_cubed *master);

#endif
