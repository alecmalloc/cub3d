#include "cubed.h"

int	extract_npath(char *src, char *dst)
{
	if (dst)
		return(DNP_ERR);
	while(*src != ' ')
		src++;
	skip_spaces(src);
	dst = ft_strdup((const char*)src);
	if (!dst)
		return(MALL_ERR);
	if (open(dst, O_RDONLY) == -1)
		return(NPU_ERR);
	return(0);
}

int	extract_spath(char *src, char *dst)
{
	if (dst)
		return(DSP_ERR);
	while(*src != ' ')
		src++;
	skip_spaces(src);
	dst = ft_strdup(src);
	if (!dst)
		return(MALL_ERR);
	if (open(dst, O_RDONLY) == -1)
		return(SPU_ERR);
	return(0);
}

int	extract_wpath(char *src, char *dst)
{
	if (dst)
		return(DWP_ERR);
	while(*src != ' ')
		src++;
	skip_spaces(src);
	dst = ft_strdup(src);
	if (!dst)
		return(MALL_ERR);
	if (open(dst, O_RDONLY) == -1)
		return(WPU_ERR);
	return(0);
}

int	extract_epath(char *src, char *dst)
{
	if (dst)
		return(DEP_ERR);
	while(*src != ' ')
		src++;
	skip_spaces(src);
	dst = ft_strdup(src);
	if (!dst)
		return(MALL_ERR);
	if (open(dst, O_RDONLY) == -1)
		return(EPU_ERR);
	return(0);
}
