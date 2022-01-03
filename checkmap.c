/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:20:59 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/02 17:48:09 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	checkrectangular(t_vars vars)
{
	int		line;

	line = 0;
	while (line < vars.map.size.y)
	{
		if (vars.map.size.x != (int)ft_strlen(vars.map.mtx[line]))
		{
			write(1, "error: map not retangular", 26);
			exit(-1);	
		}
		line++;
	}
}

void	checkwalls(t_vars vars)
{
	int	i;
	int j;

	i = 0;
	while(i < vars.map.size.y)
	{
		j = 0;
		if (i == 0 || i == (vars.map.size.y - 1))
		{
			while (vars.map.mtx[i][j])
			{
				if (vars.map.mtx[i][j] != '1')
				{
					write(1, "walls not in form", 18);
					exit(-1);
				}
				j++;
			}
		}
		if (vars.map.mtx[i][0] != '1'
			|| vars.map.mtx[i][vars.map.size.x - 1] != '1')
		{
			write(1, "walls not in form", 18);
			exit(-1);
		}
		i++;
	}
}

void	checkobjects(t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars.map.size.y)
	{
		j = 0;
		while (vars.map.mtx[i][j])
		{
			if (vars.map.mtx[i][j] == 'P')
			{
				vars.game.c_player++;
				vars.img.pos.x = j;
				vars.img.pos.y = i;	
			}
			else if (vars.map.mtx[i][j] == 'E')
				vars.game.c_exits++;
			else if (vars.map.mtx[i][j] == 'C')
				vars.game.c_collec++;
			else if (vars.map.mtx[i][j] != '0' 
				&& vars.map.mtx[i][j] != '1')
			{
				write(1, "wrong map input", 16);
				exit(-1);
			}
			j++;
		}
		i++;
	}
	if (vars.game.c_player != 1 || vars.game.c_collec < 1 
	|| vars.game.c_exits < 1)
	{
		write(1, "wrong map input", 16);
		exit(-1);
	}
}

void checkmap(t_vars vars)
{
	checkrectangular(vars);
	checkwalls(vars);
	checkobjects(vars);
}