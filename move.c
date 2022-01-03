/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:52:11 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/03 15:39:49 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_vars *vars)
{
	if (vars->map.mtx[vars->img.pos.y][vars->img.pos.x - 1] == 'E'
		&& (vars->game.c_collec == 0))
		win_game(vars);
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = '0';
	vars->img.pos.x -= 1;
	if (vars->map.mtx[vars->img.pos.y][vars->img.pos.x] == 'C')
		vars->game.c_collec -= 1;
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = 'P';
	vars->game.c_steps++;
}

void	right(t_vars *vars)
{
	if (vars->map.mtx[vars->img.pos.y][vars->img.pos.x + 1] == 'E'
		&& (vars->game.c_collec == 0))
		win_game(vars);
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = '0';
	vars->img.pos.x += 1;
	if (vars->map.mtx[vars->img.pos.y][vars->img.pos.x] == 'C')
		vars->game.c_collec -= 1;
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = 'P';
	vars->game.c_steps++;
}

void	down(t_vars *vars)
{
	if (vars->map.mtx[vars->img.pos.y + 1][vars->img.pos.x] == 'E'
		&& (vars->game.c_collec == 0))
		win_game(vars);
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = '0';
	vars->img.pos.y += 1;
	if (vars->map.mtx[vars->img.pos.y][vars->img.pos.x] == 'C')
		vars->game.c_collec -= 1;
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = 'P';
	vars->game.c_steps++;
}

void	up(t_vars *vars)
{
	if (vars->map.mtx[vars->img.pos.y - 1][vars->img.pos.x] == 'E'
		&& (vars->game.c_collec == 0))
		win_game(vars);
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = '0';
	vars->img.pos.y -= 1;
	if (vars->map.mtx[vars->img.pos.y][vars->img.pos.x] == 'C')
		vars->game.c_collec -= 1;
	vars->map.mtx[vars->img.pos.y][vars->img.pos.x] = 'P';
	vars->game.c_steps++;
}

int	move_player(int key, t_vars *vars)
{
	write(1, "1", 1);
	if (key == 53)
		close_game(vars);
	if ((key == 0)
		&& (vars->map.mtx[vars->img.pos.y][vars->img.pos.x - 1] != '1'))
		left(vars);
	if ((key == 2)
		&& (vars->map.mtx[vars->img.pos.y][vars->img.pos.x + 1] != '1'))
		right(vars);
	if ((key == 1)
		&& (vars->map.mtx[vars->img.pos.y + 1][vars->img.pos.x] != '1'))
		down(vars);
	if ((key == 13)
		&& (vars->map.mtx[vars->img.pos.y - 1][vars->img.pos.x] != '1'))
		{
			write(1, "2", 1);
			up(vars);
		}
	return (0);
}