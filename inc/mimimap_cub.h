#ifndef MINIMAP_CUBED_H
# define MINIMAP_CUBED_H

struct s_cubed;

typedef struct s_minimap{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	cur_x;
	int	cur_y;
}	t_map;

void	load_minimap(struct s_cubed *cubed);

#endif
