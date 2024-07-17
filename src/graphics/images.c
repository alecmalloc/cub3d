#include "cubed.h"
//load the images to textures then image ptr to main struct

int	make_image(t_cubed *master)
{
	mlx_image_t	*new;
	int		z;
	int		z2;

	new = mlx_new_image(master->mlx_inst, WIDTH, HIGHT);
	if (!new)
		return (MLX_IMG_ERR);
	put_backdrop(master);
	simple_caster(master);
	load_minimap(master);
	z = 0;
	z2 = 0;
	while (z < WIDTH)
	{
		z2 = 0;
		while(z2 < HIGHT)
		{
			put_pixel_cubed(new, z, z2, master->draw->draw_buffer\
				[z][z2]);	
			z2++;
		}
		z++;
	}
	if (mlx_image_to_window(master->mlx_inst, new, 0, 0) < 0)
		return (MLX_IMG_ERR);
	//if (new)
	//	mlx_delete_image(master->mlx_inst, new);
	return (0);
}
