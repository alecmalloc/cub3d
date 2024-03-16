#ifndef PARSER_H
# define PARSER_H

//store textures and colours

typedef struct	s_graf{
	char	*ntex;
	char	*stex;
	char	*etex;
	char	*wtex;
	int	fc[3];
	int	sc[3];
}	t_graf;

typedef struct	smap{
	;
}	t_map;

typedef struct	s_parser{
	int	fd;
	struct s_graf	*grafics;
	struct s_map	*map;
}	t_parser;

int	extract_data(t_parser *parser);
void	skip_spaces(char *tmp);
void	init_tex_col(t_graf *grafics);
int	extrac_npath(char *src, char *dst);
int	extrac_spath(char *src, char *dst);
int	extrac_wpath(char *src, char *dst);
int	extrac_epath(char *src, char *dst);
int	get_frgb(char *src, int arr[]);
int	get_srgb(char *src, int arr[]);
#endif
