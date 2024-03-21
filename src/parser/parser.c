#include "cubed.h"

static int	check_suffix(char *file)
{
	char	*tmp;

	tmp = ft_strrchr(file, '.');
	if (tmp && tmp[0] == '.' && tmp[1] == 'c' && tmp[2] == 'u' && tmp[3] == 'b'\
		&& tmp[4] == '\0')
		return (0);
	return (WRS_ERR);
}

static int	open_file(char *file, t_cubed *master)
{
	master->parser->fd = open(file, O_RDONLY);
	if (master->parser->fd == -1)
		return (OPF_ERR);
	return (0);
}

static void	print_parser(t_parser *parser)
{
	printf("%s\n", parser->grafics->ntex);
	printf("%s\n", parser->grafics->wtex);
	printf("%s\n", parser->grafics->etex);
	printf("%s\n", parser->grafics->stex);
	printf("%d ", parser->grafics->fc[0]);
	printf("%d ", parser->grafics->fc[1]);
	printf("%d\n", parser->grafics->fc[2]);
	printf("%d ", parser->grafics->sc[0]);
	printf("%d ", parser->grafics->sc[1]);
	printf("%d\n", parser->grafics->sc[2]);
	for (int i = 0; parser->map->map[i]; i++)
		printf("%s\n", parser->map->map[i]);
	printf("%d\n", parser->map->player_dir);
}


int	parser(char *file, t_cubed *master)
{
	int	ret;

	ret = check_suffix(file);
	if (ret)
		return (ret);
	ret = open_file(file, master);
	if (ret)
		return (ret);
	ret = extract_data(master->parser);
	if (ret)
		return (ret);
	ret = extract_map(master->parser);
	print_parser(master->parser);
	return (ret);
}
