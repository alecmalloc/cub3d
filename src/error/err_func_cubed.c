#include "cubed.h"

void	print_single(int err)
{
	if (err == MALL_ERR)
		printf("Error\nMemory allocation failed\n");
	else if (err == WRS_ERR)
		printf("Error\nWrong Suffix on .cub file\n");
	else if (err == OPF_ERR)
		printf("Error\nCould not access .cub file\n");
	else if (err == WRL_ERR)
		printf("Error\nFaulty Line in .cub file\n");
	else if (err == WRA_ERR)
		printf("Error\nOne Argument. Path to .cub\n");
	else if (err == MLX_INIT_ERR)
		printf("Error\nMLX init failed\n");
	else if (err == MLX_IMG_ERR)
		printf("Error\nMLX image failed\n");
}

void	print_doublep(int err)
{
	int		direction;
	char	*tmp[] = DIRECTIONS;

	direction = err % 100;
	printf("Error\nDouble assign of %s Path\n", tmp[direction]);
}

void	print_unaccesp(int err)
{
	int		direction;
	char	*tmp[] = DIRECTIONS;

	direction = err % 110;
	printf("Error\n%s Path not accessable\n", tmp[direction]);
}

void	print_missingp(int err)
{
	int		direction;
	char	*tmp[] = DIRECTIONS;

	direction = err % 120;
	printf("Error\n%s Path missing\n", tmp[direction]);
}

void	print_wrongp(int err)
{
	int		direction;
	char	*tmp[] = DIRECTIONS;

	direction = err % 130;
	printf("Error\n%s Path not in right format\n", tmp[direction]);
}
