#include "cubed.h"

void	print_missingn(int err)
{
	int		direction;
	char	*tmp[] = BOTOP;

	direction = err % 140;
	printf("Error\n%s RGB number missing\n", tmp[direction]);
}

void	print_doublen(int err)
{
	int		direction;
	char	*tmp[] = BOTOP;

	direction = err % 150;
	printf("Error\n%s double assingment\n", tmp[direction]);
}

void	print_wrongn(int err)
{
	int		direction;
	char	*tmp[] = BOTOP;

	direction = err % 160;
	printf("Error\n%s RGB Number wrong\n", tmp[direction]);
}

void	print_wrongfn(int err)
{
	int		direction;
	char	*tmp[] = BOTOP;

	direction = err % 170;
	printf("Error\n%s RGB Number wrong format\n", tmp[direction]);
}
