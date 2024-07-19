/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cubed.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:04:27 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:04:29 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	check_suffix(char *file, char *ending)
{
	char	*tmp;

	tmp = ft_strrchr(file, '.');
	if (!tmp)
		return (WRA_ERR);
	if (ft_memcmp((void *)tmp, (void *)ending, ft_strlen(ending)))
		return (WRS_ERR);
	return (0);
}

static int	open_file(char *file, t_cubed *master)
{
	master->parser->fd = open(file, O_RDONLY);
	if (master->parser->fd == -1)
		return (OPF_ERR);
	return (0);
}

// static void	print_parser(t_parser *parser)
// {
// 	printf("%s\n", parser->grafics->ntex);
// 	printf("%s\n", parser->grafics->wtex);
// 	printf("%s\n", parser->grafics->etex);
// 	printf("%s\n", parser->grafics->stex);
// 	printf("%d ", parser->grafics->fc[0]);
// 	printf("%d ", parser->grafics->fc[1]);
// 	printf("%d\n", parser->grafics->fc[2]);
// 	printf("%d ", parser->grafics->sc[0]);
// 	printf("%d ", parser->grafics->sc[1]);
// 	printf("%d\n", parser->grafics->sc[2]);
// 	for (int i = 0; parser->map->map[i]; i++)
// 		printf("%s\n", parser->map->map[i]);
// 	printf("%d\n", parser->map->player_dir);
// }

int	parser(char *file, t_cubed *master)
{
	int	ret;

	ret = check_suffix(file, FIL_END);
	if (ret)
		return (ret);
	ret = open_file(file, master);
	if (ret)
		return (ret);
	ret = extract_data(master->parser);
	if (ret)
		return (ret);
	ret = extract_map(master->parser);
	return (ret);
}
