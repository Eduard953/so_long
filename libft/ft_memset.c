/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 16:22:52 by ebeiline          #+#    #+#             */
/*   Updated: 2021/06/07 16:10:47 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t n)
{
	unsigned char	*pointer;

	if (!src)
		return (NULL);
	pointer = (unsigned char *) src;
	while (n)
	{
		*(pointer) = (unsigned char) c;
		n--;
		pointer++;
	}
	return (src);
}
