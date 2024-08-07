/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cub.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <mbartsch@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:05:45 by mbartsch          #+#    #+#             */
/*   Updated: 2024/07/19 11:24:02 by aeastman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CUB_H
# define GAME_CUB_H

# define MOVESPEED 0.1
# define ROTSPEED 0.05

struct	s_cubed;

typedef struct s_game
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		l;
	int		r;
	int		space;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	char	**map;
	double	pos[2];

}	t_game;

int		init_game(t_game **game);
void	free_game(t_game **game);

int		check_mouse(struct s_cubed *master);
int		check_keys_move(struct s_cubed *master);
int		check_keys_view(struct s_cubed *master);
void	check_door(mlx_key_data_t key, void *tmp);

int		move(int rot, struct s_cubed *master);
int		rotate(int dir, struct s_cubed *master);
int		handle_door(struct s_cubed *master);
void	exit_game(void *master);
void	set_mlx(struct s_cubed *master);
int		make_image(struct s_cubed *master);

#endif
