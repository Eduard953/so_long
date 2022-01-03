/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:05:10 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/03 15:27:52 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_floor(t_vars vars, int i, int j)
{
	vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./img/floor.xpm",
				&vars.img.size.x, &vars.img.size.y);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 64 * i, 64 * j);
	mlx_destroy_image(vars.mlx, vars.img.img);
}

void	choose_tile(t_vars vars, int i, int j)
{
	if (vars.map.mtx[i][j] == '1')
		vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./img/wall.xpm",
				&vars.img.size.x, &vars.img.size.y);
	else if (vars.map.mtx[i][j] == '0')
		vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./img/floor.xpm",
				&vars.img.size.x, &vars.img.size.y);
	else if (vars.map.mtx[i][j] == 'E')
		vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./img/exit.xpm",
				&vars.img.size.x, &vars.img.size.y);
	else if (vars.map.mtx[i][j] == 'P')
	{
		load_floor(vars, i, j);
		vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./img/player.xpm",
				&vars.img.size.x, &vars.img.size.y);
	}
	else if (vars.map.mtx[i][j] == 'C')
	{
		load_floor(vars, i, j);
		vars.img.img = mlx_xpm_file_to_image(vars.mlx, "./img/collectible.xpm",
				&vars.img.size.x, &vars.img.size.y);
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 64 * i, 64 * j);
	mlx_destroy_image(vars.mlx, vars.img.img);
}

void	loadmap(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.map.size.y)
	{
		j = 0;
		while (j < vars.map.size.x)
		{
			choose_tile(vars, i, j);
			j++;
		}
		i++;
	}
}
