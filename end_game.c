/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:02:25 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/03 19:35:36 by ebeiline         ###   ########.fr       */
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
	write(1, "W!: COngrAtUlAtIOns", 20);
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
