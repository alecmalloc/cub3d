/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data_cubed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:04:31 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:04:32 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	skip_spaces(char **line)
{
	while (**line && **line == ' ')
		(*line)++;
}

static int	extract_data_line(char *tmp, t_graf *grafics)
{
	if (*tmp == '\n')
		return (0);
	skip_spaces(&tmp);
	if (*tmp == 'N' && *(tmp + 1) == 'O' && *(tmp + 2) == ' ')
		return (extract_npath(tmp, &grafics->ntex));
	else if (*tmp == 'S' && *(tmp + 1) == 'O' && *(tmp + 2) == ' ')
		return (extract_spath(tmp, &grafics->stex));
	else if (*tmp == 'W' && *(tmp + 1) == 'E' && *(tmp + 2) == ' ')
		return (extract_wpath(tmp, &grafics->wtex));
	else if (*tmp == 'E' && *(tmp + 1) == 'A' && *(tmp + 2) == ' ')
		return (extract_epath(tmp, &grafics->etex));
	else if (*tmp == 'F' && *(tmp + 1) == ' ')
		return (get_frgb(tmp, &grafics->fc));
	else if (*tmp == 'C' && *(tmp + 1) == ' ')
		return (get_srgb(tmp, &grafics->sc));
	return (WRL_ERR);
}

static int	data_extracted(t_graf *grafics)
{
	if (grafics->ntex && grafics->stex && grafics->etex && grafics->wtex \
		&& grafics->fc[0] != -1 && grafics->sc[0] != -1)
		return (1);
	return (0);
}

int	extract_data(t_parser *parser)
{
	char	*tmp;
	int		ret;

	tmp = get_next_line(parser->fd);
	while (tmp)
	{
		ret = extract_data_line(tmp, parser->grafics);
		if (ret != 0)
			return (free(tmp), ret);
		if (data_extracted(parser->grafics))
			break ;
		free(tmp);
		tmp = get_next_line(parser->fd);
	}
	if (tmp)
		free(tmp);
	return (0);
}
