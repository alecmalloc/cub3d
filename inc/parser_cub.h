#ifndef PARSER_CUB_H
# define PARSER_CUB_H

//MapCharacter
# define MAP_CHR "0123NSWE "
# define IMP_CHR "0123NSWE"
# define PLR_CHR "NSWE"

//store textures and colours

typedef struct s_graf
{
	char	*ntex;
	char	*stex;
	char	*etex;
	char	*wtex;
	int		fc[3];
	int		sc[3];
}	t_graf;

typedef struct s_map
{
	int		x_len;
	int		y_len;
	int		player_pos[2];
	int		player_dir;
	char	*map_storage;
	char	**map;
}	t_map;

typedef struct s_parser
{
	int				fd;
	struct s_graf	*grafics;
	struct s_map	*map;
}	t_parser;

int		init_parser(t_parser **parser);
void	free_parser(t_parser **parser);

int		extract_data(t_parser *parser);
int		extract_npath(char *src, char **dst);
int		extract_spath(char *src, char **dst);
int		extract_wpath(char *src, char **dst);
int		extract_epath(char *src, char **dst);

int		extract_map(t_parser *parser);
void	get_map_size(t_map *map, int fd);
int		copy_map(t_map *map);
int		check_map(t_map *map);

int		get_frgb(char *src, int (*arr)[]);
int		get_srgb(char *src, int (*arr)[]);

void	skip_spaces(char **tmp);
#endif
