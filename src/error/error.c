#include "cubed.h"

int	print_error(int err_code, t_cubed **cubed)
{
	if (err_code < 100)
		print_single(err_code);
	else if (err_code < 110)
		print_doublep(err_code);
	else if (err_code < 120)
		print_unaccesp(err_code);
	else if (err_code < 130)
		print_missingp(err_code);
	else if (err_code < 140)
		print_wrongp(err_code);
	else if (err_code < 150)
		print_missingn(err_code);
	else if (err_code < 160)
		print_doublen(err_code);
	else if (err_code < 170)
		print_wrongn(err_code);
	else if (err_code < 180)
		print_wrongfn(err_code);
	free_all(cubed);
	return (EXIT_FAILURE);
}
