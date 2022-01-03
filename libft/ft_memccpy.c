/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:12:45 by ebeiline          #+#    #+#             */
/*   Updated: 2021/06/07 16:10:18 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*tdest;
	char	*tsrc;
	size_t	i;

	i = 0;
	tdest = (char *)dest;
	tsrc = (char *)src;
	if (n == 0 || !dest || !src)
		return (NULL);
	while (i < n)
	{
		tdest[i] = tsrc[i];
		if (tdest[i] == c)
			return ((void *)&tdest[i + 1]);
		i++;
	}
	return (NULL);
}
