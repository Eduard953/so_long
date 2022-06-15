/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_e.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 19:15:20 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/08 14:33:00 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	left_e(t_vars *vars, int i)
{
	if (vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x - 1] == 'P')
		loose_game(vars);
	if (vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x - 1] == 'E')
		return ;
	if (vars->map.mtx[vars->e[i].pos.y - 1][vars->e[i].pos.x] == 'C')
		return ;
	vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x] = '0';
	vars->e[i].pos.x -= 1;
	vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x] = 'W';
}

void	right_e(t_vars *vars, int i)
{
	if (vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x + 1] == 'P')
		loose_game(vars);
	if (vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x + 1] == 'E')
		return ;
	if (vars->map.mtx[vars->e[i].pos.y - 1][vars->e[i].pos.x] == 'C')
		return ;
	vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x] = '0';
	vars->e[i].pos.x += 1;
	vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x] = 'W';
}

void	down_e(t_vars *vars, int i)
{
	if (vars->map.mtx[vars->e[i].pos.y + 1][vars->e[i].pos.x] == 'P')
		loose_game(vars);
	if (vars->map.mtx[vars->e[i].pos.y + 1][vars->e[i].pos.x] == 'E')
		return ;
	if (vars->map.mtx[vars->e[i].pos.y + 1][vars->e[i].pos.x] == 'C')
		return ;
	vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x] = '0';
	vars->e[i].pos.y += 1;
	vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x] = 'W';
}

void	up_e(t_vars *vars, int i)
{
	if (vars->map.mtx[vars->e[i].pos.y - 1][vars->e[i].pos.x] == 'P')
		loose_game(vars);
	if (vars->map.mtx[vars->e[i].pos.y - 1][vars->e[i].pos.x] == 'E')
		return ;
	if (vars->map.mtx[vars->e[i].pos.y - 1][vars->e[i].pos.x] == 'C')
		return ;
	vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x] = '0';
	vars->e[i].pos.y -= 1;
	vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x] = 'W';
}

int	move_enemy(t_vars *vars)
{
	int	i;
	int	rand;

	i = 0;
	while (i < vars->game.c_enemy)
	{
		rand = ft_random(vars->game.c_rand) % 4;
		if ((rand == 0)
			&& (vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x - 1] != '1'))
			left_e(vars, i);
		else if ((rand == 1)
			&& (vars->map.mtx[vars->e[i].pos.y][vars->e[i].pos.x + 1] != '1'))
			right_e(vars, i);
		else if ((rand == 2)
			&& (vars->map.mtx[vars->e[i].pos.y + 1][vars->e[i].pos.x] != '1'))
			down_e(vars, i);
		else if ((rand == 3)
			&& (vars->map.mtx[vars->e[i].pos.y - 1][vars->e[i].pos.x] != '1'))
			up_e(vars, i);
		i++;
		if (vars->game.c_rand++ == 1500)
			vars->game.c_rand = 0;
	}
	vars->game.c_emove *= -1;
	return (0);
}
