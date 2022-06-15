/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:52:11 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/03 19:27:54 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left(t_vars *vars)
{
	char	*str;

	if (vars->map.mtx[vars->game.pos.y][vars->game.pos.x - 1] == 'E'
		&& (vars->game.c_collec == 0))
		win_game(vars);
	else if (vars->map.mtx[vars->game.pos.y][vars->game.pos.x - 1] == 'E')
		return ;
	vars->map.mtx[vars->game.pos.y][vars->game.pos.x] = '0';
	vars->game.pos.x -= 1;
	if (vars->map.mtx[vars->game.pos.y][vars->game.pos.x] == 'C')
		vars->game.c_collec -= 1;
	vars->map.mtx[vars->game.pos.y][vars->game.pos.x] = 'P';
	vars->game.c_steps++;
	str = ft_itoa(vars->game.c_steps);
	write(1, "Score: ", 8);
	write(1, str, ft_strlen(str));
	write(1, "\n", 2);
	free(str);
	loadmap(*vars);
}

void	right(t_vars *vars)
{
	char	*str;

	if (vars->map.mtx[vars->game.pos.y][vars->game.pos.x + 1] == 'E'
		&& (vars->game.c_collec == 0))
		win_game(vars);
	else if (vars->map.mtx[vars->game.pos.y][vars->game.pos.x + 1] == 'E')
		return ;
	vars->map.mtx[vars->game.pos.y][vars->game.pos.x] = '0';
	vars->game.pos.x += 1;
	if (vars->map.mtx[vars->game.pos.y][vars->game.pos.x] == 'C')
		vars->game.c_collec -= 1;
	vars->map.mtx[vars->game.pos.y][vars->game.pos.x] = 'P';
	vars->game.c_steps++;
	str = ft_itoa(vars->game.c_steps);
	write(1, "Score: ", 8);
	write(1, str, ft_strlen(str));
	write(1, "\n", 2);
	free(str);
	loadmap(*vars);
}

void	down(t_vars *vars)
{
	char	*str;

	if (vars->map.mtx[vars->game.pos.y + 1][vars->game.pos.x] == 'E'
		&& (vars->game.c_collec == 0))
		win_game(vars);
	else if (vars->map.mtx[vars->game.pos.y + 1][vars->game.pos.x] == 'E')
		return ;
	vars->map.mtx[vars->game.pos.y][vars->game.pos.x] = '0';
	vars->game.pos.y += 1;
	if (vars->map.mtx[vars->game.pos.y][vars->game.pos.x] == 'C')
		vars->game.c_collec -= 1;
	vars->map.mtx[vars->game.pos.y][vars->game.pos.x] = 'P';
	vars->game.c_steps++;
	str = ft_itoa(vars->game.c_steps);
	write(1, "Score: ", 8);
	write(1, str, ft_strlen(str));
	write(1, "\n", 2);
	free(str);
	loadmap(*vars);
}

void	up(t_vars *vars)
{
	char	*str;

	if (vars->map.mtx[vars->game.pos.y - 1][vars->game.pos.x] == 'E'
		&& (vars->game.c_collec == 0))
		win_game(vars);
	else if (vars->map.mtx[vars->game.pos.y - 1][vars->game.pos.x] == 'E')
		return ;
	vars->map.mtx[vars->game.pos.y][vars->game.pos.x] = '0';
	vars->game.pos.y -= 1;
	if (vars->map.mtx[vars->game.pos.y][vars->game.pos.x] == 'C')
		vars->game.c_collec -= 1;
	vars->map.mtx[vars->game.pos.y][vars->game.pos.x] = 'P';
	vars->game.c_steps++;
	str = ft_itoa(vars->game.c_steps);
	write(1, "Score: ", 8);
	write(1, str, ft_strlen(str));
	write(1, "\n", 2);
	free(str);
	loadmap(*vars);
}

int	move_player(int key, t_vars *vars)
{
	if (key == 53)
		close_game(vars);
	if ((key == 0)
		&& (vars->map.mtx[vars->game.pos.y][vars->game.pos.x - 1] != '1'))
		left(vars);
	if ((key == 2)
		&& (vars->map.mtx[vars->game.pos.y][vars->game.pos.x + 1] != '1'))
		right(vars);
	if ((key == 1)
		&& (vars->map.mtx[vars->game.pos.y + 1][vars->game.pos.x] != '1'))
		down(vars);
	if ((key == 13)
		&& (vars->map.mtx[vars->game.pos.y - 1][vars->game.pos.x] != '1'))
		up(vars);
	return (0);
}
