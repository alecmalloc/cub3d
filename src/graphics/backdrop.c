#include "cubed.h"

// 'Encodes' four individual bytes into an int.
uint32_t	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

// create a ceiling and a floor -> get user input to do this
void	put_backdrop(t_cubed *master)
{
	int	z;
	int	z2;

	z = 0;
	while (z < WIDTH)
	{
		z2 = 0;
		while (z2 < HIGHT)
		{
			if (z2 < HIGHT / 2)
				master->draw->draw_buffer[z][z2] = \
				get_rgba(master->parser->grafics->sc[0], \
				master->parser->grafics->sc[1], \
				master->parser->grafics->sc[2], 255);
			else
				master->draw->draw_buffer[z][z2] = \
				get_rgba(master->parser->grafics->fc[0], \
				master->parser->grafics->fc[1], \
				master->parser->grafics->fc[2], 255);
			z2++;
		}
		z++;
	}
}
