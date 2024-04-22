#include "cubed.h"

// 'Encodes' four individual bytes into an int.
int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// create a ceiling and a floor -> get user input to do this
void	put_backdrop(mlx_image_t *img, t_cubed *master)
{
	int	z;
	int	z2;

	z = 0;
	while (z < HIGHT)
	{
		z2 = 0;
		while (z2 <= WIDTH)
		{
			if (z < HIGHT / 2)
				put_pixel_cubed(img, z2++, z, get_rgba(\
				master->parser->grafics->sc[0], \
				master->parser->grafics->sc[1], \
				master->parser->grafics->sc[2], 255));
			else
				put_pixel_cubed(img, z2++, z, get_rgba(\
				master->parser->grafics->fc[0], \
				master->parser->grafics->fc[1], \
				master->parser->grafics->fc[2], 255));
		}
		z++;
	}
}
