#ifndef TEXTURES_CUB_H
# define TEXTURES_CUB_H

# define DOOR_TEX "./textures/door.png"
# define OPENDOOR_TEX "./textures/opendoor.png"
# define SPRITE1_TEX "./textures/sprite1.png"
# define SPRITE2_TEX "./textures/sprite2.png"
# define SPRITE3_TEX "./textures/sprite3.png"
# define SPRITE4_TEX "./textures/sprite4.png"
# define SPRITE5_TEX "./textures/sprite5.png"
# define SPRITE6_TEX "./textures/sprite6.png"
# define SPRITE7_TEX "./textures/sprite7.png"
# define SPRITE8_TEX "./textures/sprite8.png"
# define SPRITE9_TEX "./textures/sprite9.png"
# define SPRITE10_TEX "./textures/sprite10.png"

# define WIDTH 1000
# define HIGHT 800
# define NORTH 0
# define EAST 1
# define SOUTH 2
# define WEST 3
# define DOOR 4
# define OPENDOOR 5
# define SPRITE1 6
# define SPRITE2 7
# define SPRITE3 8
# define SPRITE4 9
# define SPRITE5 10
# define SPRITE6 11
# define SPRITE7 12
# define SPRITE8 13
# define SPRITE9 14
# define SPRITE10 15


struct s_cubed;

typedef struct s_textures{
	mlx_image_t	*img[16];
	double		spritenbr;
	double		spritemove;
        mlx_texture_t   *n_texture;
        mlx_texture_t   *s_texture;
        mlx_texture_t   *e_texture;
        mlx_texture_t   *w_texture;
        mlx_texture_t   *d_texture;
	mlx_texture_t	*od_texture;
        mlx_texture_t   *sp_texture[10];
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
void	decide_sprite(struct s_cubed *master);
int	load_textures(struct s_cubed *master);
int	load_sprites(struct s_cubed *master);
void	put_rays(int x, t_casting *cast, struct s_cubed *master);

#endif
