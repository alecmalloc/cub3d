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

static void	print_parser(t_parser *parser)
{
	printf("%s\n", parser->grafics->ntex);	
	printf("%s\n", parser->grafics->wtex);
	printf("%s\n", parser->grafics->etex);	
	printf("%s\n", parser->grafics->stex);	
	printf("%s\n", parser->grafics->ntex);	
	printf("%d\n", parser->grafics->fc[0]);	
	printf("%d\n", parser->grafics->fc[1]);	
	printf("%d\n", parser->grafics->fc[2]);	
	printf("%d\n", parser->grafics->sc[0]);	
	printf("%d\n", parser->grafics->sc[1]);	
	printf("%d\n", parser->grafics->sc[2]);	
}

int	parser(char *file, t_cubed *master){
	int	ret;

	if ((ret = check_suffix(file)))
		return(ret);
	if ((ret = open_file( file, master)))
		return(ret);
	if((ret = extract_data(master->parser)))
		return(ret);
	print_parser(master->parser);
	//close fd
	return(0);
}
