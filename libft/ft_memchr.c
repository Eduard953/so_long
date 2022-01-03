/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:03:57 by ebeiline          #+#    #+#             */
/*   Updated: 2021/06/08 13:56:02 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*s;
	int				i;

	i = 0;
	s = (unsigned char *)src;
	while (n)
	{
		if (s[i] == (unsigned char)c)
			return (s + i);
		i++;
		n--;
	}
	return (NULL);
}
