#ifndef MINIMAP_CUBED_H
# define MINIMAP_CUBED_H

# define MINI_SIZE 5

struct s_cubed;

typedef struct s_minimap{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;
	int	size;
	int	cur_x;
	int	cur_y;
}	t_minimap;

int	init_minimap(struct s_cubed **master);
void	free_minimap(t_minimap **map);
void	load_minimap(mlx_image_t *img, struct s_cubed *cubed);
void	set_minimap(struct s_cubed *cuebd);

#endif
