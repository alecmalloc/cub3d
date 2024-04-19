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
	printf("Error\nDouble assign of %s Path\n", print_direction(err % 100));
}

void	print_unaccesp(int err)
{
	printf("Error\n%s Path not accessable\n", print_direction(err % 110));
}

void	print_missingp(int err)
{
	printf("Error\n%s Path missing\n", print_direction(err % 120));
}

void	print_wrongp(int err)
{
	printf("Error\n%s Path not in right format\n", print_direction(err % 130));
}
