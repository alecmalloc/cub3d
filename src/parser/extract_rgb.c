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

static int	extract_arr_f(char *src, int *arr[])
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

static int	extract_arr_s(char *src, int *arr[])
{
	int	z;

	z = 0;
	while (*src && ft_isdigit(*src))
	{
		(*arr)[z] = extract_nbr(src);
		if ((*arr)[z] == -1)
			return (WSN_ERR);
		z++;
		while (ft_isdigit(*src))
			src++;
		if (*src == ',')
			src++;
	}
	if (z != 3)
		return (MSN_ERR);
	while (*src && *src == ' ')
		src++;
	if (*src && *src != '\n')
		return (WFS_ERR);
	return (0);
}

int	get_frgb(char *src, int arr[])
{
	if (arr[0] != -1)
		return (DFN_ERR);
	while (*src && *src != ' ')
		src++;
	if (!*src)
		return (MFN_ERR);
	skip_spaces(&src);
	return (extract_arr_f(src, &arr));
}

int	get_srgb(char *src, int arr[])
{
	if (arr[0] != -1)
		return (DSN_ERR);
	while (*src && *src != ' ')
		src++;
	if (!*src)
		return (MSN_ERR);
	skip_spaces(&src);
	return (extract_arr_s(src, &arr));
}
