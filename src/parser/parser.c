#include "cubed.h"

static int	check_suffix(char *file){
	char	*tmp;
	int	z;

	z = 0;
	tmp = ft_strrchr(file, '.');
	if (tmp && tmp[0] == '.' && tmp[1] == 'c' && tmp[2] == 'u' && tmp[3] == 'b')
		return (WRS_ERR);
	return (0);
		
}

static int	open_file(char *file, t_cubed *master)
{
	master->parser->fd = open(file, O_RDONLY);
	if( master->parser->fd == -1 )
		return(OPF_ERR);
	return(1);
}

int	parser(char *file, t_cubed *master){
	int	ret;
	init_grafics(master->parser->grafics);
	if ((ret = check_suffix(file)))
		return(ret);
	if ((ret = open_file( file, master)))
		return(ret);
	if((ret = extract_data(master->parser)))
		return(ret);
	return(0);
}
