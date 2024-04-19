#ifndef TEXTURES_CUB_H
# define TEXTURES_CUB_H

# define DOOR_TEX "./textures/door.xpm42"
# define SPRITE_TEX "./textures/sprite.xpm42"

struct s_cubed;

typedef struct s_textures{
	xpm_t	*nw;
	xpm_t	*ew;
	xpm_t	*sw;
	xpm_t	*ww;
	xpm_t	*d;
	xpm_t	*s;
}	t_tex;

int	init_tex(struct s_cubed **master);
int	load_textures(struct s_cubed *master);

#endif
