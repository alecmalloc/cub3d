/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_rgb_cubed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:04:19 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 10:04:20 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	extract_nbr(char *src)
{
	int	z;
	int	i;
	int	ret;

	z = 0;
	while (ft_isdigit(src[z]) && z < 5)
		z++;
	if ((z < 1 || z > 3) && src[z] != ',')
		return (-1);
	i = 0;
	ret = 0;
	while (i < z)
		ret = ret * 10 + (src[i++] - '0');
	if (ret < 0 || ret > 255)
		return (-1);
	return (ret);
}

static int	extract_arr_f(char *src, int (*arr)[])
{
	int	z;

	z = 0;
	while (*src && ft_isdigit(*src))
	{
		(*arr)[z] = extract_nbr(src);
		if ((*arr)[z] == -1)
			return (WFN_ERR);
		z++;
		while (ft_isdigit(*src))
			src++;
		if (*src == ',')
			src++;
	}
	if (z != 3)
		return (MFN_ERR);
	while (*src && *src == ' ')
		src++;
	if (*src && *src != '\n')
		return (WFF_ERR);
	return (0);
}

static int	extract_arr_s(char *src, int (*arr)[])
{
	int	z;

	z = 0;
	while (*src && ft_isdigit(*src))
	{
		(*arr)[z] = extract_nbr(src);
		if ((*arr)[z] == -1)
			return (WCN_ERR);
		z++;
		while (ft_isdigit(*src))
			src++;
		if (*src == ',')
			src++;
	}
	if (z != 3)
		return (MCN_ERR);
	while (*src && *src == ' ')
		src++;
	if (*src && *src != '\n')
		return (WFC_ERR);
	return (0);
}

int	get_frgb(char *src, int (*arr)[])
{
	if ((*arr)[0] != -1)
		return (DFN_ERR);
	while (*src && *src != ' ')
		src++;
	if (!*src)
		return (MFN_ERR);
	skip_spaces(&src);
	return (extract_arr_f(src, arr));
}

int	get_srgb(char *src, int (*arr)[])
{
	if ((*arr)[0] != -1)
		return (DCN_ERR);
	while (*src && *src != ' ')
		src++;
	if (!*src)
		return (MCN_ERR);
	skip_spaces(&src);
	return (extract_arr_s(src, arr));
}
