/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:26:08 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/02 15:55:19 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_coord	size;
	t_coord	pos;
}				t_img;

typedef struct s_game
{
	int			c_collec;
	int			c_steps;
	int			c_player;
	int			c_exits;
}	t_game;

typedef struct s_map
{
	char		**mtx;
	t_coord		size;
}	t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_game		game;
	t_map		map;
	t_img		img;
}	t_vars;

int		move_player(int key, t_vars *vars);
void	checkmap(t_vars vars);
void	loadmap(t_vars vars);
void	win_game(t_vars *vars);
int		close_game(t_vars *vars);

#endif
