/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebeiline <ebeiline@42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:08:55 by ebeiline          #+#    #+#             */
/*   Updated: 2021/11/17 13:58:44 by ebeiline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *src, size_t n)
{
	unsigned char	*pointer;

	pointer = (unsigned char *) src;
	while (n)
	{
		*(pointer) = '\0';
		n--;
		pointer++;
	}
}
