#ifndef PARSER_H
# define PARSER_H

/* struct holdes variables given in .cub file
 * ntex = north texture
 * stex = south texture
 * ...
 * fc = floor colour
 * sc = seling colour */


typedef struct	stex_col{
	char	*ntex;
	char	*stex;
	char	*wtex;
	char	*etex;
	int	fc[3];
	int	sc[3];
}	ttex_col;

#endif
