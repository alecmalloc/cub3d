#include "cubed.h"
//load the images to textures then image ptr to main struct

int	make_image(t_cubed *master)
{
	mlx_image_t	*new;
//	xpm_t		*screen;

	new = mlx_new_image(master->mlx_inst, WIDTH, HIGHT);
	if (!new)
		return (MLX_IMG_ERR);
	put_backdrop(new, master);
	//casting stuff
	load_minimap(new, master);
	if (master->img)
		mlx_delete_image(master->mlx_inst, master->img);
//	screen = mlx_load_xpm42("./textures/screen.xpm42");
//	new = mlx_texture_to_image(master->mlx_inst, &screen->texture);
//	master->img = new;
	if (mlx_image_to_window(master->mlx_inst, new, 0, 0) < 0)
		return (MLX_IMG_ERR);
	return (0);
}
