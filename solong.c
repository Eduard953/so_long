/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:42:38 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/03 15:54:16 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	var_init(t_vars *vars)
{
	vars->win = NULL;
	vars->mlx = NULL;
	vars->img.img = NULL;
	vars->img.addr = NULL;
	vars->game.c_steps = 0;
	vars->map.size.x = 0;
	vars->map.size.y = 1;
	vars->game.c_collec = 0;
	vars->game.c_player = 0;
	vars->game.c_exits = 0;
}

void check_format(int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, "too few args", 13);
		exit(-1);
	}
	if (argc > 2)
	{
		write(1, "too many args", 14);
		exit(-1);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		write(1, "use .ber map", 13);
		exit(-1);
	}
}

void	get_coords(t_vars *vars, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "map not found", 14);
		exit(-1);
	}
	while (get_next_line(fd, &line))
	{
		vars->map.size.x = ft_strlen(line);
		vars->map.size.y++;
		free(line);
	}
	free(line);
	close(fd);
}

void get_map(t_vars *vars, char **argv)
{
	int		row;
	int		fd;

	row = 0;
	vars->map.mtx = malloc((vars->map.size.y + 1) * sizeof(char *));
	vars->map.mtx[vars->map.size.y] = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "map not found", 14);
		exit(-1);
	}
	while (get_next_line(fd, &vars->map.mtx[row]))
		row++;
	close(fd);
	checkmap(*vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	var_init(&vars);
	check_format(argc, argv);
	get_coords(&vars, argv);
	get_map(&vars, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1280, 800, "ebeiline so_long");
	loadmap(vars);
	mlx_hook(vars.win, 17, 1L << 0, close_game, &vars);
	mlx_hook(vars.win, 2, 1L << 0, move_player, &vars);
	mlx_loop(vars.mlx);
}
