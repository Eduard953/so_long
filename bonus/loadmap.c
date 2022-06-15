/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loadmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:05:10 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/12 14:20:16 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_score(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->game.c_steps);
	mlx_string_put(vars->mlx, vars->win, (vars->game.pos.x * 64) + 5,
		(vars->game.pos.y * 64) + 10, 0xFFFFFF, str);
	free(str);
}

void	load_floor(t_vars *vars)
{
	if (vars->game.c_loop < 50)
		vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./img/floor.xpm",
				&vars->img.size.x, &vars->img.size.y);
	else
		vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./img/floor2.xpm",
				&vars->img.size.x, &vars->img.size.y);
}

void	load_enemy(t_vars *vars, int i, int j)
{
	load_floor(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img.img, 64 * j, 64 * i);
	mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->game.c_emove == 1)
		vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./img/enemy1.xpm",
				&vars->img.size.x, &vars->img.size.y);
	else
		vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./img/enemy2.xpm",
				&vars->img.size.x, &vars->img.size.y);
}

void	choose_tile(t_vars *vars, int i, int j)
{
	if (vars->map.mtx[i][j] == '1')
		vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./img/wall.xpm",
				&vars->img.size.x, &vars->img.size.y);
	else if (vars->map.mtx[i][j] == '0')
		load_floor(vars);
	else if (vars->map.mtx[i][j] == 'E')
		vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./img/exit.xpm",
				&vars->img.size.x, &vars->img.size.y);
	else if (vars->map.mtx[i][j] == 'P')
		vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./img/player.xpm",
				&vars->img.size.x, &vars->img.size.y);
	else if (vars->map.mtx[i][j] == 'W')
		load_enemy(vars, i, j);
	else if (vars->map.mtx[i][j] == 'C')
	{
		load_floor(vars);
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->img.img, 64 * j, 64 * i);
		mlx_destroy_image(vars->mlx, vars->img.img);
		vars->img.img = mlx_xpm_file_to_image(vars->mlx, "./img/collec.xpm",
				&vars->img.size.x, &vars->img.size.y);
	}
}

int	loadmap(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.size.y)
	{
		j = 0;
		while (j < vars->map.size.x)
		{
			choose_tile(vars, i, j);
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->img.img, 64 * j, 64 * i);
			mlx_destroy_image(vars->mlx, vars->img.img);
			j++;
		}
		i++;
	}
	if (vars->game.c_loop % 25 == 0)
		move_enemy(vars);
	load_score(vars);
	if (vars->game.c_loop == 100)
		vars->game.c_loop = 0;
	vars->game.c_loop++;
	return (0);
}
