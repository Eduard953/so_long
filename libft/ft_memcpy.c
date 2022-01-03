/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:40:22 by ebeiline          #+#    #+#             */
/*   Updated: 2021/05/22 18:58:39 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tdest;
	char	*tsrc;
	size_t	i;

	i = 0;
	tdest = (char *)dest;
	tsrc = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	while (i < n)
	{
		tdest[i] = tsrc[i];
		i++;
	}
	return ((void *)dest);
}
