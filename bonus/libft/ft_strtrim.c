/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 12:55:37 by ebeiline          #+#    #+#             */
/*   Updated: 2021/06/08 13:23:10 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_s(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*dest;
	unsigned int	start;
	unsigned int	end;
	unsigned int	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_char_in_s(s1[start], set))
		start++;
	while ((end != start) && ft_char_in_s(s1[end - 1], set))
		end--;
	end = end - start;
	dest = (char *)malloc(sizeof(*s1) * (end + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < end)
	{
		dest[i] = s1[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
