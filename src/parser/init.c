#include "cubed.h"

void	init_grafics(t_graf *tmp)
{
	tmp->ntex = NULL;
	tmp->stex = NULL;
	tmp->etex = NULL;
	tmp->wtex = NULL;
	tmp->fc[0] = -1;
	tmp->fc[1] = -1;
	tmp->fc[2] = -1;
	tmp->sc[0] = -1;
	tmp->sc[1] = -1;
	tmp->sc[2] = -1;
}
