#ifndef GAME_CUB_H
# define GAME_CUB_H

# define MOVESPEED 0.25
# define ROTSPEED 0.10

struct Cubed;

typedef struct s_game
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		l;
	int		r;
	int		space;
	int		dir;
	char	**map;
	double	pos[2];

}	t_game;

int	init_game(t_game **game);
void	free_game(t_game **game);

int	move(struct Cubed *master);
void	set_mlx(struct Cubed *master);
#endif
