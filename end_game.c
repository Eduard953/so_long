/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:02:25 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/03 15:58:02 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		printf("%d\n", vars->map.size.y);
	}
	printf("AAAA");
	write(1, "33333", 1);
	free(vars->map.mtx);
	printf("BBBB");
	write(1, "5444", 1);
	return (0);
}

void	win_game(t_vars *vars)
{
	write(1, "W!: COngrAtUlAtIOns", 20);
	end_game(vars);
}

int	close_game(t_vars *vars)
{
	write(1, "Game aborted", 13);
	end_game(vars);
	printf("works");
	return (0);
}