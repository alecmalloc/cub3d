#include "cubed.h"

int	init_game(t_game **game)
{
	*game = (t_game *)malloc(sizeof(t_game));
	if (!*game)
		return (MALL_ERR);
	(*game)->w = 0;
	(*game)->a = 0;
	(*game)->s = 0;
	(*game)->d = 0;
	(*game)->l = 0;
	(*game)->r = 0;
	(*game)->space = 0;
	(*game)->dir = 0;
	(*game)->pos[0] = 0;
	(*game)->pos[1] = 0;
	(*game)->map = NULL;
	return (0);
}

void	free_game(t_game **game)
{
	free(*game);
}
