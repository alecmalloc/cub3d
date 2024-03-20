#include "cubed.h"

static int	fix_len(char *src)
{
	int		z;
	char	*tmp;

	tmp = src;
	z = 0;
	while (tmp[z] != '\0' && tmp[z] != '\n' && tmp[z] != ' ')
		z++;
	if (tmp[z] == '\0')
		return (0);
	tmp[z++] = '\0';
	while (tmp[z])
	{
		if (tmp[z] != ' ' && tmp[z] != '\n' )
			return (1);
		z++;
	}
	return (0);
}

int	extract_npath(char *src, char **dst)
{
	int	tmp;

	if (*dst)
		return (DNP_ERR);
	while (*src != ' ')
		src++;
	skip_spaces(&src);
	if (!*src)
		return (NPM_ERR);
	if (fix_len(src))
		return (NPW_ERR);
	*dst = ft_strdup(src);
	if (!*dst)
		return (MALL_ERR);
	tmp = open(*dst, O_RDONLY);
	if (tmp == -1)
		return (NPU_ERR);
	close(tmp);
	return (0);
}

int	extract_spath(char *src, char **dst)
{
	int	tmp;

	if (*dst)
		return (DSP_ERR);
	while (*src != ' ')
		src++;
	skip_spaces(&src);
	if (!*src)
		return (SPM_ERR);
	if (fix_len(src))
		return (SPW_ERR);
	*dst = ft_strdup(src);
	if (!*dst)
		return (MALL_ERR);
	tmp = open(*dst, O_RDONLY);
	if (tmp == -1)
		return (SPU_ERR);
	close(tmp);
	return (0);
}

int	extract_wpath(char *src, char **dst)
{
	int	tmp;

	if (*dst)
		return (DWP_ERR);
	while (*src != ' ')
		src++;
	skip_spaces(&src);
	if (!*src)
		return (WPM_ERR);
	if (fix_len(src))
		return (WPW_ERR);
	*dst = ft_strdup(src);
	if (!*dst)
		return (MALL_ERR);
	tmp = open(*dst, O_RDONLY);
	if (tmp == -1)
		return (WPU_ERR);
	close(tmp);
	return (0);
}

int	extract_epath(char *src, char **dst)
{
	int	tmp;

	if (*dst)
		return (DEP_ERR);
	while (*src != ' ')
		src++;
	skip_spaces(&src);
	if (!*src)
		return (EPM_ERR);
	if (fix_len(src))
		return (EPW_ERR);
	*dst = ft_strdup(src);
	if (!*dst)
		return (MALL_ERR);
	tmp = open(*dst, O_RDONLY);
	if (tmp == -1)
		return (EPU_ERR);
	close(tmp);
	return (0);
}
