/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 13:53:14 by ebeiline          #+#    #+#             */
/*   Updated: 2021/05/22 18:58:45 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tdest;
	char	*tsrc;

	tdest = (char *)dest;
	tsrc = (char *)src;
	if (n == 0 || dest == src)
		return (dest);
	if (tsrc < tdest)
	{
		while (n)
		{
			tdest[n - 1] = tsrc[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return ((void *)dest);
}
