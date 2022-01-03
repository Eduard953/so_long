/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 17:07:15 by ebeiline          #+#    #+#             */
/*   Updated: 2022/01/02 16:20:55 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnewl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_out(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_get_res(char *res)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!res)
		return (0);
	while (res[i] && res[i] != '\n')
		i++;
	if (!res[i])
	{
		free(res);
		return (0);
	}
	dest = malloc(sizeof(char) * ((ft_strlen(res) - i) + 1));
	if (!dest)
		return (0);
	i++;
	while (res[i])
		dest[j++] = res[i++];
	dest[j] = '\0';
	free(res);
	return (dest);
}

int	ft_gnl(int fd, char **line)
{
	char			*buff;
	static char		*res;
	int				count_b;

	count_b = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	while (!ft_isnewl(res) && count_b != 0)
	{
		count_b = read(fd, buff, BUFFER_SIZE);
		if (count_b == -1)
		{
			free(buff);
			return (-1);
		}
		buff[count_b] = '\0';
		res = ft_strjoin(res, buff);
	}
	free(buff);
	*line = ft_get_out(res);
	res = ft_get_res(res);
	return (count_b != 0);
}
