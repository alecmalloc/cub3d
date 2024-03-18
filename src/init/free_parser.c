#include "cubed.h"

static void	free_grafics(t_graf **grafics)
{
	if ((*grafics)->ntex)
		free((*grafics)->ntex);
	if ((*grafics)->etex)
		free((*grafics)->etex);
	if ((*grafics)->stex)
		free((*grafics)->stex);
	if ((*grafics)->wtex)
		free((*grafics)->wtex);
	free(*grafics);
}

static void	free_map(t_map **map)
{
	free(*map);
}

void	free_parser(t_parser **parser)
{
	if ((*parser)->fd != -1)
		close((*parser)->fd);
	if ((*parser)->grafics)
		free_grafics(&(*parser)->grafics);
	if ((*parser)->map)
		free_map(&(*parser)->map);
	free(*parser);
}
