/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:02:25 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/08 14:57:49 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_func(char *str)
{
	printf("\e[31m\e[1mError\n%s \e[0m \n", str);
	exit (EXIT_FAILURE);
}

int	end_game(t_vars *vars)
{
	int	i;

	i = 0;
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	if (vars->game.c_enemy)
		free(vars->e);
	while (i < vars->map.size.y)
	{
		free(vars->map.mtx[i]);
		i++;
	}
	free(vars->map.mtx);
	return (0);
}

void	win_game(t_vars *vars)
{
	vars->game.c_steps++;
	write(1, "W!: COngrAtUlAtIOns: Score ", 27);
	write(1, ft_itoa(vars->game.c_steps),
		ft_strlen(ft_itoa(vars->game.c_steps)));
	end_game(vars);
	exit(EXIT_SUCCESS);
}

void	loose_game(t_vars *vars)
{
	write(1, "L!: You got eaten", 18);
	end_game(vars);
	exit(EXIT_SUCCESS);
}

int	close_game(t_vars *vars)
{
	write(1, "Game aborted", 13);
	end_game(vars);
	exit(EXIT_SUCCESS);
	return (0);
}
